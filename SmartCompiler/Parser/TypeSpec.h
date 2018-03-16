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
 * @todo move to intermediate layer
 *
 *****************************************************************************/

#ifndef TYPESPEC_H_
#define TYPESPEC_H_

#include <stdio.h>
#include <memory>
#include <vector>

namespace Parser
{

/*****************************************************************************/
class SymbolTab;
class SymbolTabItem;

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
};


/*****************************************************************************/
struct TypeAttribSymTab : public TypeAttribute
{
public:
	TypeAttribSymTab() : _symTabWeakPtr{} {};
	virtual ~TypeAttribSymTab() {};

public:
	weak_ptr<SymbolTab> _symTabWeakPtr;
};

/*****************************************************************************/
struct TypeAttribSymTabItemList : public TypeAttribute
{
public:
	TypeAttribSymTabItemList(){};
	virtual ~TypeAttribSymTabItemList() {_symTabEntryList.clear(); };

public:
	vector< shared_ptr<SymbolTabItem> > _symTabEntryList;
};


/*****************************************************************************/
class TypeSpec
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
	bool setAttribute(TypeAttribute::EAttribKey key, TypeAttribute attrib);
	pair<bool, TypeAttribute > getAttribute(TypeAttribute::EAttribKey key);

	void setForm(ETypeSpecForm e) { m_typeForm = e; }
	ETypeSpecForm getForm() { return m_typeForm; }

protected:
	ETypeSpecForm m_typeForm;
	weak_ptr<SymbolTabItem> m_typeID; // type identifier in symbol tables

protected:
	map< TypeAttribute::EAttribKey, TypeAttribute> m_typeAttributes;
};


} /* namespace Parser */

#endif /* TYPESPEC_H_ */
