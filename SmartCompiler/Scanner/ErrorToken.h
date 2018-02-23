/******************************************************************************
 * @file ErrorToken.h
 *
 * @brief Class for error handling while scanning
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/
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
	virtual void scanToken(std::shared_ptr<SourceFile> srcFile);
};

} /* namespace Scanner */

#endif /* ERRORTOKEN_H_ */
