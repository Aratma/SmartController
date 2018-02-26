/******************************************************************************
 * @file ConfigReader.h
 * @class ConfigReader
 *
 * @brief Some description
 *
 * @version 1.0
 * @author It's me
 * @date 2017/12/15
 *
 *****************************************************************************/
#ifndef CONFIGREADER_H_
#define CONFIGREADER_H_

#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMText.hpp>

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLUni.hpp>

#include <string>
#include <stdexcept>


using namespace std;

namespace Util
{

enum
{
   ERROR_ARGS = 1,
   ERROR_XERCES_INIT,
   ERROR_PARSE,
   ERROR_EMPTY_DOCUMENT
};

class ConfigReader
{
public:
	ConfigReader();
  ~ConfigReader();

   void readConfigFile(string&) throw(runtime_error);

   char *getOptionA() { return m_logFile; };

private:
   xercesc::XercesDOMParser *m_ConfigFileParser;
   char* m_logFile;

   // Internal class use only. Hold Xerces data in UTF-16 SMLCh type.

   XMLCh* TAG_root;

   XMLCh* TAG_ApplicationSettings;
   XMLCh* ATTR_logFile;
};

} /* namespace Util */

#endif /* CONFIGREADER_H_ */
