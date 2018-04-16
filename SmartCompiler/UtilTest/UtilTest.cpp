/******************************************************************************
 * @file UtilTest.cpp
 *
 * @brief Implementation of the utilTest class
 *
 * @version 1.0
 * @author It's me
 * @date 2017/12/15
 *
 *****************************************************************************/
#include <stdio.h>
#include <iostream>
#include <array>
#include <string>
#include <unistd.h>

#include "Environment.h"
#include "MessageMgr.h"
#include "Variant_t.h"

#include "UtilTest.h"

using namespace std;
using namespace Util;


namespace Util
{

UtilTest::UtilTest()
{
}

UtilTest::~UtilTest()
{
}

void UtilTest::setUp()
{
}

void UtilTest::tearDown()
{
}


///////////////////////////////////////////////////////////////////////////////
void UtilTest::testTime()
{
	string timeStr =  Environment::getEnvironment().getCurTime();
	cout << timeStr;

	CPPUNIT_ASSERT(timeStr.length() > 0);
}


///////////////////////////////////////////////////////////////////////////////
void UtilTest::testMessageMgr()
{

	Environment::getEnvironment().getMessageMgr().publishMessage(MessageType::ERROR, "Publish unformatted error message");
	Environment::getEnvironment().getMessageMgr().publishMessage(MessageType::INFO, "Formatted Info Message %d", 15);
	Environment::getEnvironment().getMessageMgr().publishMessage(MessageType::WARNING,
																 "Formatted %s Message",
																 MessageType::TEXT[MessageType::WARNING]);

	CPPUNIT_ASSERT(true);
}



///////////////////////////////////////////////////////////////////////////////
void UtilTest::testVariant()
{
	variant_t t;

	variant_t n(15);
	variant_t c('a');
	variant_t s("xyz");
	variant_t q(s);
	variant_t r = s;
	variant_t x = 5;
	variant_t y = 'y';

	std::string someString = "abcdef";
	variant_t z = someString;
}


} /* namespace Util */
