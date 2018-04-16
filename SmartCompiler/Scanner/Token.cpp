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

using namespace std;

namespace Scanner
{

const vector<string> Token::TokenText =
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
	"INT",
	"REAL",
	"UNKNOWN",
};

const vector<Token::ETokenType> Token::KeyWords =
{
	ETokenType::PROGRAM,
	ETokenType::END_PROGRAM,
	ETokenType::VAR,
	ETokenType::END_VAR,
	ETokenType::INT,
	ETokenType::REAL,
};

const vector<Token::ETokenType> Token::SpecialSymbols =
{
	ETokenType::COLON_SYM,
	ETokenType::ASSIGN_SYM,
	ETokenType::SEMICOL_SYM,
	ETokenType::PERCENT_SYM,
	ETokenType::PERIOD_SYM,
};


Token::Token()
: m_tokenType(ETokenType::UNKNOWN)
, m_tokenText(TokenText[static_cast<size_t>(ETokenType::UNKNOWN)])
, m_lineNum (0)
, m_colNum(0)
, m_value(0)
{
	// TODO: logging creation
	printf("Token Constructed %p \n", this);

}

Token::~Token()
{
	// TODO: logging cleanup
	printf("Token Destructed %p \n", this);

}

void Token::scanToken(shared_ptr<SourceFile> srcFile)
{
	this->m_tokenType = ETokenType::UNKNOWN;
	this->m_tokenText = TokenText[static_cast<size_t>(ETokenType::UNKNOWN)];
	this->m_lineNum = srcFile->getLineNum();
	this->m_colNum = srcFile->getColNum();

	srcFile->nextChar();
}

Token::ETokenType Token::text2Type(const string& someText)
{

	vector<string>::const_iterator it =  find(Token::TokenText.begin(), Token::TokenText.end(), someText);

	if (it != Token::TokenText.end())
	{
		return Token::ETokenType(it - Token::TokenText.begin());
	}

	return ETokenType::ERROR;
}


bool Token::isKeyWord(const string& someText)
{
	ETokenType e = text2Type(someText);
	if (e != Token::ETokenType::ERROR)
	{
		vector<Token::ETokenType>::const_iterator it =  find(KeyWords.begin(), KeyWords.end(), e);
		if (it != KeyWords.end())
		{
			return true;
		}
	}

	return false;
}


bool Token::isSpecialSymbol(const string& someText)
{
	Token::ETokenType e = text2Type(someText);
	if (e != Token::ETokenType::ERROR)
	{
		vector<Token::ETokenType>::const_iterator it =  find(SpecialSymbols.begin(), SpecialSymbols.end(), e);
		if (it != SpecialSymbols.end())
		{
			return true;
		}
	}
	return false;
}



} /* namespace Scanner */
