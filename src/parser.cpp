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
            char    symbol_str [max_sym_len + 1];
            int     symbol_len = max_sym_len;

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
            case t_minus:
                kx::write_ln ("minus");
                break;
            case t_divide:
                kx::write_ln ("divide");
                break;
            case t_l_paren:
                kx::write_ln ("(");
                break;
            case t_r_paren:
                kx::write_ln (")");
                break;
            case t_assign:
                kx::write_ln ("assign");
                break;
            case t_ident:
                // symbol_len and symbol_str define above
                _scanner.symbol_name (symbol_str, symbol_len);
                std::cout << "symbol: '" << symbol_str << "'" << std::endl;
                break;
            default:
                kx::write_ln ("Error: bad token");
                return st_quit;
            }
        }
        return st_ok;
    }
} // namespace ecal
