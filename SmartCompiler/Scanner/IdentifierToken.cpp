/******************************************************************************
 * @file Identifier.cpp
 *
 * @brief Implementation of IdentifierToken
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

#include "IdentifierToken.h"

using namespace std;


namespace Scanner
{

IdentifierToken::IdentifierToken()
{
}

IdentifierToken::~IdentifierToken()
{
}

void IdentifierToken::scanToken(shared_ptr<SourceFile> srcFile)
{
	string tokenText;

	char ch = srcFile->curChar();
	m_lineNum = srcFile->getLineNum();
	m_colNum = srcFile->getColNum();

	while (isalpha(ch) || (ch == '_') )
	{
		tokenText += ch;
		ch = srcFile->nextChar();
	}

	m_tokenText = tokenText;
	if ( isKeyWord(tokenText) )
	{
		m_tokenType = text2Type(tokenText);
	}
	else
	{
		m_tokenType = ETokenType::IDENTIFIER;
	}
}


} /* namespace Scanner */
