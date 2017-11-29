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

typedef struct Node
{
	ENodeType m_nodeType;
	int m_pLineNo;
	Token* m_pToken;

	map<string, Node*> m_pFamily;
};


class ParseTree
{
public:
	ParseTree();
	virtual ~ParseTree();

public:
	void parse();

private:
	Node* m_rootNode;
};

#endif /* PARSETREE_H_ */
