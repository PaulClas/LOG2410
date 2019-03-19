///////////////////////////////////////////////////////////
//  MemAudioFile.h
//  Implementation of the Class MemAudioFile
//  Created on:      26-oct.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_MemAudioFile_)
#define _HEADER_MemAudioFile_

#include <string>
#include <fstream>

#include "AudioFile.h"

class MemAudioFile : public AbsAudioFile
{
public:
	MemAudioFile(const std::string& fname);
	~MemAudioFile(void);

	virtual Chunk_const_iterator begin(void) const;
	virtual Chunk_const_iterator end(void) const;
	virtual Chunk_iterator begin(void);
	virtual Chunk_iterator end(void);
	virtual void addChunk(const Chunk_iterator& iter);

	AbsAudioFile& getSubject(void);
	const AbsAudioFile& getSubject(void) const;

protected:
	virtual size_t tellChunkg(void);
	virtual size_t tellChunkp(void);
	virtual void seekChunkg(size_t p);
	virtual void seekChunkp(size_t p);
	virtual void readChunk(char* buf);
	virtual void writeChunk(const char* buf);

private:
	std::shared_ptr<AudioFile> m_subject;
	std::vector<char> m_memBuffer;
	size_t m_putP;
	size_t m_getP;
};

#endif // !defined(_HEADER_MemAudioFile_)
