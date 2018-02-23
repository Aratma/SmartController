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
#include <vector>
#include <memory>

namespace Parser
{

class SymbolTab;


class SymbolTabItem : public std::enable_shared_from_this<SymbolTabItem>
{
public:
	SymbolTabItem(std::string name, std::shared_ptr<SymbolTab> p);
	virtual ~SymbolTabItem();

public:
	void setName(std::string name) {m_itemName = name;}
	std::string getName()  { return m_itemName;}

	void setParent(std::shared_ptr<SymbolTab> p) { m_parentTable = p;}
	std::shared_ptr<SymbolTab> getParent() {return m_parentTable.lock();}

	void addLines(int l) { m_lineNums.push_back(l);}
	std::vector<int> getLines() { return m_lineNums; }

private:
	std::string m_itemName;
	std::weak_ptr<SymbolTab> m_parentTable;
	std::vector<int> m_lineNums;
};

} /* namespace Parser */

#endif /* SYMBOLTABITEM_H_ */
