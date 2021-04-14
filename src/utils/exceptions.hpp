#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include <iostream>

/**
 * Handles hand thrown exceptions by simply displaying the passed message
 * @param error : string -> the error message
 */
void exception(const std::string error);

/**
 * Prints the help menu
 */
void printHelp();

#endif