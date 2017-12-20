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
	ScannerST(SourceFile* pFile);
	virtual ~ScannerST();

public:
	void curToken(Token& t);
	void nextToken(Token& t);

	std::shared_ptr<Token> scan();

private:
	SourceFile* m_pFile;
};

} /* namespace Scanner */

#endif /* SCANNERST_H_ */
