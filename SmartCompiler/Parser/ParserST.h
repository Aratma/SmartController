/******************************************************************************
 * @file ParserST.h
 *
 * @brief Parser base class for the language
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

#ifndef PARSERST_H_
#define PARSERST_H_

#include "Token.h"
#include "ScannerST.h"

using namespace Scanner;


namespace Parser
{

class SymbolTab;

class ParserST
{
public:
	ParserST(std::shared_ptr<ScannerST> scanner,
			std::shared_ptr<SymbolTab> table,
			std::shared_ptr<TreeNode> treeRoot);

	virtual ~ParserST();

public:
	/** @brief Generates the parse tree and symbol table.
	 *  @param None
	 *  @return Void.
	 */
	void parse();

private:
	std::shared_ptr<ScannerST> m_scanner;
	std::shared_ptr<SymbolTab> m_symbolTable;
	std::shared_ptr<TreeNode> m_rootNode;
};

} /* namespace Parser */

#endif /* PARSERST_H_ */
