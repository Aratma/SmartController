//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#ifndef PARSETREE_H_
#define PARSETREE_H_

#include <stdio.h>
#include <map>
#include <string>

using namespace std;

class Token;

enum ENodeType
{
	UNKNOWN_NODE,
};

struct Node
{
	ENodeType m_nodeType;
	int m_lineNo;
	Token* m_pToken;

	map<string, Node*> m_mapNode;

	Node();
	~Node();
};


class ParseTree
{
public:
	ParseTree();
	virtual ~ParseTree();

public:
	ParseTree(const ParseTree &t); 				// copy constructor
	ParseTree& operator= (const ParseTree &t);	// assignment operator

public:
	void setRoot(Node* p);

	void setLeftChild(Node* p);
	void setRightChild(Node* p);
	void setMidChild(Node* p);

	void setSibling(Node* p);

	void setNodeType(ENodeType type);
	void setToken(Token* pToken);

private:
	Node* m_pNode;
};

#endif /* PARSETREE_H_ */
