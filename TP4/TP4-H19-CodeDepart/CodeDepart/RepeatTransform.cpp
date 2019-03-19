///////////////////////////////////////////////////////////
//  RepeatTransform.cpp
//  Implementation of the Class RepeatTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "RepeatTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

void RepeatTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
    // A completer...
}

size_t RepeatTransform::getNRepetitions(void)
{
	return m_nRepetitions;
}

