/******************************************************************************
 * @file CJsonSerializer.h
 *
 * @brief Class for serializing objects in json
  *
 * @version 1.0
 * @author It's me
 * @date 2018/03/01
 *
 *
 *******************************l**********************************************/

#ifndef JSONSERIALIZER_H_
#define JSONSERIALIZER_H_

#include <iostream>
#include <string>

#include "IJsonSerializable.h"


using namespace std;


namespace Parser
{

class JsonSerializer
{
public:
	virtual ~JsonSerializer();
	static bool Serialize( IJsonSerializable* pObj, ostream& output );
	static bool Deserialize( IJsonSerializable* pObj, istream& input );

private:
	JsonSerializer();
};

} /* namespace Parser */

#endif /* JSONSERIALIZER_H_ */
