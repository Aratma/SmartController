/******************************************************************************
 * @file ErrorToken.cpp
 *
 * @brief Implementation of ErrorToken
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/
#include "ErrorToken.h"

using namespace std;


namespace Scanner
{

ErrorToken::ErrorToken()
{
	// TODO Auto-generated constructor stub

}

ErrorToken::~ErrorToken()
{
	// TODO Auto-generated destructor stub
}

void ErrorToken::scanToken(shared_ptr<SourceFile> srcFile)
{
	this->m_tokenType = ETokenType::ERROR;
	this->m_lineNum = srcFile->getLineNum();
	this->m_colNum = srcFile->getColNum();
	this->m_tokenText = TokenText[static_cast<size_t>(ETokenType::ERROR)];
	srcFile->nextChar();

	// TODO: Error message

}



} /* namespace Scanner */

