//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#include "SpecialSymbolToken.h"

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

void SpecialSymbolToken::scanToken(SourceFile& rFile)
{
	std::string tokenText;
	char ch = rFile.curChar();
	m_lineNum = rFile.getLineNum();
	m_colNum = rFile.getColNum();

	switch(ch)
	{
	case ':':
		{
			tokenText += ch;
			ch = rFile.nextChar();

			if (ch == '=')
			{
				tokenText += ch;
				rFile.nextChar();

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
			rFile.nextChar();

			m_tokenType = ETokenType::SEMICOL_SYM;
			m_tokenText = tokenText;
		}
		break;
	default:
		{
			// TODO
			m_tokenText = tokenText;
			m_tokenType = ETokenType::ERROR;
			rFile.nextChar();
		}
		break;
	}


}

} /* namespace Scanner */
