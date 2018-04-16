/******************************************************************************
 * @file SimpleTypeParser.cpp
 *
 * @brief Implementation SimpleTypeParser
  *
 * @version 1.0
 * @author It's me
 * @date 2018/03/26
 *
 *
 *****************************************************************************/

#include "SymbolTabItem.h"
#include "SymbolTabStack.h"
#include "TypeSpec.h"

#include "SimpleTypeParser.h"




namespace Parser
{

SimpleTypeParser::SimpleTypeParser(shared_ptr<ParserContext> ctx)
: ParserST(ctx)
{
	// TODO Auto-generated constructor stub

}

SimpleTypeParser::~SimpleTypeParser()
{
	// TODO Auto-generated destructor stub
}

shared_ptr<TypeSpec> SimpleTypeParser::parseTypeSpec()
{
	shared_ptr<TypeSpec> pTypeSpec = nullptr;

	shared_ptr<Token> pTok = m_parserCtx->_scannerST->nextToken();
	string name = pTok->getText();
	pair<bool, shared_ptr<SymbolTabItem> > ret = m_parserCtx->_symTabStack->find(name);
	if (ret.first)
	{
		shared_ptr<SymbolTabItem> pItem = ret.second;
		SymbolTabItem::EItemDefinition itemDef = pItem->getItemDefinition();
		if (itemDef == SymbolTabItem::EItemDefinition::TYPE)
		{
			pItem->addLines(pTok->getLine());
			pTypeSpec = pItem->getTypeSpec();
		}
		else
		{
			// TODO: Error handling
			throw std::logic_error("SimpleTypeParser::parseTypeSpec: Not implemented! (1)");
		}
	}
	else
	{
		// TODO: Error handling
		throw std::logic_error("SimpleTypeParser::parseTypeSpec: - Not implemented! (2)");
	}

	return pTypeSpec;
}


} /* namespace Parser */
