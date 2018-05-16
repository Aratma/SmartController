/******************************************************************************
 * @file TypeChecker.h
 *
 * @brief Check type compatibility
 *
 *
 * @version 1.0
 * @author It's me
 * @date 2018/04/19
 *
 * @todo 1. move to intermediate layer
 *
 *****************************************************************************/

#ifndef TYPECHECKER_H_
#define TYPECHECKER_H_

namespace Parser
{

class TypeChecker
{
public:
	TypeChecker();
	virtual ~TypeChecker();

public:
	bool isInt(TypeSpec spec);

};



} /* namespace Parser */

#endif /* TYPECHECKER_H_ */
