#include <cstring>
#include "RepeatTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

void RepeatTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	Chunk_iterator chunkOut(outFile, outFile.getNumberChunks());
	char* bufIn = c->get(); 
	char* bufOut = chunkOut->get();
	memcpy(bufOut, bufIn, c->size());
	for (size_t irep = 0; irep < m_nRepetitions; ++irep)
		outFile.addChunk(chunkOut);
}

size_t RepeatTransform::getNRepetitions(void)
{
	return m_nRepetitions;
}

