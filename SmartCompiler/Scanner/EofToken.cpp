/******************************************************************************
 * @file EofToken.cpp
 *
 * @brief Implementation class for EofToken
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/
#include "EofToken.h"

using namespace std;



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

void EofToken::scanToken(shared_ptr<SourceFile> srcFile)
{
	this->m_tokenType = ETokenType::END_OF_FILE;
	this->m_lineNum = srcFile->getLineNum();
	this->m_colNum = srcFile->getColNum();
	this->m_tokenText = TokenText[static_cast<size_t>(ETokenType::END_OF_FILE)];
}

} /* namespace Scanner */
