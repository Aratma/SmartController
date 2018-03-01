/******************************************************************************
 * @file SymbolTabItem.h
 *
 * @brief Symbol Table Item
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/21
 *
 *
 *****************************************************************************/

#ifndef SYMBOLTABITEM_H_
#define SYMBOLTABITEM_H_

#include <string>
#include <list>
#include <memory>

#include "IJsonSerializable.h"

using namespace std;


namespace Parser
{

class SymbolTab;


class SymbolTabItem : public enable_shared_from_this<SymbolTabItem>, public IJsonSerializable
{
public:
	enum class EItemType : uint
		{
			ERROR 		= 0,
			PROGRAM,
			UNKNOWN,
		};

public:
	SymbolTabItem(EItemType e,  string name, shared_ptr<SymbolTab> p);
	virtual ~SymbolTabItem();

public:
	void setItemType(EItemType e) { m_itemType = e; }
	EItemType getItemType() { return m_itemType; }

	void setName(string name) {m_itemName = name;}
	string getName()  { return m_itemName;}

	void setParent(shared_ptr<SymbolTab> p) { m_parentTable = p;}
	shared_ptr<SymbolTab> getParent() {return m_parentTable.lock();}

	void addLines(int l) { m_lineNums.push_back(l);}
	list<int> getLines() { return m_lineNums; }

public:
	virtual void Serialize( Json::Value& root);
	virtual void Deserialize( Json::Value& root);

private:
	EItemType m_itemType;
	string m_itemName;
	weak_ptr<SymbolTab> m_parentTable;
	list<int> m_lineNums;
};

} /* namespace Parser */

#endif /* SYMBOLTABITEM_H_ */
