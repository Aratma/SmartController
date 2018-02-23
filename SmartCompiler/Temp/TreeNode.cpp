//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <stdio.h>
#include "TreeNode.h"

namespace Parser
{

TreeNode::TreeNode()
{
	// TODO logging for memory checks

	printf("Constructed: %p \n", this);
}

TreeNode::~TreeNode()
{
	// TODO logging for cleanup
	m_childMap.clear();

	printf("Destructed: %p \n", this);
}




} /* namespace Parser */
