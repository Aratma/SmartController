//============================================================================
// Name        : ScannerTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

#include "ScannerTest.h"

using namespace std;

int main()
{

	CppUnit::TextUi::TestRunner runner;
	runner.addTest(ScannerTest::suite());
	runner.run();

	return 0;
}
