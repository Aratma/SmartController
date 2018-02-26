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

#include "SymbolTabItem.h"
#include "SymbolTab.h"


using namespace std;


namespace Parser
{

SymbolTab::SymbolTab(string name, shared_ptr<SymbolTab> p)
: m_tableName(name)
, m_parentTable(p)
{
	// TODO Auto-generated constructor stub

	printf("SymbolTab Constructed %p \n", this);
}

SymbolTab::~SymbolTab()
{
	// TODO Auto-generated destructor stub

	m_itemMap.clear();
	m_childTable.clear();

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

pair<bool, shared_ptr<SymbolTabItem> > SymbolTab::find(string name)
{
	pair<bool, shared_ptr<SymbolTabItem> > ret = findLocal(name);
	if (ret.second)
	{
		return ret;
	}

	if (auto p = m_parentTable.lock())
	{
		return p->find(name);
	}

	return make_pair(false, nullptr);            ;
}

bool SymbolTab::insert(string name, shared_ptr<SymbolTabItem> item)
{
	pair<map<string, shared_ptr<SymbolTabItem> >::iterator, bool> ret =
			m_itemMap.insert(pair<string, shared_ptr<SymbolTabItem> > (name, item));

	return ret.second;
}

bool SymbolTab::addChild(string name, shared_ptr<SymbolTab> child)
{
	pair<map<string, shared_ptr<SymbolTab> >::iterator,bool> ret =
			m_childTable.insert(pair<string, shared_ptr<SymbolTab> > (name, child));

	return ret.second;
}


} /* namespace Parser */
