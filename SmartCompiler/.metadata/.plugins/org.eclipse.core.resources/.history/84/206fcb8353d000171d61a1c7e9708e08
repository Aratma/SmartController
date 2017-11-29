//============================================================================
// Name        : Scanner.h
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#ifndef SOURCEFILE_H_
#define SOURCEFILE_H_

#include <stdio.h>
#include <string.h>

#define MAX_SOURCE_LINE_LEN 256

using namespace std;

class SourceFile
{
public:
	SourceFile();
	virtual ~SourceFile();

public:
	bool openFile(const char* pFileName);
	void closeFile();

public:
	char nextCol();
	char prevCol();

private:
	int nextRow();

private:
	FILE* m_pFile;

	char m_curLine[256];

	int m_curLineLen;

	int m_curRow;
	int m_curCol;
};

#endif /* SOURCEFILE_H_ */
