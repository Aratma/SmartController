//============================================================================
// Name        : Message.h
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>

namespace MessageManager {

enum E_MESSAGE_TYPE
{
	UNKNOWN_MSG,
};

class Message
{
public:
	Message(const E_MESSAGE_TYPE type, const std::string& msg);
	virtual ~Message();

public:
	E_MESSAGE_TYPE getType() {return m_msgType;}
	void getText(std::string& msg) {msg = m_msgText;}

private:
	E_MESSAGE_TYPE m_msgType;
	std::string m_msgText;
};


} /* namespace MessageManager */
#endif /* MESSAGE_H_ */
