/******************************************************************************
 * @file TypeSpec.cpp
 *
 * @brief Implementation of class for defining types
 *
 * @version 1.0
 * @author It's me
 * @date 2018/03/12
 *
 * @todo move to intermediate layer
 *
 *****************************************************************************/
#include <stdio.h>

#include "SymbolTabItem.h"
#include "SymbolTab.h"

#include "TypeSpec.h"


using namespace std;


namespace Parser
{

TypeSpec::TypeSpec(ETypeSpecForm  e)
: m_typeForm(e)
{
	printf("TypeSpec Constructed %p \n", this);
}

TypeSpec::~TypeSpec()
{
	m_typeAttributes.clear();

	printf("TypeSpec Destructed %p \n", this);

}

bool TypeSpec::setAttribute(TypeAttribute::EAttribKey key, TypeAttribute attrib)
{
	return (m_typeAttributes.insert( std::make_pair( key, attrib)).second);
}


pair<bool, TypeAttribute > TypeSpec::getAttribute(TypeAttribute::EAttribKey key)
{

	auto it = m_typeAttributes.find(key);
	if (it != m_typeAttributes.end())
	{
		return make_pair(true, it->second);
	}

    return make_pair(false, TypeAttribute());
}

void TypeSpec::Serialize( Json::Value& root )
{
   root["TypeForm"] = (uint)m_typeForm;

   // TODO: Attributes and symbol tabe item refrerence
}

void TypeSpec::Deserialize( Json::Value& root )
{
	throw std::logic_error("Not implemented!");
}



} /* namespace Parser */
