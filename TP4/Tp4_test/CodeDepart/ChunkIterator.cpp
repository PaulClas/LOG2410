#include "ChunkIterator.h"
#include "AudioFile.h"

void Chunk_iterator_base::inc(void) 
{
	// Avancer d'un Chunk 
	if (m_chunkIdx < m_audioFile.getNumberChunks())
	{
		++m_chunkIdx;
		m_audioFile.seekChunkg(m_chunkIdx);

		// Si on est pas à la fin, charger localement le Chunk dans l'iterateur
		if(m_chunkIdx < m_audioFile.getNumberChunks())
			m_audioFile.readChunk(m_currentChunk.get());
	}
}

void Chunk_iterator_base::dec(void) 
{ 
	// Reculer d'un Chunk et le charger localement dans l'iterateur
	if (m_chunkIdx > 0)
	{
		--m_chunkIdx;
		m_audioFile.seekChunkg(m_chunkIdx);
		m_audioFile.readChunk(m_currentChunk.get());
	}
}

void Chunk_iterator_base::inc(size_t s) 
{ 
	// Avancer de 's' Chunks
	if ((m_chunkIdx+s) <= m_audioFile.getNumberChunks())
	{
		m_chunkIdx += s;
		m_audioFile.seekChunkg(m_chunkIdx);

		// Si on est pas à la fin, charger localement le Chunk dans l'iterateur
		if (m_chunkIdx < m_audioFile.getNumberChunks())
			m_audioFile.readChunk(m_currentChunk.get());
	}
}

void Chunk_iterator_base::dec(size_t s) 
{ 
	// Si on est pas au debut, reculer de 's' Chunks et le charger localement dans l'iterateur
	if (m_chunkIdx > 0)
	{
		m_chunkIdx = (m_chunkIdx > s) ? m_chunkIdx - s : 0;
		m_audioFile.seekChunkg(m_chunkIdx);
		m_audioFile.readChunk(m_currentChunk.get());
	}
}

Chunk & Chunk_iterator_base::get(void) const
{ 
	return const_cast<Chunk&>(m_currentChunk); 
}

Chunk * Chunk_iterator_base::getp(void) const
{
	return const_cast<Chunk*>(&m_currentChunk);
}

Chunk & Chunk_iterator_base::get(size_t pos) const
{
	return const_cast<Chunk&>(m_currentChunk);
}

bool Chunk_iterator_base::equal(const Chunk_iterator_base & rhs) const
{
	bool compare = (m_chunkIdx == rhs.m_chunkIdx) && (&m_audioFile == &(rhs.m_audioFile));
	return compare;
}

Chunk_iterator_base::Chunk_iterator_base(class AbsAudioFile& audioFile, size_t pos)
	: m_chunkIdx(pos), m_audioFile(audioFile), m_currentChunk(audioFile.getChunkSize())
{
	if (pos < m_audioFile.getNumberChunks())
	{
		m_audioFile.seekChunkg(pos);
		m_audioFile.readChunk(m_currentChunk.get());
	}
}

Chunk_iterator_base::Chunk_iterator_base(const Chunk_iterator_base & mdd) 
	: m_chunkIdx(mdd.m_chunkIdx), m_audioFile(mdd.m_audioFile), m_currentChunk(mdd.m_currentChunk)
{
}
