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
        return st_quit;
    }
} // namespace ecal
