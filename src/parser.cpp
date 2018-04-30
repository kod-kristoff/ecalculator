#include "parser.hpp"

#include "scanner.hpp"
#include "symbol_table.hpp"

#include "kx/write_ln.hpp"

namespace ecal
{
    parser::parser (
        scanner &       scanner_,
        symbol_table &  sym_tab_
    )
        :   _scanner (scanner_)
        ,   _sym_tab (sym_tab_)
    {
        kx::write_ln ("parser created.");
    }

    parser::~parser ()
    {
        kx::write_ln ("destroying parser.");
    }

    status
    parser::eval ()
    {
        kx::write_ln ("parser::eval");
        return parse ();
        // return st_quit;
    }

    status
    parser::parse ()
    {
        kx::write_ln ("parser::parse");
        for (expr_token token = _scanner.token ();
            token != t_end;
            token = _scanner.accept ())
        {
            switch (token) {
            case t_error:
                kx::write_ln ("error");
                return st_quit;
            case t_number:
                std::cout << "number: " << _scanner.number () << std::endl;
                break;
            case t_plus:
                kx::write_ln ("plus");
                break;
            case t_mult:
                kx::write_ln ("times");
                break;
            default:
                kx::write_ln ("Error: bad token");
                return st_quit;
            }
        }
        return st_ok;
    }
} // namespace ecal
