///////////////////////////////////////////////////////////
//  CompositeTransform.cpp
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CompositeTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

CompositeTransform::CompositeTransform(const CompositeTransform & mdd)
{
   // A Completer...
}

// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const
{
    // A Completer...
	return nullptr;
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	// A Completer...
}

void CompositeTransform::addChild(const AbsTransform& t)
{ 
	// A Completer...
}

void CompositeTransform::removeChild(TransformIterator_const transfIt)
{
	// A Completer...
}
