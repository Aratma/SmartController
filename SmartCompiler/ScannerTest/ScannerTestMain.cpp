/******************************************************************************
 * @file ScannerTestMain.cpp
 *
 * @brief "main" for Scanner testing
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

#include <iostream>

#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

#include "ScannerTest.h"

using namespace std;

int main()
{

	CppUnit::TextUi::TestRunner runner;
	runner.addTest(Scanner::ScannerTest::suite());
	runner.run();

	return 0;
}
