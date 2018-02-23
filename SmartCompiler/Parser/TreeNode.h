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


namespace Parser
{


class TreeNode : public std::enable_shared_from_this<TreeNode>
{
public:

	enum class ENodeType : uint
		{
			ERROR 		= 0,

			// Code structure
			TREEROOT, PROGRAM, FUNCTION,

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
	TreeNode(ENodeType e, std::shared_ptr<TreeNode> p);
	virtual ~TreeNode();

public:
	bool addChild(std::string name, std::shared_ptr<TreeNode> c);

protected:
	ENodeType m_nodeType;
	std::weak_ptr<TreeNode> m_parentNode;
	std::map<std::string, std::shared_ptr<TreeNode> > m_childMap;
};



} /* namespace Parser */

#endif /* TREENODE_H_ */
