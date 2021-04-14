#ifndef __PARAMPARSER_H__
#define __PARAMPARSER_H__

#include "../utils/dev_tools.hpp"
#include "../utils/exceptions.hpp"
#include <stdio.h>

class ParamParser {
    public:
        ParamParser(const int p_argc, char** p_argv);

        bool isVerbose();
        bool hasOutput();
        int getByte();
        int getOffset();
        char* getInFile();
        char* getOutFile();

    private:
        bool _verbose;
        bool _output;
        int _byte;
        int _offset;
        char* _inFile;
        char* _outFile;
};

#endif