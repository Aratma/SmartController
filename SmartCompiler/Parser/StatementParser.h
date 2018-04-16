/******************************************************************************
 * @file StatementParser.h
 *
 * @brief Parse statements
  *
 * @version 1.0
 * @author It's me
 * @date 2018/03/28
 *
 *
 *****************************************************************************/
#ifndef STATEMENTPARSER_H_
#define STATEMENTPARSER_H_

#include "ParserST.h"


namespace Parser
{
class SymbolTabStack;

class StatementParser : public ParserST
{
public:
	StatementParser(shared_ptr<ParserContext> ctx);
	virtual ~StatementParser();

public:
	virtual shared_ptr<TreeNode> parse();
};

} /* namespace Parser */

#endif /* STATEMENTPARSER_H_ */
