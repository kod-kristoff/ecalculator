#include "symbol_table.hpp"

#include "kx/write_ln.hpp"

namespace ecal
{
    symbol_table::symbol_table ()
    {
        kx::write_ln ("symbol_table created.");
    }
} // namespace ecal
