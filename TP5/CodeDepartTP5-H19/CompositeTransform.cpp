///////////////////////////////////////////////////////////
//  CompositeTransform.cpp
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CompositeTransform.h"

CompositeTransform::CompositeTransform(const CompositeTransform & mdd)
{
	for (auto& it : mdd.m_transforms)
			addChild(*it);
}

// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const
{
	return new CompositeTransform( *this );
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	for(auto& it : m_transforms)
		it->transform(c, outFile);
}

void CompositeTransform::addChild(const AbsTransform& t)
{ 
	m_transforms.push_back(TransformPtr(t.clone()));
}

void CompositeTransform::removeChild(TransformIterator_const transfIt)
{
	m_transforms.erase(transfIt);
}
