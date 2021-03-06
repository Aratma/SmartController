/******************************************************************************
 * @file SimpleTypeParser.h
 *
 * @brief   Parser for simple types; integer,
 *
 * @version 1.0
 * @author It's me
 * @date 2018/03/26
 *
 *
 *****************************************************************************/

#ifndef SIMPLETYPEPARSER_H_
#define SIMPLETYPEPARSER_H_

#include "ParserST.h"


namespace Parser
{

class TypeSpec;

class SimpleTypeParser : public ParserST
{
public:
	SimpleTypeParser(shared_ptr<ParserContext> ctx);
	virtual ~SimpleTypeParser();

public:
	shared_ptr<TypeSpec> parseTypeSpec();

private:
	virtual shared_ptr<TreeNode> parse() {return nullptr;}
};



} /* namespace Parser */

#endif /* SIMPLETYPEPARSER_H_ */
