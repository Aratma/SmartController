/******************************************************************************
 * @file SourceFile.h
 *
 * @brief Scanner class
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

#ifndef SCANNERST_H_
#define SCANNERST_H_

#include <memory>
#include "Token.h"

using namespace std;


namespace Scanner
{

class SourceFile;


class ScannerST
{
public:
	ScannerST(shared_ptr<SourceFile> srcFile);
	virtual ~ScannerST();

public:
	shared_ptr<Token> curToken();
	shared_ptr<Token> nextToken();

	bool checkNextToken(Token::ETokenType tokeType);

protected:
	void skipWhiteSpace();

private:
	shared_ptr<SourceFile> m_srcFile;
	shared_ptr<Token> m_curToken;
};

} /* namespace Scanner */

#endif /* SCANNERST_H_ */
