/******************************************************************************
 * @file ProgramParser.cpp
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
#include "SymbolTabStack.h"
#include "VarDeclarationParser.h"

#include "ProgramParser.h"

using namespace std;



namespace Parser
{

ProgramParser::ProgramParser(shared_ptr<ScannerST> scanner, shared_ptr<SymbolTabStack> symTabStack)
: ParserST(scanner, symTabStack)
{
}

ProgramParser::~ProgramParser()
{
}


shared_ptr<TreeNode> ProgramParser::parseProgName(shared_ptr<TreeNode> parentTreeNode)
{
	// Parser program identifier
	shared_ptr<Token> pTok = m_scanner->nextToken();

	// Create symboltable for the program
	auto progTable = make_shared<SymbolTab>(pTok->getText());
	m_symTabStack->push(progTable);

	// Create subtree node and assign symbol table info
	auto progNode = make_shared<TreeNode> (TreeNode::ENodeType::PROGRAM, pTok->getText(),  parentTreeNode);
	progNode->setSymbolTab(progTable);

	return progNode;
}

void ProgramParser::parseProgDecls(shared_ptr<TreeNode> parentTreeNode)
{
	// Parser variable declarations
	shared_ptr<Token> pTok = m_scanner->nextToken();
	if (pTok->getType() == Token::ETokenType::VAR)
	{
		shared_ptr<VarDeclarationParser> pParser = make_shared<VarDeclarationParser> (m_scanner, m_symTabStack);
		pParser->parse(parentTreeNode);

	}

}

void ProgramParser::parseProgBody(shared_ptr<TreeNode> parentTreeNode)
{

}

void ProgramParser::parseProgEnd()
{
	shared_ptr<Token> pTok = m_scanner->nextToken();
	if (pTok->getType() == Token::ETokenType::END_PROGRAM)
	{
		// TODO: error handling
	}
}

void ProgramParser::parse( shared_ptr<TreeNode> parentTreeNode)
{

	// Parser program name
	shared_ptr<TreeNode> progNode =  parseProgName(parentTreeNode);

	// Parse declarations; vars etc.
	parseProgDecls(progNode);

	// Parse program body
	parseProgBody(progNode);


	// Parse program end
	parseProgEnd();
}


} /* namespace Parser */
