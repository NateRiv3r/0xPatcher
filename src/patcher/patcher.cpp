#include "patcher.hpp"

void Patcher::patch(char* p_inFile, int p_byte, int p_offset, bool p_verbose)
{

    FILE * ff = fopen(p_inFile, "r+");

    struct stat buffer;
    std::string filename(p_inFile);
    if (stat (filename.c_str(), &buffer) != 0) {
        exception("[!] Error : file not found");
    }

    fseek(ff, p_offset, SEEK_SET);

    if (p_verbose) {
        char read_byte[1];
        std::fread(read_byte, 1, 1, ff);
        int read_byte_int = *read_byte;
        std::cout << "[+] Replaced 0x" << std::hex << read_byte_int << " by 0x" << std::hex << p_byte << " at offset " << p_offset << std::endl;
        fseek(ff, p_offset, SEEK_SET);
    }

    fwrite((char *) &p_byte, 1, 1, ff);
}

void Patcher::_copy_file(std::string p_toCopy, std::string p_copy) const
{
    std::ifstream  src(p_toCopy, std::ios::binary);
    std::ofstream  dst(p_copy,   std::ios::binary);

    dst << src.rdbuf();
}

void Patcher::patch(char* p_inFile, int p_byte, int p_offset, bool p_verbose, char* p_outFile)
{
    this->_copy_file(p_inFile, p_outFile);
    this->patch(p_outFile, p_byte, p_offset, p_verbose);
}