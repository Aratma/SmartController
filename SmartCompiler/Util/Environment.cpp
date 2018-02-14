/******************************************************************************
 * @file Environment.cpp
 *
 * @brief Implementation of the Environment class
 *
 * @version 1.0
 * @author It's me
 * @date 2017/12/15
 *
 *****************************************************************************/
#include <stdio.h>
#include <chrono>
#include <cstdarg>
#include <unistd.h>

#include "MessageMgr.h"
#include "Environment.h"

using namespace std;

namespace Util
{

Environment* Environment::s_theInstance = nullptr;


Environment::Environment()
: m_pMsgMgr(nullptr)
{
}

Environment::~Environment()
{
	if (m_pMsgMgr != nullptr)
	{
		delete m_pMsgMgr;
		m_pMsgMgr = nullptr;
	}
}

Environment& Environment::getEnvironment()
{
    if ( !s_theInstance )
    {
    	s_theInstance= new Environment();
    	s_theInstance->initEnvironment();
    }

    return *s_theInstance;
}

void Environment::initEnvironment()
{
	initConfig();
	initMessageMgr();
}

void Environment::initConfig()
{
	// TODO: read config file
}

void Environment::initMessageMgr()
{
    if (m_pMsgMgr == nullptr)
	{
    	m_pMsgMgr = new Util::MessageMgr();
    	m_pMsgMgr->initMessageMgr("/home/vagrant/Temp/TestLog.txt");
	}
}

string Environment::getCurTime()
{
	chrono::time_point<chrono::system_clock> sysTimePoint = chrono::system_clock::now();
	time_t tp = chrono::system_clock::to_time_t(sysTimePoint);
	tm* pTm = gmtime(&tp);

	char       buf[80];
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", pTm);
	return buf;

}

string Environment::getCurWorkingDir()
{
	char buff[FILENAME_MAX];
	getcwd( buff, FILENAME_MAX );
	std::string cwd(buff);

	return cwd;
}

} /* namespace Util */
