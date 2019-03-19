///////////////////////////////////////////////////////////
//  AbsAudioFile.h
//  Implementation of the Class AbsAudioFile
//  Created on:      26-oct.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_AbsAudioFile_)
#define _HEADER_AbsAudioFile_

#include <string>

#include "ChunkIterator.h"

class AbsAudioFile
{
public:
	AbsAudioFile(const std::string& fname, size_t chunkSize = defaultChunkSize) 
		: m_fname(fname), m_chunkSize(chunkSize), m_numberChunks(0) {};
	virtual ~AbsAudioFile(void) {};

	const std::string& getName(void) const { return m_fname; }
	size_t getChunkSize(void) const { return m_chunkSize; }
	size_t getNumberChunks(void) const { return m_numberChunks; };

	virtual Chunk_const_iterator begin(void) const = 0;
	virtual Chunk_const_iterator end(void) const = 0;
	virtual Chunk_iterator begin(void) = 0;
	virtual Chunk_iterator end(void) = 0;
	virtual void addChunk(const Chunk_iterator& iter) = 0;

protected:
	const static size_t defaultChunkSize = 10;
	const static size_t headerSize = sizeof(size_t);
	void setChunkSize(size_t chunkSize) { m_chunkSize = chunkSize; }
	void setNumberChunks(size_t numberChunks) { m_numberChunks = numberChunks; }

	virtual size_t tellChunkg(void) = 0;
	virtual size_t tellChunkp(void) = 0;
	virtual void seekChunkg(size_t p) = 0;
	virtual void seekChunkp(size_t p) = 0;
	virtual void readChunk(char* buf) = 0;
	virtual void writeChunk(const char* buf) = 0;

private:
	std::string m_fname;
	size_t m_chunkSize;
	size_t m_numberChunks;
	friend class Chunk_iterator_base;
};

#endif // !defined(_HEADER_AbsAudioFile_)
