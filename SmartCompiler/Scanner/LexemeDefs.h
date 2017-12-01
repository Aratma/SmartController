//============================================================================
// Name        : ScannerDefs.h
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#ifndef SCANNERDEFS_H_
#define SCANNERDEFS_H_

using namespace std;

namespace Scanner
{
	enum E_LEXEME_TYPE
	{
		ERROR_LEX,
		PROG_LEX,
		ENDPROG_LEX,
		ASSIGN_LEX,
	};

	const vector<string> G_KEYW_TEXT =
	{
			"PROGRAM",
			"END_PROGRAM"
	};

	const vector<E_LEXEME_TYPE> G_KEYW_TYPE =
	{
			E_LEXEME_TYPE::PROG_LEX,
			E_LEXEME_TYPE::ENDPROG_LEX,
	};

	const vector<string> G_SPEC_SYM =
	{
			":=",
	};

	const vector<E_LEXEME_TYPE> G_SPEC_SYM_TYPE =
	{
			E_LEXEME_TYPE::ASSIGN_LEX,
	};

} /* namespace Scanner */


#endif /* SCANNERDEFS_H_ */
