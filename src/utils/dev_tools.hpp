#ifndef __DEV_TOOLS_H__
#define __DEV_TOOLS_H__

#include <iostream>
#include <time.h>
#include <string>

/**
 * Recovers and formats the current time 'hh:mm:ss' as a string
 * @return : string -> the formatted time
 */
std::string getTime();

/**
 * Dev logging for strings
 * @param printable : string -> the string to print
 */
void LOG(const std::string printable);

/**
 * Dev logging for integers
 * @param printable : int -> the integer to print
 */
void LOG(const int printable);

#endif