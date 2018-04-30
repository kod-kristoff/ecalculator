#include "symbol_table.hpp"
#include "scanner.hpp"
#include "parser.hpp"

#include <iostream>
#include <cstdlib>

const int max_buf = 100;

int main ()
{
    char buf [max_buf];
    ecal::status _status;
    ecal::symbol_table sym_tab;
    do {
        std::cout << "> ";  // prompt
        std::cin.getline (buf, max_buf);
        ecal::scanner _scanner (buf);
        ecal::parser _parser (_scanner, sym_tab);
        _status = _parser.eval ();
    } while(_status != ecal::st_quit);
    return EXIT_SUCCESS;
}
