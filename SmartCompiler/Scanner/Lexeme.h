//============================================================================
// Name        : Lexeme.h
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#ifndef LEXEME_H_
#define LEXEME_H_

#include <string>
#include "LexemeDefs.h"


using namespace std;

namespace Scanner
{

	class Lexeme
	{
	public:
		Lexeme();
		virtual ~Lexeme();

	public:
		virtual void readLexeme();

	protected:
		E_LEXEME_TYPE m_lexType;
		string m_lexText;

		int m_lineNo;
		int m_colNo;
	};

} /* namespace Scanner */
#endif /* LEXEME_H_ */
