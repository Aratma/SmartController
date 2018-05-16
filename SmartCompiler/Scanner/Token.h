/******************************************************************************
 * @file Token.h
 *
 * @brief Base class for tokens of scanning
 *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 * @todo move constant decls to another file
 *
 *****************************************************************************/

#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <vector>
#include <memory>
#include "Variant_t.h"

#include "SourceFile.h"

namespace Scanner
{

using namespace std;
using namespace Util;



class Token
{

public:
	enum class ETokenType : uint
	{
		ERROR 		= 0,
		END_OF_FILE,
		IDENTIFIER,
		PROGRAM,
		END_PROGRAM,
		VAR,
		END_VAR,
		COLON_SYM,
		ASSIGN_SYM,
		SEMICOL_SYM,
		PERCENT_SYM,
		PERIOD_SYM,
		INT,
		REAL,
		MUL_SYM,
		DIV_SYM,
		UNKNOWN,
	};

	static const vector<string> TokenText;
	static const vector<ETokenType> KeyWords;
	static const vector<ETokenType> SpecialSymbols;

public:
	Token();
	virtual ~Token();

public:
	virtual void scanToken(shared_ptr<SourceFile> srcFile);

public:
	static ETokenType text2Type(const string& someText);
	static bool isKeyWord(const string& someText);
	static bool isSpecialSymbol(const string& someText);

public:
	ETokenType getType() {return m_tokenType;}
	string getText() { return m_tokenText;}
	int getLine() {return m_lineNum; }
	int getCol() { return m_colNum; }
	variant_t getValue() {return m_value;}

protected:
	ETokenType m_tokenType;
	string m_tokenText;
	int m_lineNum;
	int m_colNum;
	variant_t m_value;
};


} /* namespace Scanner */

#endif /* TOKEN_H_ */
