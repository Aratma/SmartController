//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#include "IdentifierToken.h"

namespace Scanner
{

IdentifierToken::IdentifierToken()
{
}

IdentifierToken::~IdentifierToken()
{
}

void IdentifierToken::scanToken(SourceFile& rFile)
{
	std::string tokenText;

	char ch = rFile.curChar();
	m_lineNum = rFile.getLineNum();
	m_colNum = rFile.getColNum();

	while (isalpha(ch) || (ch == '_') )
	{
		tokenText += ch;
		ch = rFile.nextChar();
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
