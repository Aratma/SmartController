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

shared_ptr<SymbolTab> SymbolTabStack::peek()
{
	if (m_symTabStack.empty())
		return nullptr;

	return m_symTabStack.back();
}



} /* namespace Parser */
