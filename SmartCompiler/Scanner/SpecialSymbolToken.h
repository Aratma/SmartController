//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#ifndef SPECIALSYMBOLTOKEN_H_
#define SPECIALSYMBOLTOKEN_H_

#include "Token.h"


namespace Scanner
{

class SpecialSymbolToken : public Token
{
public:
	SpecialSymbolToken();
	virtual ~SpecialSymbolToken();

public:
	virtual void scanToken(SourceFile& rFile);
};

} /* namespace Scanner */

#endif /* SPECIALSYMBOLTOKEN_H_ */
