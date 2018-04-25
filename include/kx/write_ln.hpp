#ifndef KX_WRITE_LN_HPP_
#   define KX_WRITE_LN_HPP_

#include <iostream>

namespace kx
{
    template<class T>
    void write_ln (T str)
    {
        std::cout << str << std::endl;
    }
} // namespace kx

#endif // KX_WRITE_LN_HPP_
