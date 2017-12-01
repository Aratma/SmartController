//============================================================================
// Name        : Token.h
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================
#ifndef TOKENDEFS_H_
#define TOKENDEFS_H_


#define CHAR_NULL 		'\0'
#define CHAR_UNDERSCORE '_'
#define CHAR_COLON 		':'
#define CHAR_EQUAL 		'='
#define CHAR_OPERATOR	"+-:=<>*/&"

enum ETokenType
{
	/* book-keeping tokens */
	EOF_TOK,
	ERROR_TOK,

	/* reserved words */
	PROGRAM_TOK ,
	ENDPROG_TOK,

	/* multi-character tokens */
	ID_TOK,

	/* Numbers */
	NUM_TOK,

	/* special symbols */
	ASSIGN_TOK,
};

const char* const TokenText[] =
{
		/* book-keeping tokens */
		"EOF",
		"ERROR",

		/* reserved words */
		"PROGRAM" ,
		"END_PROGRAM",

		/* multi-character tokens */
		"ID",

		/* Numbers */
		"NUM",

		/* special symbols */
		"ASSIGN",
};



#endif /* TOKENDEFS_H_ */
