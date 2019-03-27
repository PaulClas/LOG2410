///////////////////////////////////////////////////////////
//  InvertTransform.cpp
//  Implementation of the Class InvertTransform
//  Created on:      13-mar.-2017
//  Original author: francois
//	Modifié: Paul Clas 1846912 26 mars 2019
///////////////////////////////////////////////////////////

#include "InvertTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

using namespace std; // pour reverse

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

	Chunk_iterator chunk(c);
	reverse(chunk->get(), chunk->get() + chunk->size()); //http://www.cplusplus.com/reference/algorithm/reverse/
	outFile.addChunk(chunk);// comme RepeatTransform
}
