//============================================================================
// Name        : Message.h
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#ifndef LOGGER_H_
#define LOGGER_H_

#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>

using namespace std;

#define LOGGER CLogger::GetLogger()


namespace Util
{

class Logger
{
public: // Singleton
	static Logger* getInstance()
	{
		static Logger theInstance;
		return &theInstance;
	}

public:
	/**
	*   Logs a message
	*   Argument msg is the message to be logged.
	*/
	void Log(const std::string& msg);

	/**
	*   Variable length logging function
	*   Argument is the format string for the message to be logged.
	*/
	void Log(const char * format, ...);

	/**
	*   << overloaded function to log a message
	*   Argument msg is the message to be logged.
	*/
	Logger& operator<<(const string& msg);

private:
	static const std::string m_sFileName;
	static ofstream m_Logfile;

private: // Singleton
	Logger();
	Logger(const Logger&){};
	Logger& operator=(const Logger&){ return *this; };

};

} /* namespace Util */
#endif /* LOGGER_H_ */
