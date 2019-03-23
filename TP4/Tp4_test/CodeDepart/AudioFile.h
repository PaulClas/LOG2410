///////////////////////////////////////////////////////////
//  AudioFile.h
//  Implementation of the Class AudioFile
//  Created on:      26-oct.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_AudioFile_)
#define _HEADER_AudioFile_

#include <string>
#include <fstream>

#include "AbsAudioFile.h"

class AudioFile : public AbsAudioFile
{
public:
	AudioFile(const std::string& fname);
	~AudioFile(void);

	virtual Chunk_const_iterator begin(void) const;
	virtual Chunk_const_iterator end(void) const;
	virtual Chunk_iterator begin(void);
	virtual Chunk_iterator end(void);
	virtual void addChunk(const Chunk_iterator& iter);

protected:
	friend class MemAudioFile;
	virtual size_t tellChunkg(void);
	virtual size_t tellChunkp(void);
	virtual void seekChunkg(size_t p);
	virtual void seekChunkp(size_t p);
	virtual void readChunk(char* buf);
	virtual void writeChunk(const char* buf);

private:
	std::fstream m_stream;
};

#endif // !defined(_HEADER_AudioFile_)
