/******************************************************************************
 * @file TreeNode.h
 *
 * @brief Implementation of parse tree nodes
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *l
 *****************************************************************************/

#include <stdio.h>
#include "SymbolTab.h"
#include "TreeNode.h"


using namespace std;


namespace Parser
{

TreeNode::TreeNode(ENodeType e, shared_ptr<TreeNode> p)
: m_nodeType(e)
, m_parentNode(p)
{
	// TODO logging for memory checks
	// TODO initialize other member

	printf(" TreeNode Constructed %p \n", this);
}

TreeNode::~TreeNode()
{
	// TODO logging for cleanup
	m_childMap.clear();

	printf("TreeNode Destructed: %p \n", this);
}


bool TreeNode::addChild(string name, shared_ptr<TreeNode> child)
{
	pair<map<string, shared_ptr<TreeNode> >::iterator,bool> ret =
				m_childMap.insert(pair<string, shared_ptr<TreeNode> > (name, child));

	return ret.second;
}



} /* namespace Parser */
