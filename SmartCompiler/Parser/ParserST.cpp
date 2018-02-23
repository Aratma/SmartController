/******************************************************************************
 * @file ParserST.cpp
 *
 * @brief Parser implementation
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/
#include "TreeNode.h"
#include "SymbolTab.h"
#include "ParserST.h"



namespace Parser
{

ParserST::ParserST(std::shared_ptr<ScannerST> scanner, std::shared_ptr<SymbolTab> table, std::shared_ptr<TreeNode> treeRoot)
: m_scanner(scanner)
, m_symbolTable(table)
, m_rootNode(treeRoot)
{
}

ParserST::~ParserST()
{
}

void ParserST::parse()
{
	std::shared_ptr<Token> pTok = nullptr;

	pTok =  m_scanner->scan();

	if (pTok->getType() == Token::ETokenType::PROGRAM)
	{
l
	}
	else
	{

	}

}


} /* namespace Parser */
