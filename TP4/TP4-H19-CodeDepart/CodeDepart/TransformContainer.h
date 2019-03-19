///////////////////////////////////////////////////////////
//  TransformContainer.h
//  Implementation of the Class TransformContainer
//  Created on:      06-mars-2019 21:00:27
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_6B742824_EE49_4414_888C_D9615C2AD3DB__INCLUDED_)
#define EA_6B742824_EE49_4414_888C_D9615C2AD3DB__INCLUDED_

#include <iterator>
#include <memory>
#include <vector>

// Configuration du stockage des enfants des objets composites
using TransformPtr = std::unique_ptr<class AbsTransform>;
using TransformContainer = std::vector<TransformPtr>;
using TransformBaseIterator = TransformContainer::iterator;
using TransformBaseIterator_const = TransformContainer::const_iterator;

class TransformIterator : public TransformBaseIterator
{
public:
	TransformIterator(const TransformContainer::iterator& it) : TransformBaseIterator(it) {}

	// Operateurs simplifiant l'acces a la transformation sur lequel pointe l'iterateur
	// pour TransformIterator it;
	//    *it est la transformation
	//    it-> permet d'invoquer une methode de la transformation
	class AbsTransform& operator*() { return *((*(TransformBaseIterator(*this))).get()); }
	class AbsTransform* operator->() { return (*(TransformBaseIterator(*this))).get(); }
};

class TransformIterator_const : public TransformBaseIterator_const
{
public:
	TransformIterator_const(const TransformContainer::const_iterator& it) : TransformBaseIterator_const(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour TransformIterator_const it;
	//    *it est la transformation
	//    it-> permet d'invoquer une methode const sur la transformation
	const class AbsTransform& operator*() { return *((*(TransformBaseIterator_const(*this))).get()); }
	const class AbsTransform* operator->() { return (*(TransformBaseIterator_const(*this))).get(); }
};
#endif // !defined(EA_6B742824_EE49_4414_888C_D9615C2AD3DB__INCLUDED_)
