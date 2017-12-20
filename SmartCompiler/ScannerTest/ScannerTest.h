//============================================================================
// Name        : ScannerTest.h
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#ifndef SCANNERTEST_H_
#define SCANNERTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>


#define BUFFER_SIZE 1048576 // 1MB


class ScannerTest : public CppUnit::TestFixture
{
public:
	ScannerTest();
	virtual ~ScannerTest();

public:
	static CppUnit::Test *suite()
	{
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "TokenTestSuite" );

		suiteOfTests->addTest( new CppUnit::TestCaller<ScannerTest>("testSourceFile", &ScannerTest::testSourceFile ) );
		suiteOfTests->addTest( new CppUnit::TestCaller<ScannerTest>("testScanToken", &ScannerTest::testScanToken ) );



		return suiteOfTests;
	}

public:
   void setUp();
   void tearDown();

protected:
  void testSourceFile();
  void testScanToken();

};

#endif /* SCANNERTEST_H_ */
