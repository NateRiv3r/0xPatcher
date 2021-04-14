#include "param_parser/ParamParser.hpp"

int main(int argc, char** argv)
{
    ParamParser* parser = new ParamParser(argc, argv);

    delete parser;
    return 0;
}
