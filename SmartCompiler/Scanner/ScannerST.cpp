/******************************************************************************
 * @file SourceFile.cpp
 *
 * @brief Implementation of the Scanner class
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

#include <stdio.h>
#include <memory>

#include "SourceFile.h"
#include "Token.h"
#include "IdentifierToken.h"
#include "NumberToken.h"
#include "SpecialSymbolToken.h"
#include "ErrorToken.h"
#include "EofToken.h"

#include "ScannerST.h"

namespace Scanner
{

ScannerST::ScannerST(std::shared_ptr<SourceFile> srcFile)
: m_srcFile(srcFile)
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

void ScannerST::skipWhiteSpace()
{
	char ch = m_srcFile->curChar();
	while (isspace(ch))
	{
		ch = m_srcFile->nextChar();
	}
}

std::shared_ptr<Token> ScannerST::scan()
{
	skipWhiteSpace();

	std::shared_ptr<Token> pTok =  nullptr;
	char ch = m_srcFile->curChar();

	if (isdigit(ch))
	{
		pTok =  std::make_shared<NumberToken> ();
		pTok->scanToken(m_srcFile);
	}
	else if (isalpha(ch) || (ch == '_') )
	{
		pTok =  std::make_shared<IdentifierToken> ();
		pTok->scanToken(m_srcFile);
	}
	else if (Token::isSpecialSymbol(std::string(1,ch)) )
	{
		pTok = std::make_shared<SpecialSymbolToken> ();
		pTok->scanToken(m_srcFile);
	}
	else if (EOF == ch)
	{
		pTok =  std::make_shared<EofToken> ();
		pTok->scanToken(m_srcFile);
	}
	else
	{
		// TODO: Error handling
		pTok =  std::make_shared<ErrorToken> ();
		pTok->scanToken(m_srcFile);
	}

	return pTok;
}




} /* namespace Scanner */
