#include "ChecksumCommand.h"
#include "AbsAudioFile.h"

void ChecksumCommand::execute(AbsAudioFile & f)
{
	// Declencher l'execution de la commande
	// A COMPLETER...
	f.accept(m_visitor);
	//f.accept(m_visitor, 
		//f.begin(), f.end())
}