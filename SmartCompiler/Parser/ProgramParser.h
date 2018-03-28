/******************************************************************************
 * @file ProgramParser.h
 *
 * @brief Parse a program
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/2
 *
 *
 *****************************************************************************/

#ifndef PROGRAMPARSER_H_
#define PROGRAMPARSER_H_

#include <memory>
#include "ParserST.h"

using namespace std;


namespace Parser
{

class TreeNode;
class SymbolTab;
class SymbolTabStack;

class ProgramParser : public ParserST
{
public:
	ProgramParser(shared_ptr<ScannerST> scanner, shared_ptr<SymbolTabStack> symTabStack);
	virtual ~ProgramParser();

public:
	virtual shared_ptr<TreeNode>  parse();

protected:
	shared_ptr<TreeNode>  parseProgName();
	void parseProgDecls(shared_ptr<TreeNode> parentTreeNode);
	void parseProgBody(shared_ptr<TreeNode> parentTreeNode);
};

} /* namespace Parser */

#endif /* PROGRAMPARSER_H_ */
