#include "dev_tools.hpp"


std::string getTime()
{
    time_t result = time( NULL );
    std::string string( ctime( &result ) );
    return string.substr( 11, string.length() - 17 );
}

void LOG(const std::string printable)
{
    std::string time = getTime();
    std::cout << "[" << time << "] " << printable << std::endl;
}

void LOG(const int printable)
{
    std::string time = getTime();
    std::cout << "[" << time << "] " << std::to_string(printable) << std::endl;
}