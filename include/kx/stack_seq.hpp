#ifndef KX_STACK_SEQ_HPP_
#   define KX_STACK_SEQ_HPP_

#include "kx/stack.hpp"

namespace kx
{
    class stack_seq
    {
    public:
        stack_seq (stack const & stack_);

        bool
        at_end ()
        const;

        void
        advance ();

        int
        get_num ()
        const;
    private:
        stack const &   _stack;
        bool            _done;
    };
} // namespace kx
#endif // KX_STACK_SEQ_HPP_
