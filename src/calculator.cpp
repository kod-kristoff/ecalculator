#include "calculator.hpp"

#include "kx/write_ln.hpp"

namespace ecal
{
    calculator::calculator ()
        : _done (false)
    {
        kx::write_ln ("calculator created");
    }

    bool
    calculator::execute (input & input_)
    {
        kx::write_ln ("calculator::execute");
        return !_done;
    }

    calculator::stack_type const &
    calculator::get_stack () /*const*/
    {
        _done = true;
        return _stack;
    }
} // namespace ecal
