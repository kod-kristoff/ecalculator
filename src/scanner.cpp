#include "scanner.hpp"

#include <iostream>

namespace ecal
{
    scanner::scanner (char const * buf)
        : _buf (buf)
    {
        std::cout << "scanner created with '" << buf << "'" << std::endl;
    }
} // namespace ecal
