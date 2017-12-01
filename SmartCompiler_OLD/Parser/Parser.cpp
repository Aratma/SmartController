#include "TokenDefs.h"
#include "Scanner.h"
#include "ParserState.h"
#include "ParseTree.h"
#include "Parser.h"


Parser::Parser()
: m_pState(NULL)
, m_pTree(NULL)
, m_pScanner(NULL)
{
}

Parser::~Parser()
{
	if (m_pScanner != NULL)
	{
		delete m_pScanner;
		m_pScanner = NULL;
	}

	if (m_pTree != NULL)
	{
		delete m_pTree;
		m_pTree = NULL;
	}
}


void Parser::initParser(const char* pFileName)
{
	if (m_pTree == NULL)
	{
		m_pTree = new ParseTree();
	}

	if (m_pScanner == NULL)
	{
		m_pScanner = new Scanner();
	}

	m_pScanner->initScanner(pFileName);
}


void Parser::setState(ParserState* pState)
{
	m_pState = pState;
}


void Parser::parse()
{
	// Always start with initial state
	m_pState = ParserStateInit::getInstance();
	m_pState->handle(this);
}


void Parser::affirm(ETokenType type)
{
	if (type == m_nextToken.getType())
	{
		m_pScanner->getNextToken(m_nextToken);
	}
	else
	{
		// TODO error state
	}
}

void Parser::getNextToken()
{

	m_pScanner->getNextToken(m_nextToken);
}


bool Parser::peekNextToken(ETokenType type)
{
	if (m_nextToken.getType() == type)
	{
		return true;
	}

	return false;
}




//============================================================================
// program_declaration ::=
//					'PROGRAM' program_type_name
//					{ io_var_declarations | other_var_declarations
//					| located_var_declarations | program_access_decls }
//					function_block_body
//					'END_PROGRAM'
//============================================================================
void Parser::parseProgramDeclaration()
{

}

