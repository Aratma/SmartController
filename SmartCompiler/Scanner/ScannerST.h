//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

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
	ScannerST(SourceFile& rFile);
	virtual ~ScannerST();

public:
	void curToken(Token& t);
	void nextToken(Token& t);

	std::shared_ptr<Token> scan();

protected:
	void skipWhiteSpace();

private:
	SourceFile& m_rFile;
};

} /* namespace Scanner */

#endif /* SCANNERST_H_ */
