#include "Token.h"
#include "SourceFile.h"
#include "ScannerState.h"
#include "Scanner.h"


void ScannerStateDone::handle(Scanner* s, Token& nextToken)
{
	/*

     if (state == DONE)
     { tokenString[tokenStringIndex] = '\0';
       if (currentToken == ID)
         currentToken = reservedLookup(tokenString);
     }

	 */
}


void ScannerStateInNum::handle(Scanner* s, Token& nextToken)
{
	char ch = s->getSourceFile()->nextCol();

	if (!isdigit(ch))
	{
		s->getSourceFile()->prevCol();
		nextToken.setType(::NUM_TOK);

		s->setState(ScannerStateDone::getInstance());
	}
	else
	{
		nextToken.appendChar(&ch);
	}
}


void ScannerStateInID::handle(Scanner* s, Token& nextToken)
{
	char ch = s->getSourceFile()->nextCol();

	if ( isalpha(ch) || (ch == CHAR_UNDERSCORE) )
	{
		nextToken.appendChar(&ch);
	}
	else
	{
		s->getSourceFile()->prevCol(); // Backtrack
		ETokenType type = s->isKeyword(nextToken.getTextPtr());
		if (type != ERROR_TOK)
		{
			nextToken.setType(type);
		}
		else
		{
			nextToken.setType(::ID_TOK);
		}

		s->setState(ScannerStateDone::getInstance());
	}

}

void ScannerStateChOperator::handle(Scanner* s, Token& nextToken)
{
	char ch = s->getSourceFile()->nextCol();

	if (ch == CHAR_COLON)
	{
		nextToken.appendChar(&ch);

		ch = s->getSourceFile()->nextCol();
		if (ch == CHAR_EQUAL)
		{
			nextToken.setType(::ASSIGN_TOK);
			nextToken.appendChar(&ch);
			s->setState(ScannerStateDone::getInstance());
		}
		else
		{
			nextToken.setType(::ERROR_TOK);
		}
	}
	else
	{
		nextToken.setType(::ERROR_TOK);
	}

}

void ScannerStateInit::handle(Scanner* s, Token& nextToken)
{
	const char ch = s->getSourceFile()->nextCol();

	if (isdigit(ch))
	{
		s->setState(ScannerStateInNum::getInstance());
		nextToken.appendChar(&ch);
	}
	else if (isalpha(ch))
	{
		s->setState(ScannerStateInID::getInstance());
		nextToken.appendChar(&ch);
	}
	else if (isspace(ch))
	{
		// skip whitespace
	}
	else if (strchr( CHAR_OPERATOR, ch) != NULL)
	{
		s->setState(ScannerStateChOperator::getInstance());
		s->getSourceFile()->prevCol(); // Backtrack
	}
	else if (ch == EOF)
	{
		nextToken.setType(::EOF_TOK);
		s->setState(ScannerStateDone::getInstance());
	}
}
