
//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <algorithm>
#include <iterator>
#include "Token.h"


namespace Scanner
{

const std::vector<std::string> Token::TokenText =
{
	"ERROR",
	"END_OF_FILE",
	"IDENTIFIER",
	"PROGRAM",
	"END_PROGRAM",
	":",
	":=",
	";",
	"UNKNOWN",
};

const std::vector<Token::ETokenType> Token::KeyWords =
{
	ETokenType::PROGRAM,
	ETokenType::END_PROGRAM,
};

const std::vector<Token::ETokenType> Token::SpecialSymbols =
{
	ETokenType::COLON_SYM,
	ETokenType::ASSIGN_SYM,
	ETokenType::SEMICOL_SYM,
};


Token::Token()
: m_tokenType(ETokenType::UNKNOWN)
, m_tokenText(TokenText[static_cast<std::size_t>(ETokenType::UNKNOWN)])
, m_lineNum (0)
, m_colNum(0)
{
}

Token::~Token()
{
}

void Token::scanToken(SourceFile& rFile)
{
	this->m_tokenType = ETokenType::UNKNOWN;
	this->m_tokenText = TokenText[static_cast<std::size_t>(ETokenType::UNKNOWN)];
	this->m_lineNum = rFile.getLineNum();
	this->m_colNum = rFile.getColNum();

	rFile.nextChar();
}

Token::ETokenType Token::text2Type(const std::string& someText)
{

	std::vector<std::string>::const_iterator it =  std::find(Token::TokenText.begin(), Token::TokenText.end(), someText);

	if (it != Token::TokenText.end())
	{
		return Token::ETokenType(it - Token::TokenText.begin());
	}

	return ETokenType::ERROR;
}


bool Token::isKeyWord(const std::string& someText)
{
	ETokenType e = text2Type(someText);
	if (e != Token::ETokenType::ERROR)
	{
		std::vector<Token::ETokenType>::const_iterator it =  std::find(KeyWords.begin(), KeyWords.end(), e);
		if (it != KeyWords.end())
		{
			return true;
		}
	}

	return false;
}


bool Token::isSpecialSymbol(const std::string& someText)
{
	Token::ETokenType e = text2Type(someText);
	if (e != Token::ETokenType::ERROR)
	{
		std::vector<Token::ETokenType>::const_iterator it =  std::find(SpecialSymbols.begin(), SpecialSymbols.end(), e);
		if (it != SpecialSymbols.end())
		{
			return true;
		}
	}
	return false;
}



} /* namespace Scanner */
