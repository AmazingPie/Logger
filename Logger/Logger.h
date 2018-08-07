/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Logger.h
 * Author: chris
 *
 * Created on 01 August 2018, 15:44
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>		//Date and Time

/*Output a log message to different places
(Bitwise OR to output to multiple places) 
*/
enum OutputType
{
    OUTPUT_TYPE_CONSOLE = 1,
    OUTPUT_TYPE_FILE = 2
};

/*The priority to assign to the message.
 Will appear as a prefix to the message.*/
enum Priority
{
    PRIORITY_ERROR,
    PRIORITY_WARN,
    PRIORITY_INFO
};

/*A simple logger that allows for multiple output types with custom messages.*/
void Log(void *userdata, int category, Priority priority, const char *message);

#endif /* LOGGER_H */

