/******************************************************************************
 * @file SymbolTab.h
 *
 * @brief Symbol Table
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/21
 *
 *
 *****************************************************************************/

#ifndef SYMBOLTAB_H_
#define SYMBOLTAB_H_

#include <string>
#include <memory>
#include <map>


using namespace std;


namespace Parser
{

class SymbolTabItem;

class SymbolTab : public enable_shared_from_this<SymbolTab>
{
public:
	SymbolTab(string name, shared_ptr<SymbolTab>);
	virtual ~SymbolTab();

public:
	pair<bool, shared_ptr<SymbolTabItem> > findLocal(string name);
	pair<bool, shared_ptr<SymbolTabItem> > find(string name);

	bool insert(string name, shared_ptr<SymbolTabItem> item);

public:
	bool addChild(string name, shared_ptr<SymbolTab> child);

private:
	string m_tableName;
	map<string, shared_ptr<SymbolTab> > m_childTable;
	weak_ptr<SymbolTab> m_parentTable;

private:
	map<string, shared_ptr<SymbolTabItem> > m_itemMap;
};

} /* namespace Parser */

#endif /* SYMBOLTAB_H_ */