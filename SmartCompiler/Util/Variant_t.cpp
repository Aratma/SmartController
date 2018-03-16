/******************************************************************************
 * @file Variant_t.cpp
 *
 * @brief Implementation of the Variant_t class
 *
 * @version 1.0
 * @author It's me
 * @date 2017/12/15
 *
 *****************************************************************************/
#include <string>

#include "Variant_t.h"

using namespace std;

namespace Util
{

variant_t::variant_t()
: 	_type(EVarType::INT)
,  asInt(0)
{
}

variant_t::~variant_t()
{
	if (_type == EVarType::STRING)
	{
		asString.~string();     // destroy (explicitly!)
	}
}

void variant_t::init(const variant_t& t)
{

	if (this == &t) // check self assignment
		return;

    if (_type == EVarType::STRING && t._type == EVarType::STRING)
    {
        asString = t.asString;  // usual string assignment
        return;
    }

    if (_type == EVarType::STRING)
    {
    	asString.~string();     // destroy (explicitly!)
    }

    switch (t._type)
    {
    case EVarType::CHAR: asChar = t.asChar; break;    	// normal copy
    case EVarType::INT: asInt = t.asInt; break;  		// normal copy
    case EVarType::STRING: new(&asString)std::string(t.asString); break;	// placement new
    }

    _type = t._type;
}


variant_t::variant_t(const variant_t& t)
{
	init(t);
}

variant_t& variant_t::operator=(const variant_t& t)
{
    init(t);
    return *this;
}



} /* namespace Util */



