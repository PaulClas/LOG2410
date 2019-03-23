///////////////////////////////////////////////////////////
//  AbsTransform.h
//  Implementation of the Class AbsTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_ABS_TRANSFORM_)
#define _HEADER_ABS_TRANSFORM_

#include "TransformContainer.h"

class AbsTransform
{
public:
	AbsTransform(void) {};
	virtual ~AbsTransform() {};
	virtual AbsTransform* clone(void) const = 0;

	// Methode pour appliquer une transformation a une partie de fichier audio
	virtual void transform( const class Chunk_iterator& c, class AbsAudioFile& outFile ) const = 0;

	virtual TransformIterator_const begin(void) const;
	virtual TransformIterator_const end(void) const;
	virtual TransformIterator begin(void);
	virtual TransformIterator end(void);
	virtual void addChild(const AbsTransform& t);
	virtual void removeChild(TransformIterator_const transfIt);

private:
	// Vecteur vide de transformation permettant de retourner des iterateurs valides
	static TransformContainer m_empty_transforms;
};
#endif // !defined(_HEADER_ABS_TRANSFORM_)
