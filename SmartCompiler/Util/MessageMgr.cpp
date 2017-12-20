/******************************************************************************
 * @file MessageMgr.cpp
 *
 * @brief Implementation of the MessageMgr class
 *
 * @version 1.0
 * @author It's me
 * @date 2017/12/15
 *
 *****************************************************************************/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdarg>
#include <string>

#include "Environment.h"
#include "MessageMgr.h"


using namespace std;

namespace Util
{

const char* MessageType::TEXT[] = {
		"ERROR",
		"WARNING",
		"INFO" };


MessageMgr::MessageMgr()
{
}

MessageMgr::~MessageMgr()
{
	if (m_fileStream.is_open() )
		m_fileStream.close();
}


void MessageMgr::initMessageMgr(const string& fileName)
{
	if ( m_fileStream.is_open() )
		m_fileStream.close();

	m_fileStream.open(fileName.c_str(), ios::out | ios::app);
}


void MessageMgr::writeMessage(const MessageType::ID msgType, const std::string& msg)
{
	ostringstream outStr;

	outStr << Environment::getEnvironment().getCurTime() << ":\t";
	outStr << MessageType::TEXT[msgType] << ":\t";
	outStr << msg << "\n";

	cout << outStr.str();

   	m_fileStream << outStr.str();
   	m_fileStream.flush();
}

void MessageMgr::publishMessage(const MessageType::ID msgType, const char * format, ...)
{
    char* msg = nullptr;
    int len = 0;

    va_list args;
    va_start(args, format);

    // Determine the number of characters in the string referenced in the list of arguments.
    va_list argcopy;
    va_copy(argcopy, args);
    // vsnprintf doesn't count terminating '\0' (so +1)
    len = vsnprintf(nullptr, 0, format, argcopy) + 1;
    va_end(argcopy);

    msg = new char[len];
    vsnprintf(msg, len, format, args);

    writeMessage(msgType, msg);

    va_end(args);

    delete [] msg;
}


} /* namespace Util */
