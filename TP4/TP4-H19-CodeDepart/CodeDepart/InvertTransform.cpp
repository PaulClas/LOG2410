///////////////////////////////////////////////////////////
//  InvertTransform.cpp
//  Implementation of the Class InvertTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "InvertTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"



using namespace std;

// Methode pour appliquer une transformation d'inversion à un Chunk
void InvertTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	// A Completer...

	 /*while ((first != last) && (first != --last)) {
		 std::iter_swap(first, last);
		 ++first;
	 */
	 //Chunk_iterator first = c.get(0);
	 //Chunk_iterator last = c.get(c.size() - 1);
	/*int i = 0;
	std::reverse(c.get(i), c.get(c.size() - 1));
	outFile.addChunk(c);*/

	Chunk_iterator w(c);
	std::reverse(w->get(), w->get() + w->size());
	outFile.addChunk(w);
}
