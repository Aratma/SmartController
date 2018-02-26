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

class ProgramParser : public ParserST
{
public:
	ProgramParser(shared_ptr<ScannerST> scanner);
	virtual ~ProgramParser();

public:
	void parse(shared_ptr<SymbolTab> parentTable, shared_ptr<TreeNode> parentTreeNode);

protected:
	void parseProgName(shared_ptr<SymbolTab> parentTable, shared_ptr<TreeNode> parentTreeNode);
};

} /* namespace Parser */

#endif /* PROGRAMPARSER_H_ */
