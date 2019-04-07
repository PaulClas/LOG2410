#include "CommandExecutor.h"

CommandExecutor & CommandExecutor::getInstance(void)
{
	static CommandExecutor m_instance;
	return m_instance;
}

void CommandExecutor::addCommand(const std::shared_ptr<AbsCommand>& c)
{
	// Ajouter la commande a la liste des commandes
	// A COMPLETER...
}

void CommandExecutor::executeAllCommands(AbsAudioFile& f)
{
	// Executer toutes les commandes dans la liste de commandes
	// A COMPLETER...
}

void CommandExecutor::clearAllCommands(void)
{
	// Vider la liste des commandes
	// A COMPLETER...
}
