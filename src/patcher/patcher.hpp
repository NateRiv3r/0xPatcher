#ifndef __PATCHER_H__
#define __PATCHER_H__

#include <string>
#include <fstream>
#include "../utils/exceptions.hpp"

class Patcher {
    public:
        Patcher() = default;
        void patch(char* p_inFile, int p_byte, int p_offset, bool p_verbose);
        void patch(char* p_inFile, int p_byte, int p_offset, bool p_verbose, char* p_outFile);

    private:
        void _copy_file(std::string p_toCopy, std::string p_copy) const;
};

#endif