/*
 * ParseTreeSerializer.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: vagrant
 */

#include "ParseTreeSerializer.h"

namespace Parser
{

ParseTreeSerializer::ParseTreeSerializer()
: m_doc (NULL)
{
}



ParseTreeSerializer::~ParseTreeSerializer()
{
	cleanup();
}



void ParseTreeSerializer::cleanup()
{
	if (m_doc != NULL)
	{
		/*free the document */
		xmlFreeDoc(m_doc);

		/*
		 *Free the global variables that may
		 *have been allocated by the parser.
		 */
		xmlCleanupParser();


		m_doc = NULL;
	}
}


void ParseTreeSerializer::serialize(const string& fileName, shared_ptr<TreeNode> parseTree)
{
	LIBXML_TEST_VERSION;

	xmlNodePtr rootNode = NULL;

	/*
	 * Creates a new document, a node and set it as a root node
	 */
	m_doc = xmlNewDoc(BAD_CAST "1.0");
	rootNode = xmlNewNode(NULL, BAD_CAST "ROOT" );

	serializeSubTree(rootNode, parseTree);


	xmlDocSetRootElement(m_doc, rootNode);

	/*
	 * Dumping document to stdio or file
	 */
	xmlSaveFormatFileEnc(fileName.c_str(), m_doc, "UTF-8", 1);



	cleanup();
}


void ParseTreeSerializer::serializeSubTree(xmlNodePtr rootNode, shared_ptr<TreeNode> parseTree)
{
	xmlNodePtr childNode = xmlNewChild(rootNode, NULL, BAD_CAST parseTree->getName().c_str() , NULL);
	xmlNewProp(childNode, BAD_CAST "Type", BAD_CAST std::to_string((uint)parseTree->getType()).c_str());

	vector<shared_ptr<TreeNode>> childArr = parseTree->getChildren();

	for (auto element : childArr)
	{
		serializeSubTree(childNode, element);
	}

}


} /* namespace Parser */
