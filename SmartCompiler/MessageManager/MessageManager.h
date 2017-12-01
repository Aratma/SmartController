//============================================================================
// Name        : MessageManager.h
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#ifndef MESSAGEMANAGER_H_
#define MESSAGEMANAGER_H_

#include <vector>

namespace MessageManager {

class MessageManager
{
public:
	MessageManager();
	virtual ~MessageManager();

public:
	void addMessageSubscriber(const MessageSubscriber& sub);
	void removeMessageSubscriber(const MessageSubscriber& sub);

public:
	void publishMessage(const Message& msg);

private:
	std::vector<MessageSubscriber> m_msgSinks;
};

} /* namespace MessageManager */
#endif /* MESSAGEMANAGER_H_ */
