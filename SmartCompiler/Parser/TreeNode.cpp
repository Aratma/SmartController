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
	m_childMap.clear();

	printf("TreeNode Destructed: %p \n", this);
}


bool TreeNode::addChild(string name, shared_ptr<TreeNode> child)
{
	pair<map<string, shared_ptr<TreeNode> >::iterator,bool> ret =
				m_childMap.insert(pair<string, shared_ptr<TreeNode> > (name, child));

	return ret.second;
}


vector<shared_ptr<TreeNode>> TreeNode::getChildren()
{
	vector<shared_ptr<TreeNode>> retval;

	for (auto const& element : m_childMap)
	{
		retval.push_back(element.second);
	}

	return retval;
}


void TreeNode::Serialize( Json::Value& root )
{
   root["Name"] = m_nodeName;
   root["Type"] = (uint)m_nodeType;

   for (auto element : m_childMap)
   {

	     string childName = element.first;
	     shared_ptr<TreeNode> nodePtr = element.second;

	     Json::Value child;
	     nodePtr->Serialize(child);

		 root["Children"][childName] = child;
   }

}

void TreeNode::Deserialize( Json::Value& root )
{
	m_nodeName = root.get("Name", "").asString();
	m_nodeType = (ENodeType) root.get("Type", 0).asUInt();

	// TODO: Children
}





} /* namespace Parser */
