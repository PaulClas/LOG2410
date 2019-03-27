///////////////////////////////////////////////////////////
//  RepeatTransform.cpp
//  Implementation of the Class RepeatTransform
//  Created on:      13-mar.-2017
//  Original author: francois
//	Modifié: Paul Clas 1846912 26 mars 2019
///////////////////////////////////////////////////////////

#include "RepeatTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"


void RepeatTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
    // A completer...
	//for (size_t i = 0; i < getNRepetitions(); i++)
	for (int i = 0; i < this->m_nRepetitions; i++) {
		outFile.addChunk(c);
	}
}

size_t RepeatTransform::getNRepetitions(void)
{
	return m_nRepetitions;
}

