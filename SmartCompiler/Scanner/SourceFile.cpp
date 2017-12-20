#include <stdio.h>
#include "SourceFile.h"

using namespace std;


namespace Scanner
{

SourceFile::SourceFile()
: m_lineNum(0)
, m_colNum(0)
, m_chCur(EOF)
{
}

SourceFile::~SourceFile()
{
	if (m_fileStream.is_open())
		m_fileStream.close();
}


bool SourceFile::init(const string& fileName)
{
	m_fileStream.open(fileName.c_str(),  ios::in);
	if (m_fileStream.is_open())
	{
		m_colNum = 0;
		m_lineNum = 0;
		 m_fileStream.get(m_chCur);
		return true;
	}

	return false;
}


char SourceFile::peekChar()
{
	return m_fileStream.peek();
}

char SourceFile::curChar()
{
	return m_chCur;
}

char SourceFile::nextChar()
{

	if (m_fileStream.eof())
	{
		return EOF;
	}

	if (m_chCur == EOL)
	{
		m_colNum = 0;
		m_lineNum++;
	}
	else
	{
		m_colNum++;
	}

	m_fileStream.get(m_chCur);
	return m_chCur;
}



} /* namespace Scanner */
