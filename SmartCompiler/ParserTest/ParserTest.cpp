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
#include "TreeNode.h"
#include "SymbolTabItem.h"
#include "SymbolTab.h"

#include "ParserTest.h"

using namespace std;

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
	bool b = false;

	auto parent = make_shared<TreeNode> (TreeNode::ENodeType::PROGRAM, "PROGRAM", nullptr);

	auto leftChild = make_shared<TreeNode> (TreeNode::ENodeType::ASSGN_STATEM, "ASSGN_STATEM", parent);
	b = parent->addChild("LEFT", leftChild);
	CPPUNIT_ASSERT(b);

	auto rightChild = make_shared<TreeNode> (TreeNode::ENodeType::FUNCTION, "FUNCTION", parent);
	b = parent->addChild("RIGHT", rightChild);
	CPPUNIT_ASSERT(b);

	auto grandChild = make_shared<TreeNode> (TreeNode::ENodeType::VAR_OPR, "VAR_OPR", rightChild);
	b = rightChild->addChild("RIGHT", grandChild);
	CPPUNIT_ASSERT(b);

	b = rightChild->addChild("RIGHT", grandChild);
	CPPUNIT_ASSERT(!b);
}

///////////////////////////////////////////////////////////////////////
void ParserTest::testSymbolTable()
{
	bool b = false;

	auto globalTable = make_shared<SymbolTab>  ("GLOBAL", nullptr);
	auto progTable = make_shared<SymbolTab>  ("PROG", globalTable);
	auto subTable = make_shared<SymbolTab>  ("SUB", progTable);


	auto subItem = make_shared<SymbolTabItem> (SymbolTabItem::EItemType::UNKNOWN, "SUBVAR", subTable);
	b = subTable->insert(subItem->getName(), subItem);
	CPPUNIT_ASSERT(b);

	b = subTable->insert(subItem->getName(), subItem);
	CPPUNIT_ASSERT(!b);

	auto progItem = make_shared<SymbolTabItem> (SymbolTabItem::EItemType::UNKNOWN, "PROGVAR", progTable);
	b = progTable->insert(progItem->getName(), progItem);
	CPPUNIT_ASSERT(b);

	auto progItemConst = make_shared<SymbolTabItem> (SymbolTabItem::EItemType::UNKNOWN, "PROGCONST", progTable);
	b = progTable->insert(progItemConst->getName(), progItemConst);
	CPPUNIT_ASSERT(b);

	auto globItem = make_shared<SymbolTabItem> (SymbolTabItem::EItemType::UNKNOWN, "GLOBVAR", globalTable);
	b = globalTable->insert(globItem->getName(), globItem);
	CPPUNIT_ASSERT(b);

	pair<bool, shared_ptr<SymbolTabItem> > ret;

	ret = subTable->findLocal("SUBVAR");
	CPPUNIT_ASSERT(ret.first);
	printf("item : %s \n", (ret.second)->getName().c_str());

	ret = subTable->findLocal("PROGVAR");
	CPPUNIT_ASSERT(!ret.first);

	ret = subTable->find("PROGVAR");
	CPPUNIT_ASSERT(ret.first);
	printf("item : %s \n", (ret.second)->getName().c_str());

	ret = subTable->find("GLOBVAR");
	CPPUNIT_ASSERT(ret.first);
	printf("item : %s \n", (ret.second)->getName().c_str());

}



} /* namespace Parser */
