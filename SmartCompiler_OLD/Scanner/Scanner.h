//============================================================================
// Name        : Scanner.h
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#ifndef SCANNER_H_
#define SCANNER_H_

#include <stdio.h>
#include <map>
#include <string>
#include "TokenDefs.h"

using namespace std;

class ScannerState;
class SourceFile;
class Token;

class Scanner
{
public:
	Scanner();
	virtual ~Scanner();

public:
	void getNextToken(Token& nextToken);
	SourceFile* getSourceFile() {return m_pSrcFile;}

public:
	void initScanner(const char* pSrcFileName);
	void setState(ScannerState* pState);

	ETokenType isKeyword(const char* id);

protected:
	void openSourceFile(const char* pSrcFileName);

private:
	ScannerState* m_pState;
	SourceFile* m_pSrcFile;

	map<string, ETokenType> m_keyWords;
};

#endif /* SCANNER_H_ */
