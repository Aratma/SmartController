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
#include "SymbolTabStack.h"
#include "ProgramParser.h"

#include "ParserST.h"


using namespace std;


namespace Parser
{

ParserST::ParserST(shared_ptr<ScannerST> scanner, shared_ptr<SymbolTabStack> symTabStack)
: m_scanner(scanner)
, m_symTabStack (symTabStack)
{
}

ParserST::~ParserST()
{
}



void ParserST::parse(shared_ptr<TreeNode> parentTreeNode)
{
	shared_ptr<Token> pTok = nullptr;
	shared_ptr<ParserST> pParser = nullptr;

	pTok =  m_scanner->nextToken();
	if (pTok->getType() == Token::ETokenType::PROGRAM)
	{
		pParser = make_shared<ProgramParser> (m_scanner, m_symTabStack);
		pParser->parse(parentTreeNode);

	}
	else
	{

	}
}


} /* namespace Parser */
