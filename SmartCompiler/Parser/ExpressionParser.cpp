
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
#include "SymbolTabItem.h"
#include "SymbolTabStack.h"
#include "StandardSymTabItems.h"
#include "ExpressionParser.h"

namespace Parser
{

using namespace Util;


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
* @brief Parse "term" in ST:
*   term ::= power_expression {multiply_operator power_expression}
* @param None
* @return Subtree for parsed expression
*
*
*****************************************************************************/
shared_ptr<TreeNode> ExpressionParser::parseTerm()
{
	// Create root node for Expression
	auto rootNode = parsePrimaryExpression();
	auto rootTypeSpec = rootNode->getTypeSpec();

	shared_ptr<Token> curTok = m_parserCtx->_scannerST->curToken();
	auto tokType = curTok->getType();

	while ( ( tokType ==  Token::ETokenType::MUL_SYM) ||
			 (tokType ==  Token::ETokenType::DIV_SYM)  )
	{
		TreeNode::ENodeType nodeType = (TreeNode::ENodeType)Token2NodeType[(uint)tokType][1];

		// Create operator node in AST
		auto oprNode = make_shared<TreeNode> (nodeType, curTok->getText(),  nullptr);
		oprNode->addChild(rootNode);

		// Consume operator
		curTok = m_parserCtx->_scannerST->nextToken();

		// Create root node for Expression
		auto nextExprNode = parsePrimaryExpression();
		oprNode->addChild(nextExprNode);
		auto nextExprTypeSpec = nextExprNode->getTypeSpec();

		// Now the operator node is the root node
		rootNode = oprNode;

		switch (nodeType)
		{
			case Token::ETokenType::MUL_SYM:
				{
					// both operands int -> int result

					// any one real -> real result

					// otherwise
				}
			break;
			}
			case Token::ETokenType::DIV_SYM:
			{
				// all combinations -> real result

			}
			break;
		}

		rootNode->setTypeSpec()

		curTok = m_parserCtx->_scannerST->curToken();
		tokType = curTok->getType();
	}


	return rootNode;
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
			// CONST, ENUM, function
			return parseIdentifier();
		}
		break;
	case Token::ETokenType::INT:
		{
			// Create AST Node for Assignment
			auto intNode = make_shared<TreeNode> (TreeNode::ENodeType::INT_CONST_OPD, curTok->getText(),  nullptr);

			// set value attribute for ast node
			auto nodeAttrib =  make_shared<NodeAttribute>();
			nodeAttrib->_attribCode = NodeAttribute::EAttribKey::VALUE;
			nodeAttrib->_attribData = curTok->getValue();
			intNode->setAttribute(NodeAttribute::EAttribKey::ID, nodeAttrib);
			intNode->setTypeSpec(m_parserCtx->_stdTypes->getIntTypeSpec());

			return intNode;
		}
		break;
	default: // TODO: REAL, STRING, PARENTHESIS
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
	shared_ptr<TreeNode> identNode = nullptr;
	shared_ptr<Token> curTok = m_parserCtx->_scannerST->curToken();

	// Check symbol table
	string name = curTok->getText();
	pair<bool, shared_ptr<SymbolTabItem> > ret = m_parserCtx->_symTabStack->find(name);
	if (!ret.first)
	{
		// TODO: Error handling
		throw std::logic_error("ExpressionParser::parseIdentifier : undefined identifier!");
	}

	shared_ptr<SymbolTabItem> symTabItem = ret.second;
	SymbolTabItem::EItemDefinition itemDef = symTabItem->getItemDefinition();

	switch (itemDef)
	{
		case SymbolTabItem::EItemDefinition::CONST:
		{

			auto retAttrib = symTabItem->getAttribute(SymbolTabItemAttribute::EAttribKey::CONST_VAL);
			if (!retAttrib.first)
			{
				// TODO: Error handling
				throw std::logic_error("ExpressionParser::parseIdentifier : Identifier attribute not found!");
			}

			SymbolTabItemAttribute attrib = retAttrib.second;
			shared_ptr<TypeSpec> typeSpec = symTabItem->getTypeSpec();


			if (attrib._attribData.getType() == variant_t::EVarType::INT)
			{
				// Create AST Node
				identNode = make_shared<TreeNode> (TreeNode::ENodeType::INT_CONST_OPD, name,  nullptr);

				// Set value attribute
				auto nodeAttrib =  make_shared<NodeAttribute> ();
				nodeAttrib->_attribCode = NodeAttribute::EAttribKey::VALUE;
				nodeAttrib->_attribData = attrib._attribData;
				identNode->setAttribute(NodeAttribute::EAttribKey::VALUE, nodeAttrib);
			}
			else
			{
				throw std::logic_error("ExpressionParser::parseIdentifier : 'CONST' not implemented!");
			}

		}
		break;

		case SymbolTabItem::EItemDefinition::ENUM_CONST:
		{
			throw std::logic_error("ExpressionParser::parseIdentifier : 'ENUM_CONST' not implemented!");
		}
		break;

		case SymbolTabItem::EItemDefinition::FUNCTION:
		{
			throw std::logic_error("ExpressionParser::parseIdentifier : 'FUNCTION' not implemented!");
		}
		break;

		default:
		{
			throw std::logic_error("ExpressionParser::parseIdentifier : 'default' not implemented!");
		}		break;

	}

	return identNode;
}



} /* namespace Parser */
