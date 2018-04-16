/******************************************************************************
 * @file ParserST.h
 *
 * @brief Parser base class for the language
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

#ifndef PARSERST_H_
#define PARSERST_H_

#include <memory>

#include "ParserContext.h"
#include "Token.h"
#include "ScannerST.h"

using namespace std;
using namespace Scanner;


namespace Parser
{

class TreeNode;
class SymbolTab;
class SymbolTabStack;

class ParserST
{
public:
	ParserST(shared_ptr<ParserContext> ctx);
	virtual ~ParserST();

public:
	/** @brief Generates the parse tree and update symbol table for this parse object.
	 * 			The returned subtree is inserted into the parent tree.
	 *  @param parentTable Refers to the symbol table of the parent object below which the own ones are inserted
	 *  @param parentTable Refers to the tree node of the parent object below which the own ones are inserted
	 *  @return Subtree for parsed part.
	 */
	virtual shared_ptr<TreeNode> parse();

protected:
	shared_ptr<ParserContext> m_parserCtx;
};

} /* namespace Parser */

#endif /* PARSERST_H_ */
