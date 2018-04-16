/******************************************************************************
 * @file PerserTest.cpp
 *
 * @brief Implementation for parser testing
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

#include <memory>
#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>


#include "JsonSerializer.h"
#include "SourceFile.h"
#include "ScannerST.h"
#include "TreeNode.h"
#include "TypeSpec.h"
#include "SymbolTabItem.h"
#include "SymbolTab.h"
#include "SymbolTabStack.h"
#include "StandardSymTabItems.h"
#include "ParserST.h"

#include "ParserTest.h"

using namespace std;
using namespace Scanner;

namespace Parser
{

ParserTest::ParserTest()
{
	// TODO Auto-generated constructor stub

}

ParserTest::~ParserTest()
{
	// TODO Auto-generated destructor stub
}


void ParserTest::setUp()
{
}

void ParserTest::tearDown()
{
}


///////////////////////////////////////////////////////////////////////
void ParserTest::testTreeNode()
{
	auto parent = make_shared<TreeNode> (TreeNode::ENodeType::PROGRAM, "PROGRAM", nullptr);

	auto leftChild = make_shared<TreeNode> (TreeNode::ENodeType::ASSGN_STATEM, "ASSGN_STATEM", parent);
	parent->addChild(leftChild);


	auto rightChild = make_shared<TreeNode> (TreeNode::ENodeType::FUNCTION, "FUNCTION", parent);
	parent->addChild(rightChild);


	auto grandChild = make_shared<TreeNode> (TreeNode::ENodeType::VAR_OPR, "VAR_OPR", rightChild);
	rightChild->addChild(grandChild);

	rightChild->addChild(grandChild);

	CPPUNIT_ASSERT(true);

}

///////////////////////////////////////////////////////////////////////
void ParserTest::testSymbolTable()
{
	bool b = false;
	pair<bool, shared_ptr<SymbolTabItem> > ret;

	// Create the symbol table stack
	auto symTabStack = make_shared<SymbolTabStack>();

	// Global Table
	auto globalTable = make_shared<SymbolTab>  ("GLOBAL");
	symTabStack->push(globalTable);

	auto globItem = make_shared<SymbolTabItem> (SymbolTabItem::EItemDefinition::UNKNOWN, "GLOBVAR", globalTable);
	b = globalTable->insert(globItem->getName(), globItem);
	CPPUNIT_ASSERT(b);

	ret = symTabStack->findLocal("GLOBVAR");
	CPPUNIT_ASSERT(ret.first);
	printf("item : %s \n", (ret.second)->getName().c_str());


	// Program Table
	auto progTable = make_shared<SymbolTab>  ("PROG");
	symTabStack->push(progTable);

	auto progItem = make_shared<SymbolTabItem> (SymbolTabItem::EItemDefinition::UNKNOWN, "PROGVAR", progTable);
	b = progTable->insert(progItem->getName(), progItem);
	CPPUNIT_ASSERT(b);

	auto progItemConst = make_shared<SymbolTabItem> (SymbolTabItem::EItemDefinition::UNKNOWN, "PROGCONST", progTable);
	b = progTable->insert(progItemConst->getName(), progItemConst);
	CPPUNIT_ASSERT(b);

	ret = symTabStack->find("GLOBVAR");
	CPPUNIT_ASSERT(ret.first);
	printf("item : %s \n", (ret.second)->getName().c_str());

	ret = symTabStack->findLocal("PROGVAR");
	CPPUNIT_ASSERT(ret.first);
	printf("item : %s \n", (ret.second)->getName().c_str());


	ofstream fileStream;
	fileStream.open("/home/vagrant/Projects/SmartController/SmartCompiler/Config/symbolTableStack.json",  ios::out | ios::trunc);
	JsonSerializer::Serialize((IJsonSerializable*)(symTabStack.get()), fileStream);



	// Subprogram Table
	auto subTable = make_shared<SymbolTab>  ("SUB");
	symTabStack->push(subTable);

	auto subItem = make_shared<SymbolTabItem> (SymbolTabItem::EItemDefinition::UNKNOWN, "SUBVAR", subTable);
	b = subTable->insert(subItem->getName(), subItem);
	CPPUNIT_ASSERT(b);


	ret = symTabStack->findLocal("SUBVAR");
	CPPUNIT_ASSERT(ret.first);
	printf("item : %s \n", (ret.second)->getName().c_str());

	symTabStack->pop();
	ret = symTabStack->findLocal("PROGVAR");
	CPPUNIT_ASSERT(ret.first);
	printf("item : %s \n", (ret.second)->getName().c_str());


}

///////////////////////////////////////////////////////////////////////
void ParserTest::testJson()
{

	auto parent = make_shared<TreeNode> (TreeNode::ENodeType::PROGRAM, "PROGRAM", nullptr);


	auto leftChild = make_shared<TreeNode> (TreeNode::ENodeType::ASSGN_STATEM, "ASSGN_STATEM", parent);
	parent->addChild(leftChild);

	auto rightChild = make_shared<TreeNode> (TreeNode::ENodeType::FUNCTION, "FUNCTION", parent);
	parent->addChild(rightChild);

	ofstream fileStream;
	fileStream.open("/home/vagrant/Projects/SmartController/SmartCompiler/Config/testJson.json",  ios::out | ios::trunc);
	JsonSerializer::Serialize((IJsonSerializable*)(parent.get()), fileStream);

}


///////////////////////////////////////////////////////////////////////
void ParserTest::testJsonSymbolTable()
{
	auto subItem = make_shared<SymbolTabItem> (SymbolTabItem::EItemDefinition::UNKNOWN, "SUBVAR", nullptr);
	subItem->addLines(3);
	subItem->addLines(4);


	ofstream fileStream;
	fileStream.open("/home/vagrant/Projects/SmartController/SmartCompiler/Config/testJsonSymbolTable.json",  ios::out | ios::trunc);
	JsonSerializer::Serialize((IJsonSerializable*)(subItem.get()), fileStream);


	//TODO Test Symbol Table + SymbolTable Stack

}

///////////////////////////////////////////////////////////////////////
void ParserTest::testStandardTypes()
{
	// Create the symbol table stack
	auto symTabStack = make_shared<SymbolTabStack>();

	// Global Table
	auto globalTable = make_shared<SymbolTab>  ("GLOBAL");
	symTabStack->push(globalTable);

	auto globItem = make_shared<SymbolTabItem> (SymbolTabItem::EItemDefinition::UNKNOWN, "GLOBVAR", globalTable);
	bool b = globalTable->insert(globItem->getName(), globItem);
	CPPUNIT_ASSERT(b);


	auto stdTypes = make_shared<StandardSymTabItems>();
	stdTypes->initTypes(symTabStack);

	ofstream fileStream;
	fileStream.open("/home/vagrant/Projects/SmartController/SmartCompiler/Config/stdtypes.json",  ios::out | ios::trunc);
	JsonSerializer::Serialize((IJsonSerializable*)(stdTypes.get()), fileStream);

}

///////////////////////////////////////////////////////////////////////
void ParserTest::testParseST()
{
	auto ctx = make_shared<ParserContext>();

	// Scanner
	auto srcFile = make_shared<SourceFile> ();
	srcFile->init("/home/vagrant/Projects/SmartController/SmartCompiler/Sample/program.st");
	ctx->_scannerST = make_shared<ScannerST>(srcFile);

	// Symbol Table Stack
	ctx->_symTabStack = make_shared<SymbolTabStack>();

	// Global Table
	auto globalTable = make_shared<SymbolTab>  ("GLOBAL");
	ctx->_symTabStack->push(globalTable);

	// Standard Types and Functions
	ctx->_stdTypes = make_shared<StandardSymTabItems>();
	ctx->_stdTypes->initTypes(ctx->_symTabStack);


	auto parser = make_shared<ParserST>(ctx);

	auto progNode = parser->parse();

	// Output symbol table stack
	ofstream fileStreamStack;
	fileStreamStack.open("/home/vagrant/Projects/SmartController/SmartCompiler/Sample/programSymStack.json",  ios::out | ios::trunc);
	JsonSerializer::Serialize((IJsonSerializable*)(ctx->_symTabStack.get()), fileStreamStack);

	// Output parse tree
	ofstream fileStreamTree;
	fileStreamTree.open("/home/vagrant/Projects/SmartController/SmartCompiler/Sample/programParseTree.json",  ios::out | ios::trunc);
	JsonSerializer::Serialize((IJsonSerializable*)(progNode.get()), fileStreamTree);


	// Output typespec
	ofstream fileStream;
	fileStream.open("/home/vagrant/Projects/SmartController/SmartCompiler/Sample/stdtypes.json",  ios::out | ios::trunc);
	JsonSerializer::Serialize((IJsonSerializable*)(ctx->_stdTypes.get()), fileStream);

}



} /* namespace Parser */
