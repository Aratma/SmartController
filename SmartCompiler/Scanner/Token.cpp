#include <stdio.h>
#include <string.h>
#include "Token.h"

using namespace std;

Token::Token()
{
	initToken();
}

Token::~Token()
{
}


Token::Token(ETokenType t, const char* pStr)
{
	this->m_tokType = t;
	this->m_curLen = strlen(pStr);
	strcpy(this->m_tokText, pStr);
}

Token::Token(const Token &t)
{
	initToken(t);
}

Token& Token::operator= (const Token &t)
{
	initToken(t);

	return *this;
}

void Token::initToken()
{
	m_tokType = ::ERROR_TOK;
	m_curLen = 0;
	memset(m_tokText, CHAR_NULL, MAX_TOK_LEN);
}

void Token::initToken(const Token &t)
{
	this->m_tokType = t.m_tokType;
	this->m_curLen = t.m_curLen;
	strcpy(this->m_tokText, t.m_tokText);
}


char* Token::getTextPtr()
{
	return m_tokText;
}

bool Token::appendChar(const char* pCh)
{
	if (m_curLen < MAX_TOK_LEN-1)
	{
		m_tokText[m_curLen] = *pCh;
		m_curLen++;
		return true;
	}

	return false;
}






