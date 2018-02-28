/******************************************************************************
 * @file TreeNode.h
 *
 * @brief Class for parse tree nodes
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *******************************l**********************************************/

#ifndef TREENODE_H_
#define TREENODE_H_

#include <memory>
#include <string>
#include <map>
#include <vector>



using namespace std;


namespace Parser
{

class SymbolTab;

class TreeNode : public enable_shared_from_this<TreeNode>
{
public:

	enum class ENodeType : uint
		{
			ERROR 		= 0,

			// Code structure
			PROGRAM, FUNCTION,

			// Statements
			ASSGN_STATEM,

			// Relational operator
			EQ_OP, NOT_OP,

			// Additive operators
			ADD_OP, SUB_OP,

			// Multiplicative operators
			MUL_OP, DIV_OP,

			//Operands
			VAR_OPR,

			UNKNOWN,
		};
public:
	TreeNode(ENodeType e, string name, shared_ptr<TreeNode> p);
	virtual ~TreeNode();

public:
	bool addChild(string name, shared_ptr<TreeNode> c);

public:
	string getName() { return m_nodeName; }
	void setName(string name) { m_nodeName = name; }
	ENodeType getType() {return m_nodeType;}
	void setType(ENodeType e) {m_nodeType = e;}

	void setSymbolTab(shared_ptr<SymbolTab> t) { m_symbolTable = t;}
	shared_ptr<SymbolTab> getSymbolTab() { return m_symbolTable.lock();}

	vector <shared_ptr<TreeNode>> getChildren();

protected:
	ENodeType m_nodeType;
	string m_nodeName;

protected:
	weak_ptr<TreeNode> m_parentNode;
	map<string, shared_ptr<TreeNode> > m_childMap;

protected:
	weak_ptr<SymbolTab> m_symbolTable;
};



} /* namespace Parser */

#endif /* TREENODE_H_ */
