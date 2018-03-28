/******************************************************************************
 * @file SymbolTab.h
 *
 * @brief Symbol Table
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/21
 *
 * @todo move to intermediate layer
 *
 *****************************************************************************/

#ifndef SYMBOLTAB_H_
#define SYMBOLTAB_H_

#include <string>
#include <memory>
#include <map>

#include "IJsonSerializable.h"


using namespace std;


namespace Parser
{

class SymbolTabItem;

class SymbolTab : public IJsonSerializable
{
public:
	SymbolTab(string name);
	virtual ~SymbolTab();

public:
	string getName() {return m_tableName;}

public:
	pair<bool, shared_ptr<SymbolTabItem> > findLocal(string name);
	bool insert(string name, shared_ptr<SymbolTabItem> item);

public:
	virtual void Serialize( Json::Value& root);
	virtual void Deserialize( Json::Value& root);

private:
	string m_tableName;
	map<string, shared_ptr<SymbolTabItem> > m_itemMap;
};

} /* namespace Parser */

#endif /* SYMBOLTAB_H_ */
