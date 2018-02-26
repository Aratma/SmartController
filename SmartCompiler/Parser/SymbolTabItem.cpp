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

	printf("SymbolTabItem Destructed %p \n", this);
}

} /* namespace Parser */
