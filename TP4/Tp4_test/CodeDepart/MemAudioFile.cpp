///////////////////////////////////////////////////////////
//  MemAudioFile.h
//  Implementation of the Class MemAudioFile
//  Created on:      26-oct.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include <cstring>
#include "MemAudioFile.h"

MemAudioFile::MemAudioFile(const std::string & fname)
	: AbsAudioFile(fname),
	m_subject(std::make_shared<AudioFile>(fname)),
	m_memBuffer(m_subject->getNumberChunks() * m_subject->getChunkSize() + headerSize),
	m_putP(0), m_getP(0)
{

	size_t chunkSize = m_subject->getChunkSize();
	size_t numberChunks = m_subject->getNumberChunks();
	setChunkSize(chunkSize);
	setNumberChunks(numberChunks);

    // initialiser l'entete
	char* bufp = m_memBuffer.data();
	*(reinterpret_cast<int*>(bufp)) = chunkSize;

	// Recuperer toutes les donnees du fichier pour les mettre en memoire
	bufp += headerSize;
	m_subject->seekChunkp(0);
	for (size_t iChunk = 0; iChunk < numberChunks; ++iChunk)
		m_subject->readChunk(bufp + iChunk*chunkSize);

	// Placer les curseurs de lecture/ecriture comme dans le fichier
	m_putP = headerSize + m_subject->tellChunkp() * numberChunks;
	m_getP = headerSize + m_subject->tellChunkg() * numberChunks;
}

MemAudioFile::~MemAudioFile(void)
{
	// Placer le pointeur d'ecriture du fichier sur le premier Chunk
	m_subject->seekChunkp(0);

	// Ecrire toutes les donnees dans le fichier
	for (Chunk_iterator iter = begin(); iter != end(); ++iter)
		m_subject->addChunk(iter);
}

Chunk_const_iterator MemAudioFile::begin(void) const
{
	return Chunk_const_iterator(*this,0);
}

Chunk_const_iterator MemAudioFile::end(void) const
{
	return Chunk_const_iterator(*this, getNumberChunks());
}

Chunk_iterator MemAudioFile::begin(void)
{
	return Chunk_iterator(*this, 0);
}

Chunk_iterator MemAudioFile::end(void)
{
	return Chunk_iterator(*this, getNumberChunks());
}

void MemAudioFile::addChunk(const Chunk_iterator & iter)
{
	// Se positionner a la fin du fichier et ecrire le Chunk
	size_t newSize = m_putP + getChunkSize();
	m_memBuffer.reserve(newSize);
	if (m_memBuffer.size() < newSize)
	{
		m_memBuffer.resize(newSize);
		setNumberChunks(getNumberChunks()+1);
	}
	memcpy(m_memBuffer.data()+m_putP, (*iter).get(), getChunkSize());
	m_putP += getChunkSize();
}

AbsAudioFile & MemAudioFile::getSubject(void)
{
	return *m_subject;
}

const AbsAudioFile & MemAudioFile::getSubject(void) const
{
	return *m_subject;
}

size_t MemAudioFile::tellChunkg(void)
{
	return (m_getP - headerSize) / getChunkSize();
}

size_t MemAudioFile::tellChunkp(void)
{
	return (m_putP - headerSize) / getChunkSize();
}

void MemAudioFile::seekChunkg(size_t s)
{
	m_getP = s*getChunkSize() + headerSize;
}

void MemAudioFile::seekChunkp(size_t s)
{
	m_putP = s*getChunkSize() + headerSize;
}

void MemAudioFile::readChunk(char * buf)
{
	memcpy(buf, m_memBuffer.data() + m_getP, getChunkSize());
	m_getP += getChunkSize();
}

void MemAudioFile::writeChunk(const char * buf)
{
	size_t newSize = m_putP + getChunkSize();
	m_memBuffer.reserve(newSize);
	if (m_memBuffer.size() < newSize)
	{
		m_memBuffer.resize(newSize);
		setNumberChunks(getNumberChunks() + 1);
	}
	memcpy(m_memBuffer.data() + m_putP, buf, getChunkSize());
	m_putP += getChunkSize();
}
