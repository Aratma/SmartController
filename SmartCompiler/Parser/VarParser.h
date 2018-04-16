/******************************************************************************
 * @file VarParser.h
 *
 * @brief Parser for variables
  *
 * @version 1.0
 * @author It's me
 * @date 2018/04/11
 *
 *
 *****************************************************************************/

#ifndef VARPARSER_H_
#define VARPARSER_H_

#include <memory>
#include "StatementParser.h"


namespace Parser
{

class VarParser : public StatementParser
{
public:
	VarParser(shared_ptr<ParserContext> ctx);
	virtual ~VarParser();

public:
	virtual shared_ptr<TreeNode> parse();

};

} /* namespace Parser */


#endif /* VARPARSER_H_ */
