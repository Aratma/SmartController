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

namespace Parser
{

SymbolTab::SymbolTab(std::string name, std::shared_ptr<SymbolTab> p)
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

std::pair<bool, std::shared_ptr<SymbolTabItem> > SymbolTab::findLocal(std::string name)
{
	std::map<std::string, std::shared_ptr<SymbolTabItem> >::iterator it = m_itemMap.find(name);
	if (it != m_itemMap.end())
	{
		return std::make_pair(true, it->second);
	}

	return std::make_pair(false, nullptr);
}

std::pair<bool, std::shared_ptr<SymbolTabItem> > SymbolTab::find(std::string name)
{
	std::pair<bool, std::shared_ptr<SymbolTabItem> > ret = findLocal(name);
	if (ret.second)
	{
		return ret;
	}

	if (auto p = m_parentTable.lock())
	{
		return p->find(name);
	}

	return std::make_pair(false, nullptr);            ;
}

bool SymbolTab::insert(std::string name, std::shared_ptr<SymbolTabItem> item)
{
	std::pair<std::map<std::string, std::shared_ptr<SymbolTabItem> >::iterator, bool> ret =
			m_itemMap.insert(std::pair<std::string, std::shared_ptr<SymbolTabItem> > (name, item));

	return ret.second;
}

bool SymbolTab::addChild(std::string name, std::shared_ptr<SymbolTab> child)
{
	std::pair<std::map<std::string, std::shared_ptr<SymbolTab> >::iterator,bool> ret =
			m_childTable.insert(std::pair<std::string, std::shared_ptr<SymbolTab> > (name, child));

	return ret.second;
}


} /* namespace Parser */
