//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
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

ScannerST::ScannerST(SourceFile& rFile)
: m_rFile(rFile)
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
	char ch = m_rFile.curChar();
	while (isspace(ch))
	{
		ch = m_rFile.nextChar();
	}
}


std::shared_ptr<Token> ScannerST::scan()
{
	skipWhiteSpace();

	std::shared_ptr<Token> pTok =  nullptr;
	char ch = m_rFile.curChar();

	if (isdigit(ch))
	{
		pTok =  std::make_shared<NumberToken> ();
		pTok->scanToken(m_rFile);
	}
	else if (isalpha(ch) || (ch == '_') )
	{
		pTok =  std::make_shared<IdentifierToken> ();
		pTok->scanToken(m_rFile);
	}
	else if (Token::isSpecialSymbol(std::string(1,ch)) )
	{
		pTok = std::make_shared<SpecialSymbolToken> ();
		pTok->scanToken(m_rFile);
	}
	else if (EOF == ch)
	{
		pTok =  std::make_shared<EofToken> ();
		pTok->scanToken(m_rFile);
	}
	else
	{
		// TODO: Error handling
		pTok =  std::make_shared<ErrorToken> ();
		pTok->scanToken(m_rFile);
	}

	return pTok;
}




} /* namespace Scanner */
