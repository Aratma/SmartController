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


bool ScannerST::checkNextToken(Token::ETokenType tokeType)
{
	shared_ptr<Token> pTok = nextToken();
	if (pTok->getType() == tokeType)
	{
		return true;
	}

	return false;
}


shared_ptr<Token> ScannerST::nextToken()
{
	skipWhiteSpace();

	char ch = m_srcFile->curChar();
	if (isdigit(ch))
	{
		m_curToken =  make_shared<NumberToken> ();
		m_curToken->scanToken(m_srcFile);
	}
	else if (isalpha(ch) || (ch == '_') )
	{
		m_curToken =  make_shared<IdentifierToken> ();
		m_curToken->scanToken(m_srcFile);
	}
	else if (Token::isSpecialSymbol(string(1,ch)) )
	{
		m_curToken = make_shared<SpecialSymbolToken> ();
		m_curToken->scanToken(m_srcFile);
	}
	else if (EOF == ch)
	{
		m_curToken =  make_shared<EofToken> ();
		m_curToken->scanToken(m_srcFile);
	}
	else
	{
		// TODO: Error handling
		m_curToken =  make_shared<ErrorToken> ();
		m_curToken->scanToken(m_srcFile);
	}

	return m_curToken;
}




} /* namespace Scanner */
