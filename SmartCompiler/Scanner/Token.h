//============================================================================
// Name        : Token.h
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#ifndef TOKEN_H_
#define TOKEN_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <type_traits>

#include "SourceFile.h"

namespace Scanner
{


class Token
{

public:
	enum class ETokenType : uint
	{
		ERROR 		= 0,
		END_OF_FILE,
		IDENTIFIER,
		PROGRAM,
		END_PROGRAM,
		COLON_SYM,
		ASSIGN_SYM,
		SEMICOL_SYM,
		UNKNOWN,
	};

	static const std::vector<std::string> TokenText;
	static const std::vector<ETokenType> KeyWords;
	static const std::vector<ETokenType> SpecialSymbols;

public:
	Token();
	virtual ~Token();

public:
	virtual void scanToken(SourceFile& rFile);

public:
	static ETokenType text2Type(const std::string& someText);
	static bool isKeyWord(const std::string& someText);
	static bool isSpecialSymbol(const std::string& someText);

public:
	ETokenType getType() {return m_tokenType;}
	std::string getText() { return m_tokenText;}
	int getLine() {return m_lineNum; }
	int getCol() { return m_colNum; }

protected:
	ETokenType m_tokenType;
	std::string m_tokenText;
	int m_lineNum;
	int m_colNum;
};


} /* namespace Scanner */

#endif /* TOKEN_H_ */
