///////////////////////////////////////////////////////////
//  ChecksumCommand.h
//  Implementation of the Class ChecksumCommand
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_ChecksumCommand)
#define _HEADER_ChecksumCommand

#include <memory>

#include "AbsCommand.h"
#include "FileChecksumCalculator.h"

class ChecksumCommand : public AbsCommand
{
public:
	ChecksumCommand(void) {};

	// Methode permettant d'executer la commande
	virtual void execute(class AbsAudioFile&);

	uint64_t get_checkSum(void) const { return m_visitor.get_checkSum(); };

private:
	FileChecksumCalculator m_visitor;
};

#endif // !defined(_HEADER_ChecksumCommand)
