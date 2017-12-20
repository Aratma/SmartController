
#include <stdio.h>
#include <memory>

#include "Token.h"
#include "SourceFile.h"
#include "ScannerST.h"

namespace Scanner
{

ScannerST::ScannerST( SourceFile* pFile)
: m_pFile(pFile)
{
}

ScannerST::~ScannerST()
{
}

void ScannerST::curToken(Token& t)
{

}

void ScannerST::nextToken(Token& t)
{

}


std::shared_ptr<Token> ScannerST::scan()
{
	char curChar = m_pFile->curChar();

	if (isspace(curChar))
	{
		// skip whitespace
	}
	else if (isdigit(curChar))
	{

	}
	else if (isalpha(curChar))
	{

	}
	else if (EOF == curChar)
	{

	}
	else
	{

	}

	return std::make_shared<Token> (TokenType::UNKNOWN);
}




} /* namespace Scanner */
