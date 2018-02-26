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


using namespace std;


namespace Scanner
{

ScannerST::ScannerST(shared_ptr<SourceFile> srcFile)
: m_srcFile(srcFile)
{
}

ScannerST::~ScannerST()
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


shared_ptr<Token> ScannerST::curToken()
{
	return m_curToken;
}


shared_ptr<Token> ScannerST::nextToken()
{
	skipWhiteSpace();

	shared_ptr<Token> pTok =  nullptr;
	char ch = m_srcFile->curChar();

	if (isdigit(ch))
	{
		pTok =  make_shared<NumberToken> ();
		pTok->scanToken(m_srcFile);
	}
	else if (isalpha(ch) || (ch == '_') )
	{
		pTok =  make_shared<IdentifierToken> ();
		pTok->scanToken(m_srcFile);
	}
	else if (Token::isSpecialSymbol(string(1,ch)) )
	{
		pTok = make_shared<SpecialSymbolToken> ();
		pTok->scanToken(m_srcFile);
	}
	else if (EOF == ch)
	{
		pTok =  make_shared<EofToken> ();
		pTok->scanToken(m_srcFile);
	}
	else
	{
		// TODO: Error handling
		pTok =  make_shared<ErrorToken> ();
		pTok->scanToken(m_srcFile);
	}

	return pTok;
}




} /* namespace Scanner */
