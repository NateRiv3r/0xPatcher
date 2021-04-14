#include "exceptions.hpp"

void exception(const std::string error) {
    printHelp();
    std::cerr << error << std::endl;
    exit(1);
}

void printHelp() {
    std::cout << "/-----------------|" << std::endl;
    std::cout << "| == 0xPatcher == |" << std::endl;
    std::cout << "|----------Log_s--/" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "patch file byte offset [OPTIONS]" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "    options :" << std::endl;
    std::cout << "        -o / --output : when specified, this option allows you to write the result" << std::endl;
    std::cout << "                        in a copy of the file, and to leave that file untouched" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "        -v / --verbose : when specified, you'll get feedaback, even when no errors" << std::endl;
    std::cout << "                         no errors where encountered" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "    Examples :" << std::endl;
    std::cout << "        patch image.png 5f 8" << std::endl;
    std::cout << "        patch file.pdf 0x73 16 -v -o file_copy.pdf" << std::endl;
    std::cout << "" << std::endl;
}