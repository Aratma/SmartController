/******************************************************************************
 * @file StandardSymTabItems.h
 *
 * @brief Implementation of class StandardSymTabItems
  *
 * @version 1.0
 * @author It's me
 * @date 2018/03/20
 *
 * @todo move to intermediate layer
 *
 *****************************************************************************/
#include "TypeSpec.h"
#include "SymbolTabItem.h"
#include "SymbolTabStack.h"


#include "StandardSymTabItems.h"

namespace Parser
{

StandardSymTabItems::StandardSymTabItems()
{
	// TODO Auto-generated constructor stub
}

StandardSymTabItems::~StandardSymTabItems()
{
	// TODO Auto-generated destructor stub
}

void StandardSymTabItems::initTypeINT(shared_ptr<SymbolTabStack> symTabStack)
{
	auto intItem = make_shared<SymbolTabItem> (SymbolTabItem::EItemDefinition::TYPE, "INT", nullptr);
	symTabStack->insertLocal("INT", intItem);

	m_intTypeSpec = make_shared<TypeSpec> (TypeSpec::ETypeSpecForm::SCALAR);
	m_intTypeSpec->setSymbolTabItemId(intItem);

	intItem->setItemDefinition(SymbolTabItem::EItemDefinition::TYPE);
	intItem->setTypeSpec(m_intTypeSpec);

	m_intTabItemID = intItem;
}


void StandardSymTabItems::initTypes(shared_ptr<SymbolTabStack> symTabStack)
{
	initTypeINT(symTabStack);

	// TODO: other types and standard functions
}


void StandardSymTabItems::Serialize( Json::Value& root )
{
	// INT
	root["Name"] = "INT";
	Json::Value child;
	m_intTypeSpec->Serialize(child);
	root["TypeSpec"] = child;

   // TODO: Attributes and symbol tabe item refrerence
}

void StandardSymTabItems::Deserialize( Json::Value& root )
{
	throw std::logic_error("StandardSymTabItems::Deserialize : Not implemented!");

}



} /* namespace Parser */
