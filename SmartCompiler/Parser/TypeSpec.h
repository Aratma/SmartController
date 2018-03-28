/******************************************************************************
 * @file TypeSpec.h
 *
 * @brief Base class for handling data types:
 * 			Scalar, Enum, Struct, Array
 *
 * @version 1.0
 * @author It's me
 * @date 2018/03/12
 *
 * @todo 1. move to intermediate layer
 * 		2. serialization
 * 		3. simple memory tracking: map to register every class on construction and deregister on destruction
 *
 *****************************************************************************/

#ifndef TYPESPEC_H_
#define TYPESPEC_H_

#include <utility>
#include <memory>
#include <vector>
#include <map>

#include "IJsonSerializable.h"
#include "Variant_t.h"

namespace Parser
{

using namespace std;
using namespace Util;


/*****************************************************************************/
class SymbolTabItem;
class SymbolTab;

/*****************************************************************************/
struct TypeAttribute
{
public:
	enum class EAttribKey
	{
		UNKNOWN = 0,
		ENUM_CONST,
		SUBRANGE_BASE_TYPE, SUBRANGE_MIN, SUBRANGE_MAX,
		ARR_INDEX_TYPE, ARR_ELEMENT_TYPE, ARR_SIZE,
		STRUCT_SYMTAB,
	};

public:
	TypeAttribute() : _attribCode(EAttribKey::UNKNOWN) { printf("TypeAttribute Constructed %p \n", this); }
	virtual ~TypeAttribute() { printf("TypeAttribute Destructed %p \n", this); }

public:
	EAttribKey _attribCode;

public:
	variant_t _attribData;
	weak_ptr<SymbolTab> _symTabWeakPtr;
	vector< shared_ptr<SymbolTabItem> > _symTabEntryList;
};


/*****************************************************************************/
class TypeSpec : public IJsonSerializable
{
public:
	enum class ETypeSpecForm : uint
	{
		UNKNOWN = 0,
		SCALAR,
		ARRAY,
		STRUCT,
	};

public:
	TypeSpec(ETypeSpecForm e);
	virtual ~TypeSpec();

public:
	virtual void Serialize( Json::Value& root);
	virtual void Deserialize( Json::Value& root);

public:
	bool setAttribute(TypeAttribute::EAttribKey key, TypeAttribute attrib);
	pair<bool, TypeAttribute > getAttribute(TypeAttribute::EAttribKey key);

	void setForm(ETypeSpecForm e) { m_typeForm = e; }
	ETypeSpecForm getForm() { return m_typeForm; }

	void setSymbolTabItemId(shared_ptr<SymbolTabItem> t) { m_typeID = t;}
	shared_ptr<SymbolTabItem> getSymbolTabItemId() { return m_typeID.lock();}


protected:
	ETypeSpecForm m_typeForm;
	weak_ptr<SymbolTabItem> m_typeID; // Avoid cylic referencing of smart pointer

protected:
	map< TypeAttribute::EAttribKey, TypeAttribute> m_typeAttributes;
};


} /* namespace Parser */

#endif /* TYPESPEC_H_ */
