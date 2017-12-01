#include "Parser.h"
#include "ParserState.h"

//============================================================================
void ParserStateInit::handle(Parser* p)
{
	if (p->peekNextToken(::PROGRAM_TOK))
	{
		p->setState(ParserStateProgram::getInstance());
	}
}


//============================================================================
void ParserStateProgram::handle(Parser* p)
{
	p->affirm(::PROGRAM_TOK);
	p->affirm(::ID_TOK);


	p->affirm(::ENDPROG_TOK);
}
