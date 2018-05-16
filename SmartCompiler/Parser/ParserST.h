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
#include "TreeNode.h"
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
	   uint Token2NodeType[2][2] =
	   {
	      { (uint)Scanner::Token::ETokenType::MUL_SYM, (uint)TreeNode::ENodeType::MUL_OP },
	      { (uint)Scanner::Token::ETokenType::DIV_SYM, (uint)TreeNode::ENodeType::DIV_OP },
	   };

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
