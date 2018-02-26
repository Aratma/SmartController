/******************************************************************************
 * @file SpecialSymbolToken.cpp
 *
 * @brief Implementation of class SpecialSymbolToken
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *****************************************************************************/
#include "SpecialSymbolToken.h"

using namespace std;


namespace Scanner
{

SpecialSymbolToken::SpecialSymbolToken()
{
	// TODO Auto-generated constructor stub
}

SpecialSymbolToken::~SpecialSymbolToken()
{
	// TODO Auto-generated destructor stub
}

void SpecialSymbolToken::scanToken(shared_ptr<SourceFile> srcFile)
{
	string tokenText;
	char ch = srcFile->curChar();
	m_lineNum = srcFile->getLineNum();
	m_colNum = srcFile->getColNum();

	switch(ch)
	{
	case ':':
		{
			tokenText += ch;
			ch = srcFile->nextChar();

			if (ch == '=')
			{
				tokenText += ch;
				srcFile->nextChar();

				m_tokenType = ETokenType::ASSIGN_SYM;
			}
			else
			{
				m_tokenType = ETokenType::COLON_SYM;
			}

			m_tokenText = tokenText;
		}
		break;
	case ';':
		{
			tokenText += ch;
			srcFile->nextChar();

			m_tokenType = ETokenType::SEMICOL_SYM;
			m_tokenText = tokenText;
		}
		break;
	default:
		{
			// TODO
			m_tokenText = tokenText;
			m_tokenType = ETokenType::ERROR;
			srcFile->nextChar();
		}
		break;
	}


}

} /* namespace Scanner */
