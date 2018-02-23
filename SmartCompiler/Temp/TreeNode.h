//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#ifndef TREENODE_H_
#define TREENODE_H_

#include <memory>
#include <string>
#include <map>


namespace Parser
{


class TreeNode
{
public:

	enum class ETokenType : uint
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
	TreeNode();
	virtual ~TreeNode();

protected:
	ETokenType m_nodeType;
	std::weak_ptr<TreeNode> m_pParent;
	std::map<std::string, std::shared_ptr<TreeNode> > m_childMap;
};



} /* namespace Parser */

#endif /* TREENODE_H_ */
