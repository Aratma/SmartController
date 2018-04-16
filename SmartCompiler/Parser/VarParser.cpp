/******************************************************************************
 * @file VarParser.cpp
 *
 * @brief Parser for variables implementation
  *
 * @version 1.0
 * @author It's me
 * @date 2018/04/11
 *
 *
 *****************************************************************************/

#include "SymbolTabItem.h"
#include "SymbolTabStack.h"
#include "TreeNode.h"

#include "VarParser.h"



namespace Parser
{

VarParser::VarParser(shared_ptr<ParserContext> ctx)
: StatementParser(ctx)
{
	// TODO Auto-generated constructor stub

}

VarParser::~VarParser()
{
	// TODO Auto-generated destructor stub
}



shared_ptr<TreeNode> VarParser::parse()
{
	shared_ptr<Token> pTok = m_parserCtx->_scannerST->curToken();
	string name = pTok->getText();

	// Find the variable in the symbol table
	pair<bool, shared_ptr<SymbolTabItem> > ret = m_parserCtx->_symTabStack->find(name);

	if (!ret.first)
	{
		// TODO: Error the variable not defined
		throw std::logic_error("VarParser::parse: - Not implemented!");
	}

	shared_ptr<SymbolTabItem> pItem = ret.second;
	SymbolTabItem::EItemDefinition itemDef = pItem->getItemDefinition();


	if (itemDef != SymbolTabItem::EItemDefinition::VARIABLE)
	{
		// TODO: Error since invalid identifier
		throw std::logic_error("SimpleTypeParser::parseTypeSpec: - Not implemented! (2)");
	}

	pItem->addLines(pTok->getLine());

	// Create AST Node for Assignment
	auto assgnNode = make_shared<TreeNode> (TreeNode::ENodeType::ASSGN_STATEM, pTok->getText(),  nullptr);

	// set node attribute for ast node
	auto nodeAttrib =  make_shared<NodeAttribute> ();
	nodeAttrib->_attribCode = NodeAttribute::EAttribKey::ID;
	nodeAttrib->_symTabItem = pItem;
	assgnNode->setAttribute(NodeAttribute::EAttribKey::ID, nodeAttrib);

	// set type specification
	auto pTypeSpec = pItem->getTypeSpec();
	assgnNode->setTypeSpec(pTypeSpec);


	return assgnNode;
}



} /* namespace Parser */


