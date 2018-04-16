/******************************************************************************
* @file AssignmentParser.cpp
*
* @brief Parse assignment statements
*
* @version 1.0
* @author It's me
* @date 2018/03/28
*
*
*****************************************************************************/
#include "TreeNode.h"
#include "ParserST.h"
#include "VarParser.h"

#include "AssignmentParser.h"

namespace Parser
{

AssignmentParser::AssignmentParser(shared_ptr<ParserContext> ctx)
: StatementParser(ctx)
{
	// TODO Auto-generated constructor stub
}

AssignmentParser::~AssignmentParser()
{
	// TODO Auto-generated destructor stub
}

shared_ptr<TreeNode> AssignmentParser::parse()
{
	shared_ptr<Token> pTok = m_parserCtx->_scannerST->curToken();

	// Create AST Node for Assignment
	auto assgnNode = make_shared<TreeNode> (TreeNode::ENodeType::ASSGN_STATEM, pTok->getText(),  nullptr);

	// Parse lhs (variable)
	shared_ptr<VarParser> varParser = make_shared<VarParser> (m_parserCtx);
	auto varNode = varParser->parse();

	// Add as child node to Assignment node
	assgnNode->addChild(varNode);

	// Parse rhs expression


	// Type check if assignment compatible


	return assgnNode;
}

} /* namespace Parser */
