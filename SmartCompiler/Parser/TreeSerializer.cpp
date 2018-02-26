/******************************************************************************
 * @file TreeSerializer.cpp
 *
 * @brief Implementation of TreeSerializer
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/23
 *
 *
 *******************************l**********************************************/

// Mandatory for using any feature of Xerces.
#include <xercesc/util/PlatformUtils.hpp>

// Use the Document Object Model (DOM) API
#include <xercesc/dom/DOM.hpp>

// Required for outputing a Xerces DOMDocument
// to a standard output stream (Also see: XMLFormatTarget)
#include <xercesc/framework/StdOutFormatTarget.hpp>

// Required for outputing a Xerces DOMDocument
// to the file system (Also see: XMLFormatTarget)
#include <xercesc/framework/LocalFileFormatTarget.hpp>


#include "TreeNode.h"
#include "TreeSerializer.h"


XERCES_CPP_NAMESPACE_USE

using namespace std;


namespace Parser
{

TreeSerializer::TreeSerializer(const string& fileName)
{
}

TreeSerializer::~TreeSerializer()
{
	// TODO Auto-generated destructor stub
}

void TreeSerializer::serialize(shared_ptr<TreeNode> rootNode, const string& fileName)
{
	// create file

	// build Dom

	// serialize Dom

	// close file
}

void TreeSerializer::buildDom(shared_ptr<TreeNode> rootNode)
{
	// init Xerces
	// Pointer to our DOMImplementation.
	DOMImplementation* pDOMImplementation = initXerces();

	// build root
	DOMElement * pRootElement = NULL;
	pRootElement = pDOMDocument->getDocumentElement();
	pRootElement->setAttribute();

	// add data of the root Node

	// add children

	/*
	ENodeType m_nodeType;
	weak_ptr<TreeNode> m_parentNode;
	map<string, shared_ptr<TreeNode> > m_childMap;
	weak_ptr<SymbolTab> m_symbolTable;
*/


}


void TreeSerializer::addChildren(shared_ptr<TreeNode> treeNode)
{

}



DOMImplementation* TreeSerializer::initXerces()
{
	// Initilize Xerces.
	XMLPlatformUtils::Initialize();

	// Get the DOM Implementation (used for creating DOMDocuments).
	// Also see: http://www.w3.org/TR/2000/REC-DOM-Level-2-Core-20001113/core.html
	return DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));
}




} /* namespace Parser */
