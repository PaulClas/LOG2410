
#include <cstdio>
#include <iostream>
#include <stdexcept>

#include "Test_TP5.h"

#include "Chunk.h"
#include "ChunkIterator.h"
#include "AudioFile.h"
#include "MemAudioFile.h"

#include "CompositeTransform.h"
#include "InvertTransform.h"
#include "RepeatTransform.h"

#include "FileChecksumCalculator.h"
#include "FileStringFindReplace.h"

#include "CommandExecutor.h"
#include "ChecksumCommand.h"
#include "StringFindReplaceCommand.h"
#include "TransformCommand.h"

bool Test_TP5::CompareFilesEqual(const AbsAudioFile & f1, const AbsAudioFile & f2)
{
	if (f1.getNumberChunks() != f2.getNumberChunks() || f1.getChunkSize() != f2.getChunkSize())
		return false;

	Chunk_const_iterator it1 = f1.begin();
	Chunk_const_iterator it2 = f2.begin();

	while (it1 != f1.end())
	{
		if (*it1 != *it2)
			return false;
		++it1;
		++it2;
	}

	return true;
}

Test_TP5::Test_TP5()
{
	{
		// Si necessaire, generer le fichier de travail audiof1.bin
		AudioFile audiof1(m_nameAudiof1);
		if(audiof1.getNumberChunks() == 0)
		{
			Chunk_iterator it(audiof1);
			char* buf = (*it).get();
			char A = 'A';
			size_t chunkSize = audiof1.getChunkSize();

			for (char c2 = 0; c2 < chunkSize; ++c2)
				buf[c2] = A + c2;
			audiof1.addChunk(it);

			for (char c1 = 0; c1 < 7; ++c1)
			{
				std::fill(buf, buf + chunkSize, A+c1);
				audiof1.addChunk(it);
			}

			for (char c2 = 0; c2 < chunkSize; ++c2)
				buf[c2] = A+c2;
			audiof1.addChunk(it);

			char q = 'q';
			for (char c3 = 6; c3 >= 0; --c3)
			{
				std::fill(buf, buf + chunkSize, q+c3);
				audiof1.addChunk(it);
			}
		}
	}
	{
		// Verifier que le fichier audiof1.bin a ete genere correctement et contient l'information attendue
		AudioFile audiof1(m_nameAudiof1);
		AudioFile fileRef(m_nameAudiof_ref1);
		bool compare = CompareFilesEqual(audiof1, fileRef);
		if(!compare)
			throw std::runtime_error("Attention! Le fichier audiof1.bin ne contient pas l'information attendue.");
	}

	// Si les fichiers de resultat existent, les enlever
	remove(m_nameAudiof_proxy.c_str());
	remove(m_nameAudiof_rt.c_str());
	remove(m_nameAudiof_inv.c_str());
	remove(m_nameAudiof_composite.c_str());
	remove(m_nameAudiof_FR.c_str());
	remove(m_nameAudiof_FR_mem.c_str());
	remove(m_nameAudiof_FR_cmd.c_str());
	remove(m_nameAudiof_composite_cmd.c_str());
	remove(m_nameAudiof_multi_cmd.c_str());
}

Test_TP5::~Test_TP5()
{
}

void Test_TP5::executeProxyTest()
{
	std::cout << std::endl << std::endl << "------------------------- PROXY -------------------------------" << std::endl << std::endl;
	std::cout << std::endl;

	{
		// Utiliser un proxy pour charger un fichier
		MemAudioFile memFileIn(m_nameAudiof1);

		// Utiliser un proxy pour reecrire le fichier
		MemAudioFile memFileOut(m_nameAudiof_proxy);

		// Vérifier que le fichier de sortie ne contient pas déjà des données
		// Sinon, réécrire par-dessus
		if (memFileOut.getNumberChunks() != 0)
		{
		}

		for (Chunk_iterator iter = memFileIn.begin(); iter != memFileIn.end(); ++iter)
			memFileOut.addChunk(iter);
	}
	{
		// Verifier l'utilisation du proxy en lecture et ecriture
		AudioFile audiof1(m_nameAudiof1);
		AudioFile proxyFile(m_nameAudiof_proxy);
		bool compare = CompareFilesEqual(audiof1, proxyFile);
		std::cout << "PROXY Test 1: " << (compare ? "SUCCES" : "ECHEC") << std::endl;
	}
}

void Test_TP5::executeCompositeTest()
{
	std::cout << std::endl << std::endl << "------------------------- COMPOSITE -------------------------------" << std::endl << std::endl;
	std::cout << std::endl;

	AudioFile audiof1(m_nameAudiof1);
	RepeatTransform rt(2);
	{
		// Appliquer la transformation de repetition seule
		AudioFile audiof_rt(m_nameAudiof_rt);
		for (Chunk_iterator iter = audiof1.begin(); iter != audiof1.end(); ++iter)
			rt.transform(iter, audiof_rt);
	}
	{
		// Verifier l'application de la transformation de repetition seule
		AudioFile audiof_rt(m_nameAudiof_rt);
		AudioFile audiof_rt_ref(m_nameAudiof_rt_ref);
		bool compare = CompareFilesEqual(audiof_rt, audiof_rt_ref);
		std::cout << "COMPOSITE Test 1: " << (compare ? "SUCCES" : "ECHEC") << std::endl;
	}

	InvertTransform invt;
	{
		// Appliquer la transformation d'inversion seule
		AudioFile audiof_inv(m_nameAudiof_inv);
		for (Chunk_iterator iter = audiof1.begin(); iter != audiof1.end(); ++iter)
			invt.transform(iter, audiof_inv);
	}
	{
		// Verifier l'application de la transformation d'inversion seule
		AudioFile audiof_inv(m_nameAudiof_inv);
		AudioFile audiof_inv_ref(m_nameAudiof_inv_ref);
		bool compare = CompareFilesEqual(audiof_inv, audiof_inv_ref);
		std::cout << "COMPOSITE Test 2: " << (compare ? "SUCCES" : "ECHEC") << std::endl;
	}

	m_racineComposite = std::make_shared<CompositeTransform>();
	CompositeTransform composit1;
	composit1.addChild(rt);
	composit1.addChild(invt);
	m_racineComposite->addChild(invt);
	m_racineComposite->addChild(composit1);
	{
		// Appliquer la transformation composite
		AudioFile audiof_composit(m_nameAudiof_composite);
		for (Chunk_iterator iter = audiof1.begin(); iter != audiof1.end(); ++iter)
			m_racineComposite->transform(iter, audiof_composit);

	}
	{
		// Verifier l'application de la transformation composite
		AudioFile audiof_composit(m_nameAudiof_composite);
		AudioFile audiof_composit_ref(m_nameAudiof_composite_ref);
		bool compare = CompareFilesEqual(audiof_composit, audiof_composit_ref);
		std::cout << "COMPOSITE Test 3: " << (compare ? "SUCCES" : "ECHEC") << std::endl;
	}
}

void Test_TP5::executeVisitorTest()
{
	std::cout << std::endl << std::endl << "------------------------- VISITEUR -------------------------------" << std::endl << std::endl;
	std::cout << std::endl;

	FileChecksumCalculator cksumvis;
	{
		// Calculer le checksum du fichier audiof1.bin
		AudioFile audiof1(m_nameAudiof1);
		audiof1.accept(cksumvis);
		const uint64_t resultVis = cksumvis.get_checkSum();
		std::cerr << "m_Audiof1CheckSumRef = " << m_Audiof1CheckSumRef << "resultVis = " << resultVis << std::endl;
		std::cout << "VISITEUR Test 1: " << (m_Audiof1CheckSumRef == resultVis ? "SUCCES" : "ECHEC") << std::endl;
	}
	{
		// Calculer le checksum du fichier audiof1.bin au travers d'un Proxy
		MemAudioFile audiof1(m_nameAudiof1);
		audiof1.accept(cksumvis);
		const uint64_t resultVis = cksumvis.get_checkSum();
		std::cout << "VISITEUR Test 2: " << (m_Audiof1CheckSumRef == resultVis ? "SUCCES" : "ECHEC") << std::endl;
	}

	std::vector<char> search_seq = { 'A','B','C' };
	std::vector<char> replac_seq = { '1','2','3' };
	{
		// Appliquer l'operation de Find/Replace seule au fichier audiof1.bin
		std::shared_ptr<AudioFile> outf = std::make_shared<AudioFile>(m_nameAudiof_FR);
		FileStringFindReplace findrepvis(search_seq, replac_seq, outf);
		AudioFile audiof1(m_nameAudiof1);
		audiof1.accept(findrepvis);
	}
	{
		// Verifier l'application du Find/Replace au fichier audiof1.bin
		AudioFile audiof_FR(m_nameAudiof_FR);
		AudioFile audiof_FR_ref(m_nameAudiof_FR_ref);
		bool compare = CompareFilesEqual(audiof_FR, audiof_FR_ref);
		std::cout << "VISITEUR Test 3: " << (compare ? "SUCCES" : "ECHEC") << std::endl;
	}
	{
		// Appliquer l'operation de Find/Replace seule au fichier audiof1.bin au travers d'un Proxy
		std::shared_ptr<AudioFile> outf = std::make_shared<AudioFile>(m_nameAudiof_FR_mem);
		FileStringFindReplace findrepvis(search_seq, replac_seq, outf);
		MemAudioFile audiof1(m_nameAudiof1);
		audiof1.accept(findrepvis);
	}
	{
		// Verifier l'application du Find/Replace au fichier audiof1.bin au travers du Proxy
		AudioFile audiof_FR_mem(m_nameAudiof_FR_mem);
		AudioFile audiof_FR_ref(m_nameAudiof_FR_ref);
		bool compare = CompareFilesEqual(audiof_FR_mem, audiof_FR_ref);
		std::cout << "VISITEUR Test 4: " << (compare ? "SUCCES" : "ECHEC") << std::endl;
	}
}

void Test_TP5::executeCommandTest()
{
	std::cout << std::endl << std::endl << "------------------------- COMMANDE -------------------------------" << std::endl << std::endl;
	std::cout << std::endl;

	CommandExecutor& cmdexecutor = CommandExecutor::getInstance();

	{
		// Construire et executer une commande de calcul de checksum seule
		AudioFile audiof1(m_nameAudiof1);
		std::shared_ptr<ChecksumCommand> cksumcmd = std::make_shared<ChecksumCommand>();
		cmdexecutor.addCommand(cksumcmd);
		cmdexecutor.executeAllCommands(audiof1);
		cmdexecutor.clearAllCommands();
		const uint64_t resultCmd = cksumcmd->get_checkSum();
		std::cout << "COMMANDE Test 1: " << (m_Audiof1CheckSumRef == resultCmd ? "SUCCES" : "ECHEC") << std::endl;
	}

	std::vector<char> search_seq = { 'A','B','C' };
	std::vector<char> replac_seq = { '1','2','3' };
	{
		// Construire et executer une commande Find/Replace seule
		AudioFile audiof1(m_nameAudiof1);
		std::shared_ptr<AudioFile> outf = std::make_shared<AudioFile>(m_nameAudiof_FR_cmd);
		std::shared_ptr<StringFindReplaceCommand> frcmd = std::make_shared<StringFindReplaceCommand>(search_seq, replac_seq, outf);
		cmdexecutor.addCommand(frcmd);
		cmdexecutor.executeAllCommands(audiof1);
		cmdexecutor.clearAllCommands();
	}
	{
		// Verifier l'application du Find/Replace au fichier audiof1.bin
		AudioFile audiof_FR_cmd(m_nameAudiof_FR_cmd);
		AudioFile audiof_FR_ref(m_nameAudiof_FR_ref);
		bool compare = CompareFilesEqual(audiof_FR_cmd, audiof_FR_ref);
		std::cout << "COMMANDE Test 2: " << (compare ? "SUCCES" : "ECHEC") << std::endl;
	}

	{
		// Construire et executer une commande de transformation composite seule
		AudioFile audiof1(m_nameAudiof1);
		std::shared_ptr<AudioFile> outf = std::make_shared<AudioFile>(m_nameAudiof_composite_cmd);
		std::shared_ptr<TransformCommand> transcmd = std::make_shared<TransformCommand>(m_racineComposite, outf);
		cmdexecutor.addCommand(transcmd);
		cmdexecutor.executeAllCommands(audiof1);
		cmdexecutor.clearAllCommands();
	}
	{
		// Verifier l'application de la transformation composite
		AudioFile audiof_composite_cmd(m_nameAudiof_composite_cmd);
		AudioFile audiof_composite_ref(m_nameAudiof_composite_ref);
		bool compare = CompareFilesEqual(audiof_composite_cmd, audiof_composite_ref);
		std::cout << "COMMANDE Test 3: " << (compare ? "SUCCES" : "ECHEC") << std::endl;
	}
	{
		// Construire et plusieurs commandes sur le meme fichier
		AudioFile audiof1(m_nameAudiof1);
		std::shared_ptr<AudioFile> outf = std::make_shared<AudioFile>(m_nameAudiof_multi_cmd);
		std::shared_ptr<TransformCommand> transcmd = std::make_shared<TransformCommand>(m_racineComposite, outf);
		std::shared_ptr<StringFindReplaceCommand> frcmd = std::make_shared<StringFindReplaceCommand>(search_seq, replac_seq, outf);
		std::shared_ptr<ChecksumCommand> cksumcmd = std::make_shared<ChecksumCommand>();

		cmdexecutor.addCommand(transcmd);
		cmdexecutor.addCommand(frcmd);
		cmdexecutor.addCommand(cksumcmd);
		cmdexecutor.executeAllCommands(audiof1);
		cmdexecutor.clearAllCommands();

		// Verifier le checksum du fichier audiof1 calcule par les commandes multiples (meme que le test 1)
		const uint64_t resultCmd = cksumcmd->get_checkSum();
		std::cerr << "m_Audiof1CheckSumRef = " << m_Audiof1CheckSumRef << "resultCmd = " << resultCmd << std::endl;
		std::cout << "COMMANDE Test 4: " << (m_Audiof1CheckSumRef == resultCmd ? "SUCCES" : "ECHEC") << std::endl;
	}
	{
		// Verifier l'application des commandes multiples au fichier audiof1
		AudioFile audiof_multicmd(m_nameAudiof_multi_cmd);
		AudioFile audiof_multicmd_ref(m_nameAudiof_multi_ref);
		bool compare = CompareFilesEqual(audiof_multicmd, audiof_multicmd_ref);
		std::cout << "COMMANDE Test 5: " << (compare ? "SUCCES" : "ECHEC") << std::endl;

		// Construire et executer une commande de calcul de checksum seule sur le fichier resultant des commandes multiples
		std::shared_ptr<ChecksumCommand> cksumcmd = std::make_shared<ChecksumCommand>();
		cmdexecutor.addCommand(cksumcmd);
		cmdexecutor.executeAllCommands(audiof_multicmd);
		cmdexecutor.clearAllCommands();
		const uint64_t resultCmd = cksumcmd->get_checkSum();
		std::cerr << "m_Audiof1CheckSumMultiCmdRef = " << m_Audiof1CheckSumMultiCmdRef << ", resultCmd = " << resultCmd << std::endl;
		std::cout << "COMMANDE Test 6: " << (m_Audiof1CheckSumMultiCmdRef == resultCmd ? "SUCCES" : "ECHEC") << std::endl;
	}
}
