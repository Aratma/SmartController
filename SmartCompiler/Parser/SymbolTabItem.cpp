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

#include "SymbolTab.h"
#include "SymbolTabItem.h"


using namespace std;



namespace Parser
{

SymbolTabItem::SymbolTabItem(EItemType e, string name, shared_ptr<SymbolTab> p)
: m_itemType (e)
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

	printf("SymbolTabItem Destructed %p \n", this);
}


void SymbolTabItem::Serialize( Json::Value& root )
{
   root["Name"] = m_itemName;
   root["Type"] = (uint)m_itemType;

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
	m_itemType = (EItemType) root.get("Type", 0).asUInt();

	// TODO: Deserialization
}

} /* namespace Parser */
