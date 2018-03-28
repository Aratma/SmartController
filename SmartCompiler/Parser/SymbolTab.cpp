/******************************************************************************
 * @file SymbolTab.cpp
 *
 * @brief Symbol Table implementation
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/21
 *
 *
 *****************************************************************************/
#include <stdio.h>
#include <jsoncpp/json/json.h>

#include "SymbolTabItem.h"
#include "SymbolTab.h"


using namespace std;


namespace Parser
{

SymbolTab::SymbolTab(string name)
: m_tableName(name)
{
	// TODO Auto-generated constructor stub

	printf("SymbolTab Constructed %p \n", this);
}

SymbolTab::~SymbolTab()
{
	// TODO Auto-generated destructor stub

	m_itemMap.clear();

	printf("SymbolTab Destructed %p \n", this);
}

pair<bool, shared_ptr<SymbolTabItem> > SymbolTab::findLocal(string name)
{
	map<string, shared_ptr<SymbolTabItem> >::iterator it = m_itemMap.find(name);
	if (it != m_itemMap.end())
	{
		return make_pair(true, it->second);
	}

	return make_pair(false, nullptr);
}


bool SymbolTab::insert(string name, shared_ptr<SymbolTabItem> item)
{
	pair<map<string, shared_ptr<SymbolTabItem> >::iterator, bool> ret =
			m_itemMap.insert(pair<string, shared_ptr<SymbolTabItem> > (name, item));

	return ret.second;
}

void SymbolTab::Serialize( Json::Value& root )
{
   root["Name"] = m_tableName;

   for (auto it : m_itemMap)
   {
	     Json::Value child;
	     it.second->Serialize(child);

		 root["Items"][it.second->getName().c_str()] = child;
   }
}

void SymbolTab::Deserialize( Json::Value& root )
{

	// TODO: Deserialization
}



} /* namespace Parser */
