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


#include "TreeNode.h"
#include "SymbolTabItem.h"
#include "SymbolTab.h"
#include "JsonSerializer.h"


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




///////////////////////////////////////////////////////////////////////
void ParserTest::testlibXml2()
{
	parseDoc("/home/vagrant/Projects/SmartController/SmartCompiler/Config/story.xml");

}

void ParserTest::parseStory (xmlDocPtr doc, xmlNodePtr cur)
{
	xmlChar *key;

	cur = cur->xmlChildrenNode;
	while (cur != NULL)
	{
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"keyword")))
		{
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			printf("keyword: %s\n", key);
			xmlFree(key);
		}

		cur = cur->next;
	}
	return;
}

void ParserTest::parseDoc(const char *docname)
{
	xmlDocPtr doc;
	xmlNodePtr cur;

	doc = xmlParseFile(docname);
	if (doc == NULL )
	{
		fprintf(stderr,"Document not parsed successfully. \n");
		return;
	}


	cur = xmlDocGetRootElement(doc);
	if (cur == NULL)
	{
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return;
	}

	if (xmlStrcmp(cur->name, (const xmlChar *) "story"))
	{
		fprintf(stderr,"document of the wrong type, root node != story");
		xmlFreeDoc(doc);
		return;
	}

	cur = cur->xmlChildrenNode;
	while (cur != NULL)
	{
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"storyinfo")))
		{
			parseStory (doc, cur);
		}
		cur = cur->next;
	}

	xmlFreeDoc(doc);

	return;
}

///////////////////////////////////////////////////////////////////////
void ParserTest::testlibXml2Serialization()
{
	xmlDocPtr doc = NULL;       /* document pointer */
	xmlNodePtr root_node = NULL, node = NULL, node1 = NULL;/* node pointers */
	char buff[256];
	int i, j;

	LIBXML_TEST_VERSION;

	/*
	 * Creates a new document, a node and set it as a root node
	 */
	doc = xmlNewDoc(BAD_CAST "1.0");
	root_node = xmlNewNode(NULL, BAD_CAST "root");
	xmlDocSetRootElement(doc, root_node);

	/*
	 * Creates a DTD declaration. Isn't mandatory.
	 */
	xmlCreateIntSubset(doc, BAD_CAST "root", NULL, BAD_CAST "tree2.dtd");

	/*
	 * xmlNewChild() creates a new node, which is "attached" as child node
	 * of root_node node.
	 */
	xmlNewChild(root_node, NULL, BAD_CAST "node1",
				BAD_CAST "content of node 1");
	/*
	 * The same as above, but the new child node doesn't have a content
	 */
	xmlNewChild(root_node, NULL, BAD_CAST "node2", NULL);

	/*
	 * xmlNewProp() creates attributes, which is "attached" to an node.
	 * It returns xmlAttrPtr, which isn't used here.
	 */
	node =
		xmlNewChild(root_node, NULL, BAD_CAST "node3",
					BAD_CAST "this node has attributes");
	xmlNewProp(node, BAD_CAST "attribute", BAD_CAST "yes");
	xmlNewProp(node, BAD_CAST "foo", BAD_CAST "bar");

	/*
	 * Here goes another way to create nodes. xmlNewNode() and xmlNewText
	 * creates a node and a text node separately. They are "attached"
	 * by xmlAddChild()
	 */
	node = xmlNewNode(NULL, BAD_CAST "node4");
	node1 = xmlNewText(BAD_CAST
				   "other way to create content (which is also a node)");
	xmlAddChild(node, node1);
	xmlAddChild(root_node, node);

	/*
	 * A simple loop that "automates" nodes creation
	 */
	for (i = 5; i < 7; i++) {
		sprintf(buff, "node%d", i);
		node = xmlNewChild(root_node, NULL, BAD_CAST buff, NULL);
		for (j = 1; j < 4; j++) {
			sprintf(buff, "node%d%d", i, j);
			node1 = xmlNewChild(node, NULL, BAD_CAST buff, NULL);
			xmlNewProp(node1, BAD_CAST "odd", BAD_CAST((j % 2) ? "no" : "yes"));
		}
	}

	/*
	 * Dumping document to stdio or file
	 */
	xmlSaveFormatFileEnc("/home/vagrant/Projects/SmartController/SmartCompiler/Config/generated.xml", doc, "UTF-8", 1);

	/*free the document */
	xmlFreeDoc(doc);

	/*
	 *Free the global variables that may
	 *have been allocated by the parser.
	 */
	xmlCleanupParser();

	/*
	 * this is to debug memory for regression tests
	 */
	xmlMemoryDump();

}


///////////////////////////////////////////////////////////////////////
void ParserTest::testJson()
{

	auto parent = make_shared<TreeNode> (TreeNode::ENodeType::PROGRAM, "PROGRAM", nullptr);


	auto leftChild = make_shared<TreeNode> (TreeNode::ENodeType::ASSGN_STATEM, "ASSGN_STATEM", parent);
	parent->addChild("LEFT", leftChild);

	auto rightChild = make_shared<TreeNode> (TreeNode::ENodeType::FUNCTION, "FUNCTION", parent);
	parent->addChild("RIGHT", rightChild);

	ofstream fileStream;
	fileStream.open("/home/vagrant/Projects/SmartController/SmartCompiler/Config/parsetree.json",  ios::out | ios::trunc);
	JsonSerializer::Serialize((IJsonSerializable*)(parent.get()), fileStream);

}


///////////////////////////////////////////////////////////////////////
void ParserTest::testJsonSymbolTable()
{
	auto subItem = make_shared<SymbolTabItem> (SymbolTabItem::EItemType::UNKNOWN, "SUBVAR", nullptr);
	subItem->addLines(3);
	subItem->addLines(4);


	ofstream fileStream;
	fileStream.open("/home/vagrant/Projects/SmartController/SmartCompiler/Config/symtab.json",  ios::out | ios::trunc);
	JsonSerializer::Serialize((IJsonSerializable*)(subItem.get()), fileStream);


}


} /* namespace Parser */
