/******************************************************************************
 * @file SymbolTabItem.cpp
 *
 * @brief Implementation of SymbolTabItem
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/21
 *
 *
 *****************************************************************************/
#include <iostream>
#include <string>

#include "SymbolTabItem.h"


using namespace std;


namespace Parser
{

SymbolTabItem::SymbolTabItem(EItemDefinition e, string name, shared_ptr<SymbolTab> p)
: m_itemTypeDef(e)
, m_itemName(name)
, m_parentTable(p)
{
	// TODO Auto-generated constructor stub
	printf("SymbolTabItem Constructed %p \n", this);
}

SymbolTabItem::~SymbolTabItem()
{
	// TODO Auto-generated destructor stub

	m_lineNums.clear();
	m_itemAttributes.clear();

	printf("SymbolTabItem Destructed %p \n", this);
}


void SymbolTabItem::Serialize( Json::Value& root )
{
   root["Name"] = m_itemName;
   root["Type"] = (uint)m_itemTypeDef;

   string strLines;
   for (auto it = m_lineNums.begin() ; it != m_lineNums.end(); ++it)
   {
	   strLines += to_string(*it) + ", " ;
   }

   root["Lines"] = strLines;
}

void SymbolTabItem::Deserialize( Json::Value& root )
{
	m_itemName = root.get("Name", "").asString();
	m_itemTypeDef = (EItemDefinition) root.get("Type", 0).asUInt();

	// TODO: Deserialization
}

bool SymbolTabItem::setAttribute(SymbolTabItemAttribute::EAttribKey key, SymbolTabItemAttribute attrib)
{
	return (m_itemAttributes.insert( std::make_pair( key, attrib)).second);
}

pair<bool, SymbolTabItemAttribute>  SymbolTabItem::getAttribute(SymbolTabItemAttribute::EAttribKey key)
{
	auto it = m_itemAttributes.find(key);
	if (it != m_itemAttributes.end())
	{
		return make_pair(true, it->second);
	}

    return make_pair(false, SymbolTabItemAttribute());
}

} /* namespace Parser */
