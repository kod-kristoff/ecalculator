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
        case '-':
            _token = t_minus;
            ++_look;
            break;
        case '/':
            _token = t_divide;
            break;
        case '(':
            _token = t_l_paren;
            break;
        case ')':
            _token = t_r_paren;
            break;
        case '=':
            _token = t_assign;
            break;
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            _token = t_number;
            char * p;
            _number = strtod (&_buf [_look], &p);
            _look = p - _buf; // pointer subtraction
            break;
        case '\0': // end of input
            _token = t_end;
            break;
        default:
            if (isalpha (_buf [_look]) || _buf [_look] == '_')
            {
                _token  = t_ident;
                _symbol = _look;
                int look; // initalized in the do loop
                do {
                    ++_look;
                    look = _buf [_look];
                } while (isalnum (look) || look == '_');

                _symbol_len = _look - _symbol;
                if (_symbol_len > max_sym_len)
                    _symbol_len = max_sym_len;
            }
            else
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

    void
    scanner::symbol_name (
        char *  str_out,
        int &   len
    )
    {
        assert (len >= max_sym_len);
        assert (_symbol_len <= max_sym_len);
        strncpy (str_out, &_buf [_symbol], _symbol_len);
        str_out [_symbol_len] = 0;
        len = _symbol_len;
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
