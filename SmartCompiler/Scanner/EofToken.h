/*
 * EofToken.h
 *
 *  Created on: Feb 13, 2018
 *      Author: vagrant
 */

#ifndef EOFTOKEN_H_
#define EOFTOKEN_H_


#include "Token.h"

namespace Scanner
{

class EofToken : public Token
{
public:
	EofToken();
	virtual ~EofToken();

public:
	virtual void scanToken(SourceFile& rFile);

};

} /* namespace Scanner */

#endif /* EOFTOKEN_H_ */
