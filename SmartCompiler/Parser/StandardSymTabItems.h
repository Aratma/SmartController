/******************************************************************************
 * @file StandardSymTabItems.h
 *
 * @brief Builtin constants, types and functions
  *
 * @version 1.0
 * @author It's me
 * @date 2018/03/20
 *
 * @todo 1. move to intermediate layer
 * 		2. Serialization Json
 *
 *
 *****************************************************************************/

#ifndef STANDARDSYMTABITEMS_H_
#define STANDARDSYMTABITEMS_H_

#include <memory>


namespace Parser
{

/*****************************************************************************/
class SymbolTabItem;
class SymbolTabStack;
class TypeSpec;

/*****************************************************************************/
class StandardSymTabItems : public IJsonSerializable
{
public:
	StandardSymTabItems();
	virtual ~StandardSymTabItems();

public:
	void initTypes(shared_ptr<SymbolTabStack> symTabStack);

protected:
	void initTypeINT(shared_ptr<SymbolTabStack> symTabStack);

public:
	virtual void Serialize( Json::Value& root);
	virtual void Deserialize( Json::Value& root);

private: // Types
	shared_ptr<TypeSpec> m_intTypeSpec;

private: // Identifier
	weak_ptr<SymbolTabItem> m_intTabItemID;  // Avoid cyclic referencing of smart pointer
};



} /* namespace Parser */

#endif /* STANDARDSYMTABITEMS_H_ */
