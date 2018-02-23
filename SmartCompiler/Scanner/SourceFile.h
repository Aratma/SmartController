/******************************************************************************
 * @file SourceFile.h
 *
 * @brief Class for source file handling
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 * @todo Use memory mapped files
 *
 *****************************************************************************/

#ifndef SOURCEFILE_H_
#define SOURCEFILE_H_

#include <iostream>
#include <fstream>
#include <string>


namespace Scanner
{

constexpr char EOL {'\n'};

class SourceFile
{
public:
	SourceFile();
	virtual ~SourceFile();

public:
	bool init(const std::string& srcFileName);

	int getLineNum() {return m_lineNum;}
	int getColNum()  {return m_colNum;}

public:
	char peekChar();
	char nextChar();
	char curChar();

private:
	int m_lineNum;
	int m_colNum;

private:
	char m_chCur;
	std::ifstream m_fileStream;

};

} /* namespace Scanner */

#endif /* SOURCEFILE_H_ */
