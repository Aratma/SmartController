/******************************************************************************
 * @file SymbolTabItem.h
 *
 * @brief Symbol Table Item
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/21
 *
 * @todo 1. move to intermediate layer
 *
 *****************************************************************************/

#ifndef SYMBOLTABITEM_H_
#define SYMBOLTABITEM_H_

#include <string>
#include <list>
#include <memory>
#include "IJsonSerializable.h"

#include "Variant_t.h"


using namespace std;
using namespace Util;


namespace Parser
{

/*****************************************************************************/
class TypeSpec;
class SymbolTab;

/*****************************************************************************/
struct SymbolTabItemAttribute
{
public:
	enum class EAttribKey : uint
	{
		UNKNOWN = 0,
		CONST_VAL,				// Constant value: todo: int, real, string,
		MODULE_CODE, 			// Program or Function code
		MODULE_SYMTAB,
		MODULE_ICODE,
		MODULE_PARAM,
		MODULE_ROUTINES,
		DATA_VALUE,				// Variable value
	};

public:
	SymbolTabItemAttribute() : _attribCode(EAttribKey::UNKNOWN) {};
	virtual ~SymbolTabItemAttribute() {};

public:
	EAttribKey _attribCode;

public:
	variant_t _attibData;
	weak_ptr<SymbolTab> _symTabWeakPtr;
};


/*****************************************************************************/
class SymbolTabItem : public IJsonSerializable
{
public:
	enum class EItemDefinition : uint
	{
		UNKNOWN = 0,
		CONST,
		ENUM_CONST,
		TYPE,
		VARIABLE,
		PROGRAM,
		FUNCTION,
	};


public:
	SymbolTabItem(EItemDefinition e,  string name, shared_ptr<SymbolTab> p);
	virtual ~SymbolTabItem();

public:
	void setItemDefinition(EItemDefinition e) { m_itemTypeDef = e; }
	EItemDefinition getItemDefinition() { return m_itemTypeDef; }

	void setName(string name) {m_itemName = name;}
	string getName()  { return m_itemName;}

	void setParent(shared_ptr<SymbolTab> p) { m_parentTable = p;}
	shared_ptr<SymbolTab> getParent() {return m_parentTable.lock();}

	void addLines(int l) { m_lineNums.push_back(l);}
	list<int> getLines() { return m_lineNums; }

	void setTypeSpec(shared_ptr<TypeSpec> p) { m_typeSpec = p; }
	shared_ptr<TypeSpec> getTypeSpec(){ return m_typeSpec; }

	bool setAttribute(SymbolTabItemAttribute::EAttribKey key, SymbolTabItemAttribute attrib);
	pair<bool, SymbolTabItemAttribute> getAttribute(SymbolTabItemAttribute::EAttribKey key);

public:
	virtual void Serialize( Json::Value& root);
	virtual void Deserialize( Json::Value& root);

private:
	EItemDefinition m_itemTypeDef;
	string m_itemName;
	weak_ptr<SymbolTab> m_parentTable; // Avoid cylic referencing of smart pointer
	list<int> m_lineNums;
	shared_ptr<TypeSpec> m_typeSpec;

protected:
	map< SymbolTabItemAttribute::EAttribKey, SymbolTabItemAttribute> m_itemAttributes;

};

} /* namespace Parser */

#endif /* SYMBOLTABITEM_H_ */
