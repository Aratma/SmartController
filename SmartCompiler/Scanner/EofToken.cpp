/*
 * EofToken.cpp
 *
 *  Created on: Feb 13, 2018
 *      Author: vagrant
 */

#include "EofToken.h"

namespace Scanner
{

EofToken::EofToken()
{
	// TODO Auto-generated constructor stub

}

EofToken::~EofToken()
{
	// TODO Auto-generated destructor stub
}

void EofToken::scanToken(SourceFile& rFile)
{
	this->m_tokenType = ETokenType::END_OF_FILE;
	this->m_lineNum = rFile.getLineNum();
	this->m_colNum = rFile.getColNum();
	this->m_tokenText = TokenText[static_cast<std::size_t>(ETokenType::END_OF_FILE)];
}

} /* namespace Scanner */
