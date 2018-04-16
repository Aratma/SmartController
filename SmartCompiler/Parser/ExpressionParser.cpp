
/******************************************************************************
* @file ExpressionParser.cpp
*
* @brief Parse expressions
*
* @version 1.0
* @author It's me
* @date 2018/04/12
*
*
*****************************************************************************/
#include "Token.h"
#include "TreeNode.h"
#include "StandardSymTabItems.h"
#include "ExpressionParser.h"

namespace Parser
{

ExpressionParser::ExpressionParser(shared_ptr<ParserContext> ctx)
: StatementParser(ctx)
{
	// TODO Auto-generated constructor stub
}

ExpressionParser::~ExpressionParser()
{
	// TODO Auto-generated destructor stub
}

shared_ptr<TreeNode> ExpressionParser::parse()
{
	// TODO
	throw std::logic_error("ExpressionParser::parse : Not implemented!");
}


/******************************************************************************
* @brief Parse "factor" in ST:
*   primary_expression ::=
*   constant | enumerated_value | variable | '(' expression ')'
*   | function_name '(' param_assignment {',' param_assignment} ')'
* @param None
* @return Subtree for parsed expression
*
*
*****************************************************************************/
shared_ptr<TreeNode> ExpressionParser::parsePrimaryExpression()
{
	shared_ptr<Token> curTok = m_parserCtx->_scannerST->curToken();
	switch (curTok->getType())
	{
	case Token::ETokenType::IDENTIFIER:
		{
			return parseIdentifier();
		}
		break;
	case Token::ETokenType::INT:
		{
			// Create AST Node for Assignment
			auto intNode = make_shared<TreeNode> (TreeNode::ENodeType::INT_CONST_OPR, curTok->getText(),  nullptr);

			// set value attribute for ast node
			auto nodeAttrib =  make_shared<NodeAttribute>();
			nodeAttrib->_attribCode = NodeAttribute::EAttribKey::VALUE;
			nodeAttrib->_attribData = curTok->getValue();
			intNode->setAttribute(NodeAttribute::EAttribKey::ID, nodeAttrib);
			intNode->setTypeSpec(m_parserCtx->_stdTypes->getIntTypeSpec());

			return intNode;
		}
		break;
	default:
		{
			throw std::logic_error("ExpressionParser::parsePrimaryExpression : Not implemented!");
			return nullptr;
		}
		break;
	}

	return nullptr;
}

shared_ptr<TreeNode> ExpressionParser::parseIdentifier()
{
	throw std::logic_error("ExpressionParser::parseIdentifier : Not implemented!");
}



} /* namespace Parser */
