/******************************************************************************
 * @file TreeNode.h
 *
 * @brief Implementation of parse tree nodes
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

#include <stdio.h>
#include <jsoncpp/json/json.h>

#include "SymbolTab.h"
#include "TreeNode.h"


using namespace std;


namespace Parser
{

TreeNode::TreeNode(ENodeType e, string name,  shared_ptr<TreeNode> p)
: m_nodeType(e)
, m_nodeName(name)
, m_parentNode(p)
{
	// TODO logging for memory checks
	// TODO initialize other member

	printf(" TreeNode Constructed %p \n", this);
}

TreeNode::~TreeNode()
{
	// TODO logging for cleanup
	m_childList.clear();

	printf("TreeNode Destructed: %p \n", this);
}


void TreeNode::addChild( shared_ptr<TreeNode> child)
{
	m_childList.push_back(child);
}


void TreeNode::Serialize( Json::Value& root )
{
   root["Name"] = m_nodeName;
   root["Type"] = (uint)m_nodeType;

   for (auto element : m_childList)
   {
	     Json::Value child;
	     element->Serialize(child);

		 root["Children"][element->getName().c_str()] = child;
   }

}

void TreeNode::Deserialize( Json::Value& root )
{
	m_nodeName = root.get("Name", "").asString();
	m_nodeType = (ENodeType) root.get("Type", 0).asUInt();

	// TODO: Children
}





} /* namespace Parser */
