#include "InvertTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

// Methode pour appliquer une transformation d'inversion à un Chunk
void InvertTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{ 
	Chunk_iterator chunkOut(outFile, outFile.getNumberChunks());
	char* bufIn = c->get();
	char* bufOut = chunkOut->get();

	size_t s = c->size();
	
	for (size_t i = 0; i < s; ++i)
		bufOut[s - i - 1] = bufIn[i];

	outFile.addChunk(chunkOut);
}
