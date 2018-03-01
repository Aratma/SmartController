/******************************************************************************
 * @file PerserTest.h
 *
 * @brief Class for parser testing
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/20
 *
 *
 *****************************************************************************/

#ifndef PARSERTEST_H_
#define PARSERTEST_H_


#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

namespace Parser
{

class ParserTest : public CppUnit::TestFixture
{
public:
	ParserTest();
	virtual ~ParserTest();

public:
	static CppUnit::Test *suite()
	{
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "ParserTestSuite" );

		suiteOfTests->addTest( new CppUnit::TestCaller<ParserTest>("testTreeNode", &ParserTest::testTreeNode ) );
		suiteOfTests->addTest( new CppUnit::TestCaller<ParserTest>("testSymbolTable", &ParserTest::testSymbolTable ) );
		suiteOfTests->addTest( new CppUnit::TestCaller<ParserTest>("testlibXml2", &ParserTest::testlibXml2 ) );
		suiteOfTests->addTest( new CppUnit::TestCaller<ParserTest>("testlibXml2Serialization", &ParserTest::testlibXml2Serialization ) );
		suiteOfTests->addTest( new CppUnit::TestCaller<ParserTest>("testJson", &ParserTest::testJson ) );
		suiteOfTests->addTest( new CppUnit::TestCaller<ParserTest>("testJsonSymbolTable", &ParserTest::testJsonSymbolTable ) );

		return suiteOfTests;
	}

public:
   void setUp();
   void tearDown();

protected:
  void testTreeNode();
  void testSymbolTable();
  void testTreeSerialization();


protected:
  void testlibXml2();
  void testlibXml2Serialization();
  void testJson();
  void testJsonSymbolTable();


protected:
  void parseStory (xmlDocPtr doc, xmlNodePtr cur);
  void parseDoc(const char *docname);


};

} /* namespace Parser */

#endif /* PARSERTEST_H_ */
