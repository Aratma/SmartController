/******************************************************************************
 * @file TreeNode.h
 *
 * @brief Class for parse tree nodes
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 * @todo 1. move to intermediate layer
 *
 *******************************l**********************************************/

#ifndef TREENODE_H_
#define TREENODE_H_

#include <memory>
#include <string>
#include <map>
#include <vector>

#include "IJsonSerializable.h"

#include "SymbolTab.h"
#include "TypeSpec.h"


using namespace std;


namespace Parser
{

/*****************************************************************************/
struct NodeAttribute
{
public:
	enum class EAttribKey : uint
	{
		UNKNOWN = 0,
		LINE,
		ID,
		VALUE_NUM,
		VALUE_STR,
	};

public:
	NodeAttribute() : _attribCode(EAttribKey::UNKNOWN) {};
	virtual ~NodeAttribute() {};

public:
	EAttribKey _attribCode;
};


/*****************************************************************************/
struct NodeAttributeLine : public NodeAttribute
{
public:
	NodeAttributeLine() {};
	virtual ~NodeAttributeLine() {};

public:
	uint _lineNum;
};

/*****************************************************************************/
struct NodeAttributeSymTabItem : public NodeAttribute
{
public:
	NodeAttributeSymTabItem() : _symTabEntryWeakPtr{} {};
	virtual ~NodeAttributeSymTabItem() {};

public:
	weak_ptr<SymbolTabItem> _symTabEntryWeakPtr;
};


/*****************************************************************************/
struct NodeAttributeValStr : public NodeAttribute
{
public:
	NodeAttributeValStr() {};
	virtual ~NodeAttributeValStr() {};

public:
	string _val;
};


/*****************************************************************************/
struct NodeAttributeVariant : public NodeAttribute
{
public:
	NodeAttributeVariant() {};
	virtual ~NodeAttributeVariant() {};

public:
	variant_t _val;
};


/*****************************************************************************/
class TreeNode : public enable_shared_from_this<TreeNode>,  public IJsonSerializable
{
public:

	enum class ENodeType : uint
		{
			UNKNOWN 		= 0,

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

		};

public:
	TreeNode(ENodeType e, string name, shared_ptr<TreeNode> p);
	virtual ~TreeNode();

public:
	void addChild(shared_ptr<TreeNode> child);

public:
	string getName() { return m_nodeName; }
	void setName(string name) { m_nodeName = name; }
	ENodeType getType() {return m_nodeType;}
	void setType(ENodeType e) {m_nodeType = e;}

	void setSymbolTab(shared_ptr<SymbolTab> t) { m_symbolTable = t;}
	shared_ptr<SymbolTab> getSymbolTab() { return m_symbolTable.lock();}

	bool setAttribute(NodeAttribute::EAttribKey key, NodeAttribute attrib);
	pair<bool, NodeAttribute > getAttribute(NodeAttribute::EAttribKey key);

public:
	virtual void Serialize( Json::Value& root);
	virtual void Deserialize( Json::Value& root);

protected:
	ENodeType m_nodeType;
	string m_nodeName;

protected:
	weak_ptr<TreeNode> m_parentNode;
	vector<shared_ptr<TreeNode> > m_childList;

protected:
	weak_ptr<SymbolTab> m_symbolTable;

protected:
	map< NodeAttribute::EAttribKey, NodeAttribute> m_nodeAttributes;
};



} /* namespace Parser */

#endif /* TREENODE_H_ */
