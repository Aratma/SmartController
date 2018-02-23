//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#ifndef PARSERST_H_
#define PARSERST_H_

#include "Token.h"
#include "ScannerST.h"

using namespace Scanner;


namespace Parser
{

class ParserST
{
public:
	ParserST(ScannerST& s);
	virtual ~ParserST();

public:
	void parse();

private:
	ScannerST& m_rScanner;
};

} /* namespace Parser */

#endif /* PARSERST_H_ */
