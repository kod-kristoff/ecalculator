#include "input.hpp"

#include "kx/write_ln.hpp"

#include <cctype>
#include <cstdlib>
#include <cassert>

namespace ecal
{
    input::input ()
    {
        std::cin >> _buf;

        // first char of input is usually enough to decide
        // what token it is

        int c = _buf [0];

        if (isdigit (c))
            _token = token_number;
        else if (c == '+' || c == '*' || c == '/')
            _token = c;
        else if (c == '-') // allow negative numbers
        {
            if (isdigit (_buf [1]))
                _token = token_number;
            else
                _token = c;
        }
        else
            _token = token_error;
    }

    int
    input::number ()
    const
    {
        assert (_token == token_number);
        return atoi (_buf);
    }

    int
    input::token ()
    const
    {
        return _token;
    }
} // namespace ecal
