///////////////////////////////////////////////////////////
//  FileChecksumCalculator.h
//  Implementation of the Class FileChecksumCalculator
//  Created on:      26-oct.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_FileChecksumCalculator_)
#define _HEADER_FileChecksumCalculator_

#include <cstdint>

#include "AbsFileVisitor.h"

class FileChecksumCalculator : public AbsFileVisitor
{
public:
	FileChecksumCalculator(void) : m_checkSum(0) {};
	virtual FileChecksumCalculator* clone(void);

	virtual void visit(const class AudioFile&);
	virtual void visit(const class MemAudioFile&);

	uint64_t get_checkSum(void) const { return m_checkSum; };

private:
	uint64_t computeChunkHash(size_t chunkSize, const char* chunkData);
	uint64_t combineHash(uint64_t h1, uint64_t h2, size_t i);

	uint64_t m_checkSum;
};
#endif // !defined(_HEADER_FileChecksumCalculator_)
