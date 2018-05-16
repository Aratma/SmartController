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
#include "Variant_t.h"

#include "SymbolTab.h"
#include "TypeSpec.h"


namespace Parser
{

using namespace std;
using namespace Util;

/*****************************************************************************/
class NodeAttribute
{
public:
	enum class EAttribKey : uint
	{
		UNKNOWN = 0,
		LINE,
		ID,
		VALUE,
	};

public:
	NodeAttribute() : _attribCode(EAttribKey::UNKNOWN) {};
	virtual ~NodeAttribute() {};

public:
	EAttribKey _attribCode;
	variant_t _attribData;
	weak_ptr<SymbolTabItem> _symTabItem; // Avoid cylic referencing of smart pointer
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
			VAR_OPD,
			INT_CONST_OPD, REAL_CONST_OPD,

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

	bool setAttribute(NodeAttribute::EAttribKey key, shared_ptr<NodeAttribute> attrib);
	pair<bool, shared_ptr<NodeAttribute> > getAttribute(NodeAttribute::EAttribKey key);

	void setTypeSpec(shared_ptr<TypeSpec> p) { m_typeSpec = p; }
	shared_ptr<TypeSpec> getTypeSpec(){ return m_typeSpec.lock(); }

public:
	virtual void Serialize( Json::Value& root);
	virtual void Deserialize( Json::Value& root);

protected:
	ENodeType m_nodeType;
	string m_nodeName;

protected:
	weak_ptr<TreeNode> m_parentNode; // Avoid cylic referencing of smart pointer

	vector<shared_ptr<TreeNode> > m_childList;

protected:
	weak_ptr<SymbolTab> m_symbolTable; // TODO: shared_ptr ???
	weak_ptr<TypeSpec> m_typeSpec; // Avoid cylic referencing of smart pointer

protected:
	map< NodeAttribute::EAttribKey, shared_ptr<NodeAttribute>> m_nodeAttributes;
};



} /* namespace Parser */

#endif /* TREENODE_H_ */
