
#include <stdio.h>
#include <memory>

#include "Token.h"
#include "SourceFile.h"
#include "ScannerST.h"

#include "ScannerTest.h"
#include <MessageMgr.h>

using namespace Util;
using namespace Scanner;


ScannerTest::ScannerTest()
{
}

ScannerTest::~ScannerTest()
{
}

void ScannerTest::setUp()
{
}

void ScannerTest::tearDown()
{
}


///////////////////////////////////////////////////////////////////////
void ScannerTest::testSourceFile()
{
	SourceFile codeFile;
	codeFile.init("/home/vagrant/Projects/SmartController/SmartCompiler/Sample/program.st");

	char ch = codeFile.curChar();
	while (ch != EOF)
	{
		std::cout << ch;
		ch = codeFile.nextChar();
	}
}


///////////////////////////////////////////////////////////////////////
void ScannerTest::testScanToken()
{
	SourceFile codeFile;
	codeFile.init("/home/vagrant/Projects/SmartController/SmartCompiler/Sample/program.st");

	MessageMgr l;
	l.init("/home/vagrant/Temp/TestLog.txt");

	ScannerST testScanner(&codeFile);
	std::shared_ptr<Token> p = testScanner.scan();

}





