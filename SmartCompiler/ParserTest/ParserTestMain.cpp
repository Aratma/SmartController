/******************************************************************************
 * @file PerserTestMain.cpp
 *
 * @brief Class for the main function of parser testing
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

#include "ParserTest.h"


using namespace std;

int main()
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(Parser::ParserTest::suite());
	runner.run();

	return 0;
}
