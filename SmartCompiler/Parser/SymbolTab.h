
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

private:
	string m_tableName;
	weak_ptr<SymbolTab> m_parentTable;

private:
	map<string, shared_ptr<SymbolTabItem> > m_itemMap;
};

} /* namespace Parser */

#endif /* SYMBOLTAB_H_ */
