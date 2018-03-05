/******************************************************************************
 * @file SymbolTabStack.h
 *
 * @brief Symbol Table Stack
  *
 * @version 1.0
 * @author It's me
 * @date 2018/03/05
 *
 *
 *****************************************************************************/
#ifndef SYMBOLTABSTACK_H_
#define SYMBOLTABSTACK_H_

#include <memory>
#include <vector>

#include "SymbolTab.h"

namespace Parser
{

class SymbolTabStack
{
public:
	SymbolTabStack();
	virtual ~SymbolTabStack();

public:
	void push(shared_ptr<SymbolTab> symTab);
	shared_ptr<SymbolTab> pop();
	shared_ptr<SymbolTab> peek();

	bool isEmpty() { return m_symTabStack.empty(); }
	uint size()  {return m_symTabStack.size(); }


private:
	vector<shared_ptr<SymbolTab> > m_symTabStack;

};

} /* namespace Parser */

#endif /* SYMBOLTABSTACK_H_ */
