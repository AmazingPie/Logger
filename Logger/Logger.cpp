/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Logger.h"

void Log(void *userdata, int category, Priority priority, const char *message)
{
    time_t t = time(0);
    struct tm *CurrTime = localtime(&t);
    
    //decide upon the type of log to write (error, warn or info)
    std::string logfile;
    std::string type;
    switch (priority)
    {
    case (PRIORITY_ERROR):
    	logfile = "Logs\\crashlog.txt";
    	type = "ERROR";
    	break;
    case (PRIORITY_WARN):
    	logfile = "Logs\\eventlog.txt";
    	type = "WARNING";
    	break;
    case (PRIORITY_INFO):
    	logfile = "Logs\\eventlog.txt";
    	type = "INFO";
    	break;
    }
    std::stringstream ss;
	
	
    //write the message to the string stream and then to the output
    for (int i = 1; i<3; i=i*2) {
    	ss << "<" << CurrTime->tm_year + 1900 << "-" << CurrTime->tm_mon + 1 << "-" << CurrTime->tm_mday << "> <"
    	<< CurrTime->tm_hour << ":" << CurrTime->tm_min << ":" << CurrTime->tm_sec << "> " << "[" << type << "]  " 
    	<< message << std::endl;
	switch (category & i) {
	case (OUTPUT_TYPE_CONSOLE):
	    std::cout << ss.rdbuf();
	    break;
	case (OUTPUT_TYPE_FILE):
	    std::ofstream os(logfile.c_str(), std::ios::app | std::ios::ate);
	    if (os.is_open()) {
		os << ss.rdbuf();
		os.close();
	    }
	    break;
	}
    }
}
//Output Example: <2016-12-31> <23:60:60> [ERROR]  errormsg...
//Output Example: <2016-12-31> <23:60:60> [INFO]   _getcwd: errormsg...