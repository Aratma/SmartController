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
#include "ConfigReader.h"

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
void UtilTest::testConfigReader()
{

	string configFile="/home/vagrant/Projects/SmartController/SmartCompiler/Config/config.xml";

	ConfigReader appConfig;
	appConfig.readConfigFile(configFile);

	std::string logDir = appConfig.getOptionA();

 	CPPUNIT_ASSERT(logDir.length() > 0);
}


} /* namespace Util */
