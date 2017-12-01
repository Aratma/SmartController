/*
 * MessageSubscriber.h
 *
 *  Created on: Nov 30, 2017
 *      Author: vagrant
 */

#ifndef MESSAGESUBSCRIBER_H_
#define MESSAGESUBSCRIBER_H_

namespace MessageManager
{

class MessageSubscriber
{
public:
	MessageSubscriber();
	virtual ~MessageSubscriber();

public:
	void OnMessage(const Message& msg);
};

} /* namespace MessageManager */
#endif /* MESSAGESUBSCRIBER_H_ */
