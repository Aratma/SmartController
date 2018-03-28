/******************************************************************************
 * @file UtilTestMain.cpp
 * @brief Main function for util testing
 *
 * @version 1.0
 * @author It's me
 * @date 2017/12/15
 *
 *****************************************************************************/
#include <iostream>

#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

#include "UtilTest.h"

using namespace std;

int main()
{

	CppUnit::TextUi::TestRunner runner;

	runner.addTest(Util::UtilTest::suite());
	runner.run();

	return 0;
}


