/******************************************************************************
 * @file EofToken.h
 *
 * @brief Class for handling EOF
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/
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
	virtual void scanToken(std::shared_ptr<SourceFile> srcFile);

};

} /* namespace Scanner */

#endif /* EOFTOKEN_H_ */
