///////////////////////////////////////////////////////////
//  AbsCommand.h
//  Implementation of the Class AbsCommand
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_AbsCommand)
#define _HEADER_AbsCommand

class AbsCommand
{
public:
	AbsCommand(void) {};
	virtual ~AbsCommand(void) = 0 {};

	// Methode permettant d'executer la commande
	virtual void execute(class AbsAudioFile&) = 0;
};

#endif // !defined(_HEADER_AbsCommand)
