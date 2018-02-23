//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#include "ParserST.h"

namespace Parser
{

ParserST::ParserST(ScannerST& s)
: m_rScanner(s)
{
}

ParserST::~ParserST()
{
}

void ParserST::parse()
{
	std::shared_ptr<Token> pTok = nullptr;

	pTok =  m_rScanner.scan();

	if (pTok->getType() == Token::ETokenType::PROGRAM)
	{

	}
	else
	{

	}

}



} /* namespace Parser */
