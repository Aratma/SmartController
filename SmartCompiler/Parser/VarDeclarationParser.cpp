/******************************************************************************
 * @file VarDeclarationParser.cpp
 *
 * @brief Implementation VarDeclarationParser
  *
 * @version 1.0
 * @author It's me
 * @date 2018/03/07
 *
 *
 *****************************************************************************/

#include "TreeNode.h"
#include "SymbolTabItem.h"
#include "SymbolTab.h"
#include "SymbolTabStack.h"

#include "VarDeclarationParser.h"

namespace Parser
{

VarDeclarationParser::VarDeclarationParser(shared_ptr<ScannerST> scanner, shared_ptr<SymbolTabStack> symTabStack)
: ParserST(scanner, symTabStack)
{
}

VarDeclarationParser::~VarDeclarationParser()
{
}

void VarDeclarationParser::parse(shared_ptr<TreeNode> parentTreeNode)
{
	// Parser variable declarations separated by semicolon
	shared_ptr<Token> pTok = m_scanner->curToken();
	while ( (pTok->getType() != Token::ETokenType::END_VAR) )
	{
		parseVarDeclList(parentTreeNode);

		pTok = m_scanner->curToken(); // Advance previous
	}

}

void VarDeclarationParser::parseVarDeclList(shared_ptr<TreeNode> parentTreeNode)
{
	// parse identifier

	// parse colon

	// parse type specification for variable
}




} /* namespace Parser */
