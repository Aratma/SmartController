/*
 * ErrorToken.h
 *
 *  Created on: Feb 13, 2018
 *      Author: vagrant
 */

#ifndef ERRORTOKEN_H_
#define ERRORTOKEN_H_

#include "Token.h"

namespace Scanner
{

class ErrorToken : public Token
{
public:
	ErrorToken();
	virtual ~ErrorToken();

public:
	virtual void scanToken(SourceFile& rFile);
};

} /* namespace Scanner */

#endif /* ERRORTOKEN_H_ */
