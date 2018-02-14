
#include <stdio.h>
#include <memory>

#include "SourceFile.h"

#include "Token.h"
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

	ScannerST testScanner(codeFile);
	std::shared_ptr<Token> p;

	do
	{
		p = testScanner.scan();


		std::cout << " Text: " << p->getText();
		std::cout << " Type: " << static_cast<size_t>(p->getType());
		std::cout << " Line: " << p->getLine();
		std::cout << " Col: " << p->getCol();
		std::cout << std::endl;

	} while  ( (p->getType() != Token::ETokenType::ERROR)
			   && (p->getType() != Token::ETokenType::END_OF_FILE) );


}





