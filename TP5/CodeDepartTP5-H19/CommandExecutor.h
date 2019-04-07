///////////////////////////////////////////////////////////
//  CommandExecutor.h
//  Implementation of the Class CommandExecutor
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_CommandExecutor)
#define _HEADER_CommandExecutor

#include <memory>
#include <list>

#include "AbsCommand.h"
#include "AbsAudioFile.h"

class CommandExecutor
{
public:
	static CommandExecutor& getInstance(void);
	void addCommand(const std::shared_ptr<AbsCommand>& c);
	void executeAllCommands( AbsAudioFile& f);
	void clearAllCommands(void);

private:
	CommandExecutor(void) {};

	std::list<std::shared_ptr<AbsCommand> > m_commandList;
};
#endif // !defined(_HEADER_CommandExecutor)
