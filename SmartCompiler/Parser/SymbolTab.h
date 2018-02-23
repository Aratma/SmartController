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


namespace Parser
{

class SymbolTabItem;

class SymbolTab : public std::enable_shared_from_this<SymbolTab>
{
public:
	SymbolTab(std::string name, std::shared_ptr<SymbolTab>);
	virtual ~SymbolTab();

public:
	std::pair<bool, std::shared_ptr<SymbolTabItem> > findLocal(std::string name);
	std::pair<bool, std::shared_ptr<SymbolTabItem> > find(std::string name);

	bool insert(std::string name, std::shared_ptr<SymbolTabItem> item);

public:
	bool addChild(std::string name, std::shared_ptr<SymbolTab> child);

private:
	std::string m_tableName;
	std::map<std::string, std::shared_ptr<SymbolTab> > m_childTable;
	std::weak_ptr<SymbolTab> m_parentTable;

private:
	std::map<std::string, std::shared_ptr<SymbolTabItem> > m_itemMap;
};

} /* namespace Parser */

#endif /* SYMBOLTAB_H_ */
