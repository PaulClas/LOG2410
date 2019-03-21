///////////////////////////////////////////////////////////
//  RepeatTransform.h
//  Implementation of the Class RepeatTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_REPEAT_TRANSFORM_)
#define _HEADER_REPEAT_TRANSFORM_

#include "AbsTransform.h"

class RepeatTransform : public AbsTransform
{
	size_t m_nRepetitions;
public:
	RepeatTransform(size_t nRepeat) : m_nRepetitions(nRepeat) {};
	RepeatTransform* clone(void) const { return new RepeatTransform(m_nRepetitions); }

	// Methode pour appliquer une transformation a une partie de fichier audio
	virtual void transform(const class Chunk_iterator& c, class AbsAudioFile& outFile) const;

	virtual size_t getNRepetitions(void);
};
#endif // !defined(_HEADER_REPEAT_TRANSFORM_)
