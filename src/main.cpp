#include "param_parser/param_parser.hpp"
#include "patcher/patcher.hpp"


void printHelp();

int main(int argc, char** argv)
{
    ParamParser * parser = new ParamParser(argc, argv);

    bool verbose = parser->isVerbose();
    bool output = parser->hasOutput();
    int byte = parser->getByte();
    int offset = parser->getOffset();
    char* inFile = parser->getInFile();
    char* outFile;
    if (output) {
        outFile = parser->getOutFile();
    }


    Patcher * patcher = new Patcher();
    if (output) {
        patcher->patch(inFile, byte, offset, verbose, outFile);
    }
    else {
        patcher->patch(inFile, byte, offset, verbose);
    }


    return 0;
}

