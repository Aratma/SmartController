/******************************************************************************
 * @file UtilTest.h
 * @class UtilTest
 *
 * @brief Testing of the util library
 *
 * @version 1.0
 * @author It's me
 * @date 2017/12/15
 *
 *****************************************************************************/
#ifndef UTILTEST_H_
#define UTILTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>


namespace Util
{

class Environment;

class UtilTest : public CppUnit::TestFixture
{
public:
	UtilTest();
	virtual ~UtilTest();

public:
	static CppUnit::Test *suite()
	   {
	     CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "utilTestSuite" );

	     suiteOfTests->addTest( new CppUnit::TestCaller<Util::UtilTest>("testTime", &UtilTest::testTime ) );
	     suiteOfTests->addTest( new CppUnit::TestCaller<Util::UtilTest>("testLogger", &UtilTest::testMessageMgr ) );

	     return suiteOfTests;
	   }

public:
	   void setUp();
	   void tearDown();

protected:
	   void testTime();
	   void testMessageMgr();
};

} /* namespace Util */

#endif /* UTILTEST_H_ */
