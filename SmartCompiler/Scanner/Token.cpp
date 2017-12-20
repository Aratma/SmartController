#include "SourceFile.h"
#include "Token.h"


namespace Scanner
{

Token::Token(TokenType type)
{
	m_tokenType = type;
	m_tokenText = TokenText[type];
}

Token::~Token()
{

}




/* TODO: Needed ??? *****************************************************

// Copy constructor - deep copy of rhs
Token::Token(const Token& rhs)
{
	m_tokenType = rhs.m_tokenType;
	m_tokenText = rhs.m_tokenText;
}

// Move constructor - transfer ownership of resources
Token::Token(Token&& rhs)
{
	m_tokenType = rhs.m_tokenType;
	m_tokenText = rhs.m_tokenText;

	rhs.m_tokenType = TokenType::UNKNOWN;
	rhs.m_tokenText = TokenText[TokenType::UNKNOWN];
}


// Copy assignment - deep copy of rhs
Token& Token::operator=(const Token& rhs)
{
	// Self assignment detection
	if (&rhs == this)
		return *this;

	// Release any resource we're holding

	// Then copy the resource
	m_tokenType = rhs.m_tokenType;
	m_tokenText = rhs.m_tokenText;
}


// Move assignment - transfer ownership of resources
Token& Token::operator=(Token&& rhs)
{
	// Self assignment detection
	if (&rhs == this)
		return *this;

	// Release any resource we're holding

	// Then transfer ownership
	m_tokenType = rhs.m_tokenType;
	m_tokenText = rhs.m_tokenText;

	rhs.m_tokenType = TokenType::UNKNOWN;
	rhs.m_tokenText = TokenText[TokenType::UNKNOWN];
}
*************************************************************************/


} /* namespace Scanner */
