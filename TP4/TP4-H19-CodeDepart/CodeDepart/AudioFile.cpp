///////////////////////////////////////////////////////////
//  AudioFile.cpp
//  Implementation of the Class AudioFile
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include <stdexcept>

#include "AudioFile.h"
#include "ChunkIterator.h"

AudioFile::AudioFile(const std::string & fname)
	: AbsAudioFile(fname)
{
	size_t f_chunkSize = AbsAudioFile::defaultChunkSize;
	size_t f_numberChunks = 0;

	// Essayer d'ouvrir le fichier en lecture
	m_stream.open(fname, std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::ate);
	if (!m_stream.good())
	{
		// Nouveau fichier, on reouvre en ecriture
		m_stream.clear();
		m_stream.close();
		m_stream.open(fname, std::fstream::out | std::fstream::binary);

		// Initialiser l'entete avec la taille des Chunks
		m_stream.write(reinterpret_cast<char*>(&f_chunkSize), headerSize);
	}
	else
	{
		// Le fichier contient deja des donnees
		size_t p = m_stream.tellg();

		char headBuffer[headerSize];
		m_stream.seekg(0);
		m_stream.read(headBuffer, headerSize);

		// interpreter le debut du tampon comme un element de type size_t
		f_chunkSize = *(reinterpret_cast<size_t *>(headBuffer));

		// calculer le nombre de Chunk contenus dans le fichier
		f_numberChunks = (p - headerSize) / f_chunkSize;
	}

	// Conserver les donnees de dimensionnement et le nombre d'enregistrements
	setChunkSize(f_chunkSize);
	setNumberChunks(f_numberChunks);
}

AudioFile::~AudioFile(void)
{
	m_stream.close();
}

Chunk_const_iterator AudioFile::begin(void) const
{
	return Chunk_const_iterator(*this, 0);
}

Chunk_const_iterator AudioFile::end(void) const
{
	return Chunk_const_iterator(*this, getNumberChunks());
}

Chunk_iterator AudioFile::begin(void)
{
	return Chunk_iterator(*this, 0);
}

Chunk_iterator AudioFile::end(void)
{
	return Chunk_iterator(*this, getNumberChunks());
}

void AudioFile::addChunk(const Chunk_iterator & iter)
{
	m_stream.write((*iter).get(), getChunkSize());
}

size_t AudioFile::tellChunkg(void)
{
	std::streampos p = m_stream.tellg();
	size_t chunkIdx = (p - std::streampos(headerSize)) / getChunkSize();
	return chunkIdx;
}

size_t AudioFile::tellChunkp(void)
{
	std::streampos p = m_stream.tellp();
	size_t chunkIdx = (p - std::streampos(headerSize)) / getChunkSize();
	return chunkIdx;
}

void AudioFile::seekChunkg(size_t s)
{
	std::streampos p = s*getChunkSize() + headerSize;
	m_stream.seekg(p);
}

void AudioFile::seekChunkp(size_t s)
{
	std::streampos p = s*getChunkSize() + headerSize;
	m_stream.seekp(p);
}

void AudioFile::readChunk(char * buf)
{
	m_stream.read(buf, getChunkSize());
}

void AudioFile::writeChunk(const char * buf)
{
	m_stream.write(buf, getChunkSize());
}
