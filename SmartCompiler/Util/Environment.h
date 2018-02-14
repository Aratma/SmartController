/******************************************************************************
 * @file Environment.h
 * @class Environment
 *
 * @brief Some description
 *
 * @version 1.0
 * @author It's me
 * @date 2017/12/15
 *
 *****************************************************************************/

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

#include <stdio.h>
#include <string>

#include "MessageMgr.h"

namespace Util
{

class Environment
{
public:
	static Environment& getEnvironment();

public:
	MessageMgr& getMessageMgr() {return *m_pMsgMgr;}
	std::string getCurTime();
	std::string getCurWorkingDir();

private:
	void initEnvironment();
	void initConfig();
	void initMessageMgr();

private:
	Environment();
	~Environment();

	Environment(const Environment& ) = delete;
	Environment& operator=(const Environment& ) = delete;

private:
	MessageMgr* m_pMsgMgr;
	static Environment* s_theInstance;
};

} /* namespace Util */

#endif /* ENVIRONMENT_H_ */
