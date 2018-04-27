#ifndef ECAL_CALCULATOR_HPP_
#   define ECAL_CALCULATOR_HPP_

#include "kx/stack_ff.hpp"
#include "input_fwd.hpp"

namespace ecal
{
    class calculator
    {
    public: // Member types
        typedef kx::stack_ff<int>   stack_type;
    public:
        calculator ();

        bool
        execute (ecal::input & input_);

        stack_type const &
        get_stack ()
        /*const*/;
    private:
        stack_type  _stack;
        bool        _done;
    };
} // namespace ecal
#endif // ECAL_CALCULATOR_HPP_
