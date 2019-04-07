///////////////////////////////////////////////////////////
//  AbsFileVisitor.h
//  Implementation of the Class AbsFileVisitor
//  Created on:      26-oct.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_AbsFileVisitor_)
#define _HEADER_AbsFileVisitor_

class AbsFileVisitor
{
public:
	AbsFileVisitor(void) {};
	virtual ~AbsFileVisitor(void) = 0 {};
	virtual AbsFileVisitor* clone(void) = 0;

	virtual void visit(const class AudioFile&) = 0;
	virtual void visit(const class MemAudioFile&) = 0;
};
#endif // !defined(_HEADER_AbsFileVisitor_)
