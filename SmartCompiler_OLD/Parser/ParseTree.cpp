
#include "Token.h"
#include "ParseTree.h"


Node::Node()
: m_nodeType(UNKNOWN_NODE)
, m_lineNo (0)
, m_pToken(NULL)
{

}

Node::~Node()
{
	if (m_pToken != NULL)
	{
		delete m_pToken;
		m_pToken = NULL;
	}

	for ( map<string,Node*> ::iterator it = m_mapNode.begin();  it != m_mapNode.end(); ++it)
	{
		if (it->second != NULL) delete it->second;
	}

	m_mapNode.clear();
}


ParseTree::ParseTree()
: m_pNode(NULL)
{

}

ParseTree::~ParseTree()
{
	if (m_pNode != NULL)
	{
		// TODO: cleanup
	}

}

ParseTree::ParseTree(const ParseTree &t)
{
	// TODO copy constructor
}

ParseTree& ParseTree::operator=(const ParseTree &t)
{
	// TODO assignment operator
}
