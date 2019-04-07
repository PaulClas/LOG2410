///////////////////////////////////////////////////////////
//  TransformCommand.h
//  Implementation of the Class TransformCommand
//  Created on:      10-nov.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_TransformCommand)
#define _HEADER_TransformCommand

#include <memory>

#include "AbsCommand.h"
#include "AbsTransform.h"
#include "AbsAudioFile.h"

class TransformCommand : public AbsCommand
{
public:
	TransformCommand(std::shared_ptr<AbsTransform> t, const std::string& outFileName);
	TransformCommand(std::shared_ptr<AbsTransform> t, const std::shared_ptr<AbsAudioFile>& outFile);

	// Methode permettant d'executer la commande
	virtual void execute(class AbsAudioFile&);

	// Acces au fichier de sortie
	std::shared_ptr<AbsAudioFile>& getOutFile(void) { return m_outFile; }

private:
	std::shared_ptr<AbsTransform> m_transform;
	std::shared_ptr<AbsAudioFile> m_outFile;
};

#endif // !defined(_HEADER_TransformCommand)
