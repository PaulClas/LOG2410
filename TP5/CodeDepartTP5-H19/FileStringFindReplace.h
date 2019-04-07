///////////////////////////////////////////////////////////
//  FileStringFindReplace.h
//  Implementation of the Class FileStringFindReplace
//  Created on:      26-oct.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_FileStringFinder_)
#define _HEADER_FileStringFinder_

#include <memory>
#include <string>

#include "AbsFileVisitor.h"
#include "AbsAudioFile.h"

class FileStringFindReplace : public AbsFileVisitor
{
public:
	FileStringFindReplace(const std::vector<char>& sOrig, const std::vector<char>& sNew, const std::string& outFileName);
	FileStringFindReplace(const std::vector<char>& sOrig, const std::vector<char>& sNew, const std::shared_ptr<AbsAudioFile>& outFile);
	virtual FileStringFindReplace* clone(void);

	virtual void visit(const class AudioFile&);
	virtual void visit(const class MemAudioFile&);

private:
	void findReplace(char* p_beg, char* p_end);

	std::vector<char> m_searchString;
	std::vector<char> m_replaceString;
	std::shared_ptr<AbsAudioFile> m_outFile;
};
#endif // !defined(_HEADER_FileStringFinder_)
