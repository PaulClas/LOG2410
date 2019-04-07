/*****************************************************************************/
//  Test_TP5.h
//  Implementation of the Class Test_TP5
//  Created on:      2015-10-14
//  Modified on:     2017-11-12
//  Original author: El Houcine Boudoukha and Farouk Ouenniche
//  Modification:    Francois Guibault - Adapt to PolySonor
/*****************************************************************************/

#ifndef Test_TP5_H
#define Test_TP5_H

#include <string>
#include <memory>
#include <exception>

#include "AbsTransform.h"

//
// Classe TestTP5
//
// Classe de test pour les elements implementes au TP5
//
class Test_TP5
{
private:
	std::shared_ptr<AbsTransform> m_racineComposite;

	const std::string m_nameAudiof1 = "audiof1.bin";                           // Fichier de travail de base

	const std::string m_nameAudiof_proxy = "audiof_proxy.bin";                 // Fichier de resultat pour le Proxy
	const std::string m_nameAudiof_rt = "audiof_rt.bin";                       // Fichier de resultat pour la transformation de repetition
	const std::string m_nameAudiof_inv = "audiof_inv.bin";                     // Fichier de resultat pour la transformation d'inversion
	const std::string m_nameAudiof_composite = "audiof_composit.bin";          // Fichier de resultat pour la transformation composite
	const std::string m_nameAudiof_FR = "audiof_FR.bin";                       // Fichier de resultat pour le visiteur Find/Replace
	const std::string m_nameAudiof_FR_mem = "audiof_FR_mem.bin";               // Fichier de resultat pour le visiteur Find/Replace via le Proxy
	const std::string m_nameAudiof_FR_cmd = "audiof_FR_cmd.bin";               // Fichier de resultat pour la commande Find/Replace
	const std::string m_nameAudiof_composite_cmd = "audiof_composite_cmd.bin"; // Fichier de resultat pour la commande de transformation composite
	const std::string m_nameAudiof_multi_cmd = "audiof_multi_cmd.bin";         // Fichier de resultat pour les commandes multiples


	const std::string m_nameAudiof_ref1 = "audiof_ref1.bin";                  // Fichier de reference pour le fichier de travail de base
	const std::string m_nameAudiof_rt_ref = "audiof_rt_ref.bin";              // Fichier de reference pour la transformation de repetition
	const std::string m_nameAudiof_inv_ref = "audiof_inv_ref.bin";            // Fichier de reference pour la transformation d'inversion
	const std::string m_nameAudiof_composite_ref = "audiof_composit_ref.bin"; // Fichier de reference pour la transformation composite
	const std::string m_nameAudiof_FR_ref = "audiof_FR_ref.bin";              // Fichier de reference pour le visiteur Find/Replace
	const std::string m_nameAudiof_multi_ref = "audiof_multi_ref.bin";        // Fichier de reference pour les commandes multiples

	const uint64_t m_Audiof1CheckSumRef         = 17252709550581968364;
	const uint64_t m_Audiof1CheckSumMultiCmdRef = 17289298559521254894;

protected:
	bool CompareFilesEqual(const AbsAudioFile& f1, const AbsAudioFile& f2);

public:

	//-------------------------------------------
	// Constructeur & Destructeur
	//-------------------------------------------
	Test_TP5();
	~Test_TP5();

	// Tests
	void executeProxyTest();          // Execute les tests sur le Proxy
	void executeCompositeTest();      // Execute les tests sur les composites
	void executeVisitorTest();        // Execute les tests sur les visiteurs
	void executeCommandTest();        // Execute les tests sur les commandes
};

#endif// Test_TP5_H
