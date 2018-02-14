/*
 * ErrorToken.cpp
 *
 *  Created on: Feb 13, 2018
 *      Author: vagrant
 */

#include "ErrorToken.h"

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

void ErrorToken::scanToken(SourceFile& rFile)
{
	this->m_tokenType = ETokenType::ERROR;
	this->m_lineNum = rFile.getLineNum();
	this->m_colNum = rFile.getColNum();
	this->m_tokenText = TokenText[static_cast<std::size_t>(ETokenType::ERROR)];
	rFile.nextChar();

	// TODO: Error message

}



} /* namespace Scanner */

