/******************************************************************************
 * @file ScannerTest.h
 *
 * @brief Class for testing the scanner
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

#ifndef SCANNERTEST_H_
#define SCANNERTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>


#define BUFFER_SIZE 1048576 // 1MB


namespace Scanner
{

class ScannerTest : public CppUnit::TestFixture
{
public:
	ScannerTest();
	virtual ~ScannerTest();

public:
	static CppUnit::Test *suite()
	{
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "ScannerTestSuite" );

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


} /* namespace Scanner */


#endif /* SCANNERTEST_H_ */
