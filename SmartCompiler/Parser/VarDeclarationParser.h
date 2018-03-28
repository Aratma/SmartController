/******************************************************************************
 * @file VarDeclarationParser.h
 *
 * @brief Parser for variable declartions
  *
 * @version 1.0
 * @author It's me
 * @date 2018/03/07
 *
 *
 *****************************************************************************/
#ifndef VARDECLARATIONPARSER_H_
#define VARDECLARATIONPARSER_H_

#include <memory>
#include "ParserST.h"


namespace Parser
{

class TreeNode;
class SymbolTab;
class SymbolTabStack;


class VarDeclarationParser : public ParserST
{
public:
	VarDeclarationParser(shared_ptr<ScannerST> scanner, shared_ptr<SymbolTabStack> symTabStack);
	virtual ~VarDeclarationParser();

public:
	void parseVarDeclList();

protected:
	shared_ptr<SymbolTabItem> parseVarDecl();
	shared_ptr<SymbolTabItem> parseIdentifier();

private:
	virtual shared_ptr<TreeNode> parse() {return nullptr;}
};

} /* namespace Parser */

#endif /* VARDECLARATIONPARSER_H_ */
