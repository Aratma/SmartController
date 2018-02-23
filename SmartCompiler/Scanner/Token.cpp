/******************************************************************************
 * @file Token.cpp
 *
 * @brief Implementation of class Token
 *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *****************************************************************************/
#include <stdio.h>
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
	"VAR",
	"END_VAR",
	":",
	":=",
	";",
	"%",
	".",
	"UNKNOWN",
};

const std::vector<Token::ETokenType> Token::KeyWords =
{
	ETokenType::PROGRAM,
	ETokenType::END_PROGRAM,
	ETokenType::VAR,
	ETokenType::END_VAR,
};

const std::vector<Token::ETokenType> Token::SpecialSymbols =
{
	ETokenType::COLON_SYM,
	ETokenType::ASSIGN_SYM,
	ETokenType::SEMICOL_SYM,
	ETokenType::PERCENT_SYM,
	ETokenType::PERIOD_SYM,
};


Token::Token()
: m_tokenType(ETokenType::UNKNOWN)
, m_tokenText(TokenText[static_cast<std::size_t>(ETokenType::UNKNOWN)])
, m_lineNum (0)
, m_colNum(0)
{
	// TODO: logging creation
	printf("Token Constructed %p \n", this);

}

Token::~Token()
{
	// TODO: logging cleanup
	printf("Token Destructed %p \n", this);

}

void Token::scanToken(std::shared_ptr<SourceFile> srcFile)
{
	this->m_tokenType = ETokenType::UNKNOWN;
	this->m_tokenText = TokenText[static_cast<std::size_t>(ETokenType::UNKNOWN)];
	this->m_lineNum = srcFile->getLineNum();
	this->m_colNum = srcFile->getColNum();

	srcFile->nextChar();
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
