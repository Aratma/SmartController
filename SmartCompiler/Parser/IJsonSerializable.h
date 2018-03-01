/******************************************************************************
 * @file IJsonSerializable.h
 *
 * @brief Base class for serializing using json
  *
 * @version 1.0
 * @author It's me
 * @date 2018/03/01
 *
 *
 *******************************l**********************************************/
#include <jsoncpp/json/json.h>


#ifndef IJSONSERIALIZABLE_H_
#define IJSONSERIALIZABLE_H_

namespace Parser
{

class IJsonSerializable
{
public:
	IJsonSerializable();
	virtual ~IJsonSerializable();
	virtual void Serialize( Json::Value& root ) = 0;
	virtual void Deserialize( Json::Value& root)  = 0;
};


} /* namespace Parser */

#endif /* IJSONSERIALIZABLE_H_ */
