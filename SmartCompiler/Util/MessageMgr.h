/******************************************************************************
 * @file MessageMgr.h
 * @class MessageMgr
 *
 * @brief Some description
 *
 * @version 1.0
 * @author It's me
 * @date 2017/12/15
 *
 *****************************************************************************/
#ifndef MESSAGEMGR_H_
#define MESSAGEMGR_H_

#include <iostream>
#include <fstream>
#include <string>

namespace Util
{

using namespace std;

struct MessageType
{
	enum ID {
		ERROR 	= 0,
		WARNING 	= 1,
		INFO 		= 2
	};

	static const char* TEXT[];
};

class MessageMgr
{
public:
	MessageMgr();
	virtual ~MessageMgr();

	void initMessageMgr(const string& fileName);

public:

	/** @brief Publish given message with given format and parameters (variadic)
	 *  @param msgType Message type
	 *  @param format Format string
	 *  @return Void.
	 */
	void publishMessage(const MessageType::ID msgType, const char * format, ...);

private:
	void writeMessage(const MessageType::ID msgType, const string& msg);

private:
	MessageMgr(const MessageMgr&) = delete;
	MessageMgr& operator=(const MessageMgr&) = delete;

private:
	ofstream m_fileStream;
};

} /* namespace Util */
#endif /* MESSAGEMGR_H_ */
