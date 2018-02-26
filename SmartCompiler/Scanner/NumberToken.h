/******************************************************************************
 * @file NumberToken.h
 *
 * @brief Class for number lexeme
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

#ifndef NUMBERTOKEN_H_
#define NUMBERTOKEN_H_

#include "Token.h"

using namespace std;


namespace Scanner
{

class NumberToken : public Token
{
public:
	NumberToken();
	virtual ~NumberToken();

public:
	virtual void scanToken(shared_ptr<SourceFile> srcFile);
};

} /* namespace Scanner */

#endif /* NUMBERTOKEN_H_ */
