/******************************************************************************
 * @file SpecialSymbolToken.h
 *
 * @brief Class for special symbol lexeme
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *****************************************************************************/

#ifndef SPECIALSYMBOLTOKEN_H_
#define SPECIALSYMBOLTOKEN_H_

#include "Token.h"

using namespace std;

namespace Scanner
{

class SpecialSymbolToken : public Token
{
public:
	SpecialSymbolToken();
	virtual ~SpecialSymbolToken();

public:
	virtual void scanToken(shared_ptr<SourceFile> srcFile);
};

} /* namespace Scanner */

#endif /* SPECIALSYMBOLTOKEN_H_ */
