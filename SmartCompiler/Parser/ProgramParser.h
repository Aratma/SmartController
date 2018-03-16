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
	void parse(shared_ptr<TreeNode> parentTreeNode);

protected:
	shared_ptr<TreeNode>  parseProgName(shared_ptr<TreeNode> parentTreeNode);
	void parseProgDecls(shared_ptr<TreeNode> parentTreeNode);
	void parseProgBody(shared_ptr<TreeNode> parentTreeNode);
	void parseProgEnd();
};

} /* namespace Parser */

#endif /* PROGRAMPARSER_H_ */
