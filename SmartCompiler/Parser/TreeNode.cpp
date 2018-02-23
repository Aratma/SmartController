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
#include "TreeNode.h"

namespace Parser
{

TreeNode::TreeNode(ENodeType e, std::shared_ptr<TreeNode> p)
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


bool TreeNode::addChild(std::string name, std::shared_ptr<TreeNode> child)
{
	std::pair<std::map<std::string, std::shared_ptr<TreeNode> >::iterator,bool> ret =
				m_childMap.insert(std::pair<std::string, std::shared_ptr<TreeNode> > (name, child));

	return ret.second;
}



} /* namespace Parser */
