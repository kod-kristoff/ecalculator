#include "kx/stack_seq.hpp"
#include "kx/write_ln.hpp"

namespace kx
{
    stack_seq::stack_seq (
        stack const & stack_
    )
        :   _stack (stack_)
        ,   _done (false)
    {
        write_ln ("stack sequencer created");
    }

    bool
    stack_seq::at_end ()
    const
    {
        return _done;
    }

    void
    stack_seq::advance ()
    {
        _done = true;
    }

    int
    stack_seq::get_num ()
    const
    {
        return 13;
    }
} // namespace kx
