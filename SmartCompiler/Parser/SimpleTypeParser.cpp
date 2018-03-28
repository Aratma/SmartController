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

SimpleTypeParser::SimpleTypeParser(shared_ptr<ScannerST> scanner, shared_ptr<SymbolTabStack> symTabStack)
: ParserST(scanner, symTabStack)
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

	shared_ptr<Token> pTok = m_scanner->nextToken();
	string name = pTok->getText();
	pair<bool, shared_ptr<SymbolTabItem> > ret = m_symTabStack->find(name);
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
			throw std::logic_error("Not implemented!");
		}
	}
	else
	{
		// TODO: Error handling
		throw std::logic_error("Not implemented!");
	}

	return pTypeSpec;
}


} /* namespace Parser */
