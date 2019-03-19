/*****************************************************************************/
//  Test_TP4.h
//  Implementation of the Class Test_TP4
//  Created on:      2015-10-14
//  Modified on:     2019-03-06
//  Original author: El Houcine Boudoukha and Farouk Ouenniche
//  Modification:    Francois Guibault - Adapt to PolyVersion
/*****************************************************************************/

#ifndef Test_TP5_H
#define Test_TP5_H

#include <string>
#include <memory>
#include <exception>

#include "AbsTransform.h"

//
// Classe TestTP4
//
// Classe de test pour les elements implementes au TP4
//
class Test_TP4
{
private:
	std::shared_ptr<AbsTransform> m_racineComposite;

	const std::string m_nameAudiof1 = "audiof1.bin";                           // Fichier de travail de base

	const std::string m_nameAudiof_proxy = "audiof_proxy.bin";                 // Fichier de resultat pour le Proxy
	const std::string m_nameAudiof_rt = "audiof_rt.bin";                       // Fichier de resultat pour la transformation de repetition
	const std::string m_nameAudiof_inv = "audiof_inv.bin";                     // Fichier de resultat pour la transformation d'inversion
	const std::string m_nameAudiof_composite = "audiof_composit.bin";          // Fichier de resultat pour la transformation composite

	const std::string m_nameAudiof_ref1 = "audiof_ref1.bin";                   // Fichier de reference pour le fichier de travail de base
	const std::string m_nameAudiof_rt_ref = "audiof_rt_ref.bin";               // Fichier de reference pour la transformation de repetition
	const std::string m_nameAudiof_inv_ref = "audiof_inv_ref.bin";             // Fichier de reference pour la transformation d'inversion
	const std::string m_nameAudiof_composite_ref = "audiof_composit_ref.bin";  // Fichier de reference pour la transformation composite

protected:
	bool CompareFilesEqual(const AbsAudioFile& f1, const AbsAudioFile& f2);

public:

	//-------------------------------------------
	// Constructeur & Destructeur
	//-------------------------------------------
	Test_TP4();
	~Test_TP4();

	// Tests
	void executeProxyTest();          // Execute les tests sur le Proxy
	void executeCompositeTest();      // Execute les tests sur les composites
};

#endif// Test_TP5_H
