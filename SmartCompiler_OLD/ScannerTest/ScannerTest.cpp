
#include "ScannerTest.h"
#include "Scanner.h"

ScannerTest::ScannerTest()
{
}

ScannerTest::~ScannerTest()
{
}

void ScannerTest::setUp()
{
}

void ScannerTest::tearDown()
{
}


///////////////////////////////// Token //////////////////////////////////////
void ScannerTest::testTheToken()
{
	Token t(::ERROR_TOK, "ERRORTOK");
	CPPUNIT_ASSERT(t.getType() == ::ERROR_TOK);

	CPPUNIT_ASSERT( (strcmp(t.getTextPtr(), "ERRORTOK") == 0) );

	Token r;
	r = t;
	CPPUNIT_ASSERT(t.getType() == ::ERROR_TOK);
	CPPUNIT_ASSERT( (strcmp(r.getTextPtr(), "ERRORTOK") == 0) );

	Token p;
	p.appendChar("E");
	p.appendChar("R");
	p.appendChar("R");
	CPPUNIT_ASSERT( (strcmp(p.getTextPtr(), "ERR") == 0) );


}



///////////////////////////////// SourceFile //////////////////////////////////////

bool ScannerTest::isFileEqual(const std::string& lFilePath, const std::string& rFilePath) const
{
    std::ifstream lFile(lFilePath.c_str(), std::ifstream::in | std::ifstream::binary);
    std::ifstream rFile(rFilePath.c_str(), std::ifstream::in | std::ifstream::binary);

    if(!lFile.is_open() || !rFile.is_open())
    {
        return false;
    }

    char *lBuffer = new char[BUFFER_SIZE]();
    char *rBuffer = new char[BUFFER_SIZE]();

    long numberOfRead = 0;

    do
    {
    	 lFile.read(lBuffer, BUFFER_SIZE);
    	        rFile.read(rBuffer, BUFFER_SIZE);
    		numberOfRead = lFile.gcount(); //I check the files with the same size


    	        if (memcmp(lBuffer, rBuffer, numberOfRead) != 0)
    	        {
    				memset(lBuffer,0,numberOfRead);
    				memset(rBuffer,0,numberOfRead);
    				return false;
    	        }

    } while (lFile.good() || rFile.good());

    delete[] lBuffer;
    delete[] rBuffer;

    return true;
}

void ScannerTest::testSourceFile()
{
	const char* pSrcFileName = "/home/vagrant/SmartControl/SmartCompiler/Sample/program.st";
	const char* pDestFileName = "/home/vagrant/SmartControl/SmartCompiler/Sample/program_copy.st";

	SourceFile f;
	CPPUNIT_ASSERT(true == f.openFile(pSrcFileName));

	FILE* destFile = fopen(pDestFileName, "w");
	CPPUNIT_ASSERT(destFile != NULL);

	printf("************************  testSourceFile \n");


	char ch = f.nextCol();;
	printf ("%d %c \n", ch, ch);

	while (ch != EOF)
	{
		fputc (ch, destFile);
		ch = f.nextCol();

		printf ("%d %c \n", ch, ch);

	} ;
	fclose(destFile);

	bool filesEqual = isFileEqual(pSrcFileName, pDestFileName);
	remove(pDestFileName);

	CPPUNIT_ASSERT(filesEqual == true);
}

///////////////////////////////// Scanner //////////////////////////////////////
void ScannerTest::testScanner()
{
	Scanner s;
	s.initScanner("/home/vagrant/SmartControl/SmartCompiler/Sample/program.st");

	Token t;

	printf("************************  testScanner \n");

	do {
		s.getNextToken(t);
		printf("%d    %s \n", (int)t.getType(), t.getTextPtr() );
	} while (t.getType() != ::EOF_TOK);
}


