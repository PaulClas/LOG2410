///////////////////////////////////////////////////////////
//  CompositeTransform.cpp
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CompositeTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

using namespace std;

CompositeTransform::CompositeTransform(const CompositeTransform & mdd)
{
   // A Completer...
	this->m_transforms.reserve(mdd.m_transforms.size());
}

// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const
{
    /*// A Completer...
	CompositeTransform* nouveauClone = new CompositeTransform;

	//Copie des transformations vers l'objet cloné 
	nouveauClone->m_transforms = this->m_transforms;
	//nouveauCLone.m_transforms= this.m_transforms;

	return nouveauClone;
	//return nullptr;*/

	if (this->m_transforms.size()>0)
		return new CompositeTransform(*this);
	return nullptr;
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	// A Completer...
	/*for (auto i : this->m_transforms)
		i->transform(c, outFile);*/

	for (size_t i = 0; i < this->m_transforms.size(); i++) {
		this->m_transforms[i]->transform(c, outFile);
	}
}

void CompositeTransform::addChild(const AbsTransform& t)
{ 
	// A Completer...
	//unique_ptr<AbsTransform> 
	this->m_transforms.push_back(std::make_unique<AbsTransform>(*t.clone()));

}

void CompositeTransform::removeChild(TransformIterator_const transfIt)
{
	// A Completer...
	for (auto it = this->m_transforms.begin(); it != this->m_transforms.end(); it++) {
		if (it == transfIt) {
			this->m_transforms.erase(it);
		}
	}

}
