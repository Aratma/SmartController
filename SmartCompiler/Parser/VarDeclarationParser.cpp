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
#include "Token.h"
#include "TreeNode.h"
#include "SymbolTabItem.h"
#include "SymbolTab.h"
#include "SymbolTabStack.h"
#include "SimpleTypeParser.h"

#include "VarDeclarationParser.h"

namespace Parser
{

using namespace Scanner;

VarDeclarationParser::VarDeclarationParser(shared_ptr<ParserContext> ctx)
: ParserST(ctx)
{
}

VarDeclarationParser::~VarDeclarationParser()
{
}

void VarDeclarationParser::parseVarDeclList()
{
	// Parser variable declarations separated by semicolon
	shared_ptr<Token> pTok = m_parserCtx->_scannerST->nextToken();
	while ( (pTok->getType() != Token::ETokenType::END_VAR) )
	{
		shared_ptr<SymbolTabItem> pVarDecl = parseVarDecl();

		m_parserCtx->_symTabStack->insertLocal(pVarDecl->getName(), pVarDecl);

		pTok = m_parserCtx->_scannerST->nextToken(); // Advance
	}
}

shared_ptr<SymbolTabItem>  VarDeclarationParser::parseVarDecl()
{
	// parse identifier
	shared_ptr<SymbolTabItem> pVarItem = parseIdentifier();

	// parse colon
	shared_ptr<Token> pTok = m_parserCtx->_scannerST->nextToken();
	if (pTok->getType() != Token::ETokenType::COLON_SYM)
	{
		// TODO: Error handling
		throw std::logic_error("VarDeclarationParser::parseVarDecl: Not implemented!");
	}

	// parse type specification for variable
	shared_ptr<SimpleTypeParser> pParser = make_shared<SimpleTypeParser> (m_parserCtx);
	shared_ptr<TypeSpec> typeSpec = pParser->parseTypeSpec();

	pVarItem->setTypeSpec(typeSpec);

	m_parserCtx->_scannerST->checkNextToken(Token::ETokenType::SEMICOL_SYM);

	return pVarItem;
}


shared_ptr<SymbolTabItem> VarDeclarationParser::parseIdentifier()
{
	shared_ptr<SymbolTabItem> pItem = nullptr;

	shared_ptr<Token> pTok = m_parserCtx->_scannerST->curToken();
	string name = pTok->getText();

	pair<bool, shared_ptr<SymbolTabItem> > ret = m_parserCtx->_symTabStack->findLocal(name);
	if (ret.first)
	{
		// TODO: Error identifier exists
		throw std::logic_error(" VarDeclarationParser::parseIdentifier - Not implemented!");
	}
	else
	{
		pItem =	make_shared<SymbolTabItem> (SymbolTabItem::EItemDefinition::VARIABLE, name, m_parserCtx->_symTabStack->getLocalSymTab());
		m_parserCtx->_symTabStack->insertLocal(name, pItem);
		pItem->addLines(pTok->getLine());
	}

	return pItem;
}



} /* namespace Parser */
