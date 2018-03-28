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


shared_ptr<TreeNode> ProgramParser::parseProgName()
{
	// Parser program identifier
	shared_ptr<Token> pTok = m_scanner->nextToken();

	// Create symboltable for the program
	auto progTable = make_shared<SymbolTab>(pTok->getText());
	m_symTabStack->push(progTable);

	// Create subtree node and assign symbol table info
	auto progNode = make_shared<TreeNode> (TreeNode::ENodeType::PROGRAM, pTok->getText(),  nullptr);
	progNode->setSymbolTab(progTable);

	return progNode;
}

void ProgramParser::parseProgDecls(shared_ptr<TreeNode> parentTreeNode)
{
	// Parser variable declarations if there are any
	shared_ptr<Token> pTok = m_scanner->nextToken();
	if (pTok->getType() == Token::ETokenType::VAR)
	{
		shared_ptr<VarDeclarationParser> pParser = make_shared<VarDeclarationParser> (m_scanner, m_symTabStack);
		pParser->parseVarDeclList();
	}
}

void ProgramParser::parseProgBody(shared_ptr<TreeNode> parentTreeNode)
{
	// Parser variable declarations separated by semicolon
	shared_ptr<Token> pTok = m_scanner->nextToken();
	while ( (pTok->getType() != Token::ETokenType::END_PROGRAM) )
	{
		// TODO: parse statements

		pTok = m_scanner->nextToken();
	}
}

shared_ptr<TreeNode> ProgramParser::parse()
{
	// Parser program name
	shared_ptr<TreeNode> progNode =  parseProgName();

	// Parse declarations; vars etc.
	parseProgDecls(progNode);

	// Parse program body
	parseProgBody(progNode);

	// TODO
	// m_scanner->checkNextToken(Token::ETokenType::END_PROGRAM);

	return progNode;
}


} /* namespace Parser */
