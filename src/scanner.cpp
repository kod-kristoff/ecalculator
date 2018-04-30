#include "scanner.hpp"

#include <iostream>
#include <cassert>

namespace ecal
{
    scanner::scanner (char const * buf)
        :   _buf (buf)
        ,   _look (0)
    {
        std::cout << "scanner created with '" << buf << "'" << std::endl;
        accept ();
    }

    expr_token
    scanner::token ()
    const
    {
        return _token;
    }

    expr_token
    scanner::accept ()
    {
        eat_white ();
        switch (_buf [_look])
        {
        case '+':
            _token = t_plus;
            ++_look;
            break;
        case '*':
            _token = t_mult;
            ++_look;
            break;
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            _token = t_number;
            _number = atoi (&_buf [_look]);
            while (isdigit (_buf [_look]))
                ++_look;
            break;
            case '\0': // end of input
                _token = t_end;
                break;
            default:
                _token = t_error;
                break;
        }
        return token ();
    }

    double
    scanner::number ()
    const
    {
        assert (_token == t_number);
        return _number;
    }

    // ============================
    // helpers
    // ============================
    void
    scanner::eat_white () {
        while (isspace (_buf [_look]))
            ++_look;
    }
} // namespace ecal
