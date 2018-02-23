/******************************************************************************
 * @file Identifier.h
 *
 * @brief Class for identifier lexeme
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

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
	virtual void scanToken(std::shared_ptr<SourceFile> srcFile);
};

} /* namespace Scanner */

#endif /* IDENTIFIERTOKEN_H_ */
