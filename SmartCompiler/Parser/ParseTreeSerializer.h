/******************************************************************************
 * @file ParseTreeSerializer.h
 *
 * @brief Class for serializing parse trees in xml files
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/2
 *
 *
 *******************************l**********************************************/


#ifndef PARSETREESERIALIZER_H_
#define PARSETREESERIALIZER_H_

#include <memory>
#include <string>

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include "TreeNode.h"



using namespace std;

namespace Parser
{

class ParseTreeSerializer
{
public:
	ParseTreeSerializer();
	virtual ~ParseTreeSerializer();

public:
	void serialize(const string& fileName, shared_ptr<TreeNode> parseTree);

protected:
	void serializeSubTree(xmlNodePtr rootNode, shared_ptr<TreeNode> parseTree);
	void cleanup();

private:
	xmlDocPtr m_doc;       /* document pointer */
};



} /* namespace Parser */

#endif /* PARSETREESERIALIZER_H_ */
