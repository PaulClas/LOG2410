///////////////////////////////////////////////////////////
//  AbsTransform.cpp
//  Implementation of the Class AbsTransform
//  Created on:      7-mar.-2019
//  Original author: francois
///////////////////////////////////////////////////////////

#include "AbsTransform.h"

TransformContainer AbsTransform::m_empty_transforms;

TransformIterator_const AbsTransform::begin(void) const
{ 
	return m_empty_transforms.begin(); 
}

TransformIterator_const AbsTransform::end(void) const
{ 
	return  m_empty_transforms.end(); 
}

TransformIterator AbsTransform::begin(void) 
{ 
	return  m_empty_transforms.begin(); 
}

TransformIterator AbsTransform::end(void)
{ 
	return  m_empty_transforms.end(); 
}

void AbsTransform::addChild(const AbsTransform & t) 
{ 
	/* echoue silencieusement */ 
}

void AbsTransform::removeChild(TransformIterator_const transfIt)
{
	/* echoue silencieusement */
}
