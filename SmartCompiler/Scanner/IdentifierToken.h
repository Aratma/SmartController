//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#ifndef IDENTIFIERTOKEN_H_
#define IDENTIFIERTOKEN_H_

#include "Token.h"

namespace Scanner
{

class IdentifierToken : public Token
{

public:
	IdentifierToken();
	virtual ~IdentifierToken();

public:
	virtual void scanToken(SourceFile& rFile);
};

} /* namespace Scanner */

#endif /* IDENTIFIERTOKEN_H_ */
