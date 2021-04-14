#include "param_parser.hpp"

ParamParser::ParamParser(const int p_argc, char **p_argv) : _verbose(false), _output(false) {

    if (p_argv[1]) {
        this->_inFile = p_argv[1];
    }
    else {
        exception("[!] Error : the file parameter is required");
    }

    try {
        this->_byte = std::stoi(p_argv[2], 0, 16);
        if (this->_byte < 0 || this->_byte > 255) {
            exception("[!] Error : the byte parameter must be exactly one byte (0x00 - 0xFF)");
        }
    }
    catch (...) {
        exception("[!] Error : the byte parameter is required and must be an hexadecimal value (e.g. 0xfe or fe)");
    }

    try {
        this->_offset = std::stoi(p_argv[3], 0, 10);
    }
    catch (...) {
        exception("[!] Error : the offset parameter is required and must be a decimal value");
    }

    for (int i=4 ; i<p_argc ; i++) {
        std::string arg = p_argv[i];
        if (arg == "-v" || arg == "--verbose") {
            this->_verbose = true;
        }
        else if (arg == "-o" || arg == "--output") {
            if (p_argc > i+1) {
                std::string param = p_argv[i+1];
                if (param.rfind("-", 0) != 0) {
                    this->_output = true;
                    this->_outFile = p_argv[i+1];
                    i++;
                }
                else {
                    exception("[!] Error : the output flag was specified without an output file (.e.g. -o image.png)");
                }
            }
            else {
                exception("[!] Error : the output flag was specified without an output file (.e.g. -o image.png)");
            }
        }
        else {
            exception("[!] Error : unrecognized parameter");
        }
    }
}


bool ParamParser::isVerbose() {
    return this->_verbose;
}

bool ParamParser::hasOutput() {
    return this->_output;
}

int ParamParser::getByte() {
    return this->_byte;
}

int ParamParser::getOffset() {
    return this->_offset;
}

char* ParamParser::getInFile() {
    return this->_inFile;
}

char* ParamParser::getOutFile() {
    if (!this->_output) {
        exception("[!] Error : can't call getOutFile() without -o flag");
    }
    return this->_outFile;
}

// TODO : check if offset is in range
