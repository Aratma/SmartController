/******************************************************************************
* @file StatementParser.cpp
*
* @brief Parse statements
*
* @version 1.0
* @author It's me
* @date 2018/03/28
*
*
*****************************************************************************/
#include "StatementParser.h"
#include "AssignmentParser.h"

namespace Parser
{

StatementParser::StatementParser(shared_ptr<ParserContext> ctx)
: ParserST(ctx)
{
	// TODO Auto-generated constructor stub
}

StatementParser::~StatementParser()
{
	// TODO Auto-generated destructor stub
}

shared_ptr<TreeNode> StatementParser::parse()
{
	shared_ptr<TreeNode> statementNode =  nullptr;
	shared_ptr<Token> pTok = nullptr;
	shared_ptr<ParserST> pParser = nullptr;

	pTok =  m_parserCtx->_scannerST->curToken();
	switch (pTok->getType())
	{
	case Token::ETokenType::IDENTIFIER:
		{	// TODO: check function call
			pParser = make_shared<AssignmentParser> (m_parserCtx);
			statementNode = pParser->parse();
		}
		break;
	default:
		{
			throw std::logic_error("StatementParser::parse : Not implemented!");
		}
		break;
	}

	return statementNode;
}

} /* namespace Parser */
