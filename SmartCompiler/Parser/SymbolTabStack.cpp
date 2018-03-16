/******************************************************************************
 * @file SymbolTabStack.cpp
 *
 * @brief Symbol Table Stack implementation
  *
 * @version 1.0
 * @author It's me
 * @date 2018/03/05
 *
 *
 *****************************************************************************/

#include "SymbolTabStack.h"

namespace Parser
{

SymbolTabStack::SymbolTabStack()
{
}

SymbolTabStack::~SymbolTabStack()
{
	m_symTabStack.clear();
}

void SymbolTabStack::push(shared_ptr<SymbolTab> symTab)
{
	m_symTabStack.push_back(symTab);
}

shared_ptr<SymbolTab> SymbolTabStack::pop()
{
	if (m_symTabStack.empty())
		return nullptr;

	shared_ptr<SymbolTab> t = m_symTabStack.back();
	m_symTabStack.pop_back();

	return t;
}

shared_ptr<SymbolTab> SymbolTabStack::getLocalSymTab()
{
	if (m_symTabStack.empty())
		return nullptr;

	return m_symTabStack.back();
}


pair<bool, shared_ptr<SymbolTabItem> > SymbolTabStack::findLocal(string name)
{
	if (m_symTabStack.empty())
		return make_pair(false, nullptr);

	return m_symTabStack.back()->findLocal(name);
}


pair<bool, shared_ptr<SymbolTabItem> > SymbolTabStack::find(string name)
{
	if (! m_symTabStack.empty())
	{
		vector<shared_ptr<SymbolTab> >::reverse_iterator rit = m_symTabStack.rbegin();
		for (; rit != m_symTabStack.rend(); ++rit)
		{
			auto p =  m_symTabStack.back()->findLocal(name);
			if (p.first)
			{
				return p;
			}
		}
	}

	return make_pair(false, nullptr);
}



} /* namespace Parser */
