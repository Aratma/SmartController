/******************************************************************************
 * @file ProgramParser.h
 *
 * @brief Implementation ProgramParser
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/2
 *
 *
 *****************************************************************************/

#include "TreeNode.h"
#include "SymbolTabItem.h"
#include "SymbolTab.h"
#include "ProgramParser.h"

using namespace std;



namespace Parser
{

ProgramParser::ProgramParser(shared_ptr<ScannerST> scanner)
: ParserST(scanner)
{
}

ProgramParser::~ProgramParser()
{
	// TODO Auto-generated destructor stub
}


void ProgramParser::parseProgName(shared_ptr<SymbolTab> parentTable, shared_ptr<TreeNode> parentTreeNode)
{
	// Parser program name
	shared_ptr<Token> pTok = m_scanner->nextToken();

	// Insert into symbol table
	auto progItem = make_shared<SymbolTabItem> (SymbolTabItem::EItemType::PROGRAM, pTok->getText(), parentTable);
	bool bRet = parentTable->insert(progItem->getName(), progItem);

	// Create symbol for the program table
	auto progTable = make_shared<SymbolTab>  (pTok->getText(), parentTable);

	// Create subtree node
	auto progNode = make_shared<TreeNode> (TreeNode::ENodeType::PROGRAM, parentTreeNode);
	progNode->setSymbolTab(progTable);

}

void ProgramParser::parse(shared_ptr<SymbolTab> parentTable, shared_ptr<TreeNode> parentTreeNode)
{
	shared_ptr<Token> pTok = nullptr;

	pTok =  m_scanner->curToken();
	if (pTok->getType() == Token::ETokenType::PROGRAM)
	{

		// Parser program name
		parseProgName(parentTable, parentTreeNode);

		// Parse declarations; vars etc.

		// Parse program body


	}
	else
	{

	}

}


} /* namespace Parser */
