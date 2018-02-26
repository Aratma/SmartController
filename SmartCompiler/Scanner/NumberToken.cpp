/******************************************************************************
 * @file NumberToken.cpp
 *
 * @brief Implementation of NumberToken
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

#include "NumberToken.h"

using namespace std;


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

void NumberToken::scanToken(shared_ptr<SourceFile> srcFile)
{
	string tokenText;

	char ch = srcFile->curChar();
	m_lineNum = srcFile->getLineNum();
	m_colNum = srcFile->getColNum();

	while (isdigit(ch))
	{
		tokenText += ch;
		ch = srcFile->nextChar();
	}

	m_tokenText = tokenText;
	m_tokenType = ETokenType::IDENTIFIER; // TODO: Numeric types and values !!!
}


} /* namespace Scanner */
