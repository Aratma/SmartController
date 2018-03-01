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
#include "JsonSerializer.h"

using namespace std;


namespace Parser
{

JsonSerializer::JsonSerializer()
{
	// TODO Auto-generated constructor stub
}

JsonSerializer::~JsonSerializer()
{
	// TODO Auto-generated destructor stub
}

bool JsonSerializer::Serialize( IJsonSerializable* pObj, ostream& output )
{
   if (pObj == NULL)
      return false;

   Json::Value serializeRoot;
   pObj->Serialize(serializeRoot);

   Json::StyledWriter writer;
   output << writer.write( serializeRoot );

   return true;
}

bool JsonSerializer::Deserialize( IJsonSerializable* pObj, istream& input )
{
   if (pObj == NULL)
      return false;

   Json::Value deserializeRoot;
   Json::Reader reader;

   if ( !reader.parse(input, deserializeRoot) )
      return false;

   pObj->Deserialize(deserializeRoot);

   return true;
}



} /* namespace Parser */
