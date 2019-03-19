///////////////////////////////////////////////////////////
//  Chunk.h
//  Implementation of the Class Chunk
//  Created on:      26-oct.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_CHUNK_)
#define _HEADER_CHUNK_

#include <memory>
#include <vector>

class Chunk
{
	std::vector<char> m_buffer;

public:
	Chunk(size_t s) : m_buffer(s, char(0)) {};
	Chunk(size_t s, const char* data) : m_buffer(data, data + s) {};

	size_t size(void) { return m_buffer.size(); };
	const char* get(void) const { return m_buffer.data(); }
	char* get(void) { return m_buffer.data(); }

	bool operator==(const Chunk& mdd) const { return m_buffer == mdd.m_buffer; }
	bool operator!=(const Chunk& mdd) const { return !(m_buffer == mdd.m_buffer); }
};

#endif // !defined(_HEADER_CHUNK_)
