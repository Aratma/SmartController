//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#ifndef PARSER_H_
#define PARSER_H_

#include "TokenDefs.h"
#include "Token.h"

class Scanner;
class ParseTree;
class ParserState;

class Parser
{
public:
	Parser();
	virtual ~Parser();

public:
	void initParser(const char* pFileName);

public:
	void parse();
	void getNextToken();
	bool peekNextToken(ETokenType type);
	void affirm(ETokenType type);

	void setState(ParserState* pState);

protected:
	void parseProgramDeclaration();

private:
	ParserState* m_pState;
	ParseTree* m_pTree;
	Scanner* m_pScanner;

	Token m_nextToken;
};

#endif /* PARSER_H_ */
