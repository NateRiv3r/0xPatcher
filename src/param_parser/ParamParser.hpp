#ifndef __PARAMPARSER_H__
#define __PARAMPARSER_H__

class ParamParser {
    public:
        ParamParser(const int p_argc, char** p_argv);

        bool isVerbose();
        bool hasOutput();
        char* getInFile();
        char* getOutFile();

    private:
        bool _verbose;
        bool _output;
        char* _inFile;
        char* _outFile;
};

#endif