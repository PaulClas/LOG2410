///////////////////////////////////////////////////////////
//  CompositeTransform.h
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_COMPOSITE_TRANSFORM_)
#define _HEADER_COMPOSITE_TRANSFORM_

#include "AbsTransform.h"

class CompositeTransform : public AbsTransform
{
public:
	CompositeTransform(void) = default;
	CompositeTransform(const CompositeTransform& mdd);
	virtual ~CompositeTransform() = default;
	virtual CompositeTransform* clone(void) const;

	// Methode pour appliquer une transformation a une partie de fichier audio
	virtual void transform(const class Chunk_iterator& c, class AbsAudioFile& outFile) const;

	// Methodes de gestions des enfants
	virtual TransformIterator_const begin(void) const { return m_transforms.begin(); }
	virtual TransformIterator_const end(void) const { return m_transforms.end(); }
	virtual TransformIterator begin(void) { return m_transforms.begin(); }
	virtual TransformIterator end(void) { return m_transforms.end(); }
	virtual void addChild(const AbsTransform& t);
	virtual void removeChild(TransformIterator_const transfIt);

private:
	TransformContainer m_transforms;
};
#endif // !defined(_HEADER_COMPOSITE_TRANSFORM_)
