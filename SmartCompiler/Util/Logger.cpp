
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <string>
#include <memory.h>

#include "Logger.h"

namespace Util
{

const string Logger::m_sFileName = "Log.txt";
ofstream Logger::m_Logfile;

void Logger::Log(const char * format, ...)
{
    char* sMessage = NULL;
    int nLength = 0;

    va_list args;
    va_start(args, format);



 /*
    //  Return the number of characters in the string referenced the list of arguments.
    // _vscprintf doesn't count terminating '\0' (that's why +1)
    nLength = _vscprintf(format, args) + 1;
    sMessage = new char[nLength];
    vsprintf_s(sMessage, nLength, format, args);
    //vsprintf(sMessage, format, args);
 */


 /*
           size_t size = std::snprintf( nullptr, 0, format, args) + 1; // Extra space for '\0'
           std::unique_ptr<char[]> buf( new char[ size ] );
           std::vsnprintf( buf.get(), size, format, args);

           return std::string(buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
 */

    size_t size = std::snprintf(NULL, 0, format, args) + 1; // Extra space for '\0'
    std::unique_ptr<char[]> buf( new char[ size ] );
    std::vsnprintf( buf.get(), size, format, args);



    m_Logfile << Util::CurrentDateTime() << ":\t";
    m_Logfile << sMessage << "\n";
    va_end(args);

    delete [] sMessage;
}

void Logger::Log(const string& sMessage)
{
    m_Logfile <<  Util::CurrentDateTime() << ":\t";
    m_Logfile << sMessage << "\n";
}

Logger& Logger::operator<<(const string& sMessage)
{
    m_Logfile << "\n" << Util::CurrentDateTime() << ":\t";
    m_Logfile << sMessage << "\n";
    return *this;
}


} /* namespace Logging */
