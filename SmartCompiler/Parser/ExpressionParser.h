/******************************************************************************
* @file ExpressionParser.cpp
*
* @brief Parse expressions
*
* @version 1.0
* @author It's me
* @date 2018/04/12
*
*
*****************************************************************************/

#ifndef EXPRESSIONPARSER_H_
#define EXPRESSIONPARSER_H_

#include <memory>
#include "StatementParser.h"


namespace Parser
{

class ExpressionParser : public StatementParser
{
public:
	ExpressionParser(shared_ptr<ParserContext> ctx);
	virtual ~ExpressionParser();

public:
	virtual shared_ptr<TreeNode> parse();

protected:
	shared_ptr<TreeNode> parsePrimaryExpression();
	shared_ptr<TreeNode> parseIdentifier();
};

} /* namespace Parser */

#endif /* EXPRESSIONPARSER_H_ */
