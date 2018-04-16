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

ParserST::ParserST(shared_ptr<ParserContext> ctx)
: m_parserCtx(ctx)
{
}

ParserST::~ParserST()
{
}

shared_ptr<TreeNode> ParserST::parse()
{
	shared_ptr<Token> pTok = nullptr;
	shared_ptr<ParserST> pParser = nullptr;

	pTok =  m_parserCtx->_scannerST->nextToken();
	if (pTok->getType() == Token::ETokenType::PROGRAM)
	{
		pParser = make_shared<ProgramParser> (m_parserCtx);
		shared_ptr<TreeNode> progNode = pParser->parse();

		return progNode;
	}


	// TODO
	return nullptr;
}


} /* namespace Parser */
