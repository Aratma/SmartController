//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#ifndef NUMBERTOKEN_H_
#define NUMBERTOKEN_H_

#include "Token.h"

namespace Scanner
{

class NumberToken : public Token
{
public:
	NumberToken();
	virtual ~NumberToken();

public:
	virtual void scanToken(SourceFile& rFile);
};

} /* namespace Scanner */

#endif /* NUMBERTOKEN_H_ */
