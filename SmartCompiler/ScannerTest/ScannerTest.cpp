/******************************************************************************
 * @file ScannerTest.cpp
 *
 * @brief Implementation class for ScannerTest
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

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
	auto srcFile = make_shared<SourceFile> ();
	srcFile->init("/home/vagrant/Projects/SmartController/SmartCompiler/Sample/program.st");

	auto s = make_shared<ScannerST>(srcFile);

	std::shared_ptr<Token> p;

	do
	{
		p = s->scan();

		std::cout << " Text: " << p->getText();
		std::cout << " Type: " << static_cast<size_t>(p->getType());
		std::cout << " Line: " << p->getLine();
		std::cout << " Col: " << p->getCol();
		std::cout << std::endl;

	} while  ( (p->getType() != Token::ETokenType::ERROR)
			   && (p->getType() != Token::ETokenType::END_OF_FILE) );


}





