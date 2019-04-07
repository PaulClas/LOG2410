///////////////////////////////////////////////////////////
//  StringFindReplaceCommand.h
//  Implementation of the Class StringFindCommand
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_StringFindCommand)
#define _HEADER_StringFindCommand

#include <string>

#include "AbsCommand.h"
#include "FileStringFindReplace.h"

class StringFindReplaceCommand : public AbsCommand
{
public:
	StringFindReplaceCommand( const std::vector<char>& sOrig, const std::vector<char>& sNew, const std::string& outFileName )
		: m_visitor(sOrig, sNew, outFileName) {};
	StringFindReplaceCommand(const std::vector<char>& sOrig, const std::vector<char>& sNew, const std::shared_ptr<AbsAudioFile>& outFile)
		: m_visitor(sOrig, sNew, outFile) {};

	// Methode permettant d'executer la commande
	virtual void execute(class AbsAudioFile&);

private:
	FileStringFindReplace m_visitor;
};

#endif // !defined(_HEADER_StringFindCommand)
