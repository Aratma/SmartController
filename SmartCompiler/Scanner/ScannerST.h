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

namespace Scanner
{

class SourceFile;


class ScannerST
{
public:
	ScannerST(std::shared_ptr<SourceFile> srcFile);
	virtual ~ScannerST();

public:
	void curToken(Token& t);
	void nextToken(Token& t);

	std::shared_ptr<Token> scan();

protected:
	void skipWhiteSpace();

private:
	std::shared_ptr<SourceFile> m_srcFile;
};

} /* namespace Scanner */

#endif /* SCANNERST_H_ */
