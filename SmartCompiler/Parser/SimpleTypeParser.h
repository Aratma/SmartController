/*
 * SimpleTypeParser.h
 *
 *  Created on: Mar 23, 2018
 *      Author: vagrant
 */
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
	SimpleTypeParser(shared_ptr<ScannerST> scanner, shared_ptr<SymbolTabStack> symTabStack);
	virtual ~SimpleTypeParser();

public:
	shared_ptr<TypeSpec> parseTypeSpec();

protected:
	virtual shared_ptr<TreeNode> parse() {};
};



} /* namespace Parser */

#endif /* SIMPLETYPEPARSER_H_ */
