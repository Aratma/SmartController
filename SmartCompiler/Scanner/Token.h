//============================================================================
// Name        : SourceFile.h
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

namespace Scanner
{

enum TokenType {UNKNOWN, ERROR, IDENTIFIER, PROGRAM, END_PROGRAM};
const char* const TokenText[] = {"UNKNOWN", "ERROR", "IDENTIFIER", "PROGRAM", "END_PROGRAM", };
const char* const KeyWords[] = {"" /*UNKNOWN*/, "" /*ERROR*/, "" /*IDENTIFIER*/, "PROGRAM", "END_PROGRAM", };


class Token
{
public:
	Token(TokenType type);
	virtual ~Token();

public:
/*  TODO: needed ???
	// Copy constructor - deep copy of rhs
	Token(const Token& rhs);
	// Move constructor - transfer ownership of resources
	Token(Token&& rhs);
	// Copy assignment - deep copy of rhs
	Token& operator=(const Token& rhs);
	// Move assignment - transfer ownership of resources
	Token& operator=(Token&& rhs);
*/

private:
	TokenType m_tokenType;
	std::string m_tokenText;
};


} /* namespace Scanner */

#endif /* TOKEN_H_ */
