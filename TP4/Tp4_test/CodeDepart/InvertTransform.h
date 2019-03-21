///////////////////////////////////////////////////////////
//  InvertTransform.h
//  Implementation of the Class InvertTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_INVERT_TRANSFORM_)
#define _HEADER_INVERT_TRANSFORM_

#include "AbsTransform.h"

class InvertTransform : public AbsTransform
{
public:
	InvertTransform(void) {};
	InvertTransform* clone(void) const { return new InvertTransform; }

	// Methode pour appliquer une transformation a une partie de fichier audio
	virtual void transform(const Chunk_iterator& c, AbsAudioFile& outFile) const;
};
#endif // !defined(_HEADER_INVERT_TRANSFORM_)
