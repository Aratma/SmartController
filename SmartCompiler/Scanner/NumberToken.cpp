//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#include "NumberToken.h"

namespace Scanner
{

NumberToken::NumberToken()
{
	// TODO Auto-generated constructor stub

}

NumberToken::~NumberToken()
{
	// TODO Auto-generated destructor stub
}

void NumberToken::scanToken(SourceFile& rFile)
{
	std::string tokenText;

	char ch = rFile.curChar();
	m_lineNum = rFile.getLineNum();
	m_colNum = rFile.getColNum();

	while (isdigit(ch))
	{
		tokenText += ch;
		ch = rFile.nextChar();
	}

	m_tokenText = tokenText;
	m_tokenType = ETokenType::IDENTIFIER; // TODO: Numeric types and values !!!
}


} /* namespace Scanner */
