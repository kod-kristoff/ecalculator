#include "calculator.hpp"

#include "kx/write_ln.hpp"

namespace ecal
{
    // Helper methods
    int
    calculate (
        int num1,
        int num2,
        int token
    )
    {
        int result;

        if (token == '+')       result = num1 + num2;
        else if (token == '-')  result = num1 - num2;
        else if (token == '*')  result = num1 * num2;
        else if (token == '/')
        {
            if (num2 == 0)
            {
                kx::write_ln ("Division by zero");
                result = 0;
            }
            else
                result = num1 / num2;
        }
        return result;
    }
    // Class calculator
    calculator::calculator ()
        : _done (false)
    {
        kx::write_ln ("calculator created");
    }

    bool
    calculator::execute (input & input_)
    {
        int token = input_.token ();
        bool status = false; // assume failure

        if (token == token_error)
        {
            kx::write_ln ("Unknown token");
        }
        else if (token == token_number)
        {
            if (_stack.is_full ())
            {
                kx::write_ln ("Stack is full");
            }
            else
            {
                _stack.push (input.number ());
                status = true;
            }
        }
        else
        {
            assert (token == '+'
                ||  token == '-'
                ||  token == '*'
                ||  token == '/'
            );

            if (_stack.is_empty ())
            {
                kx::write_ln ("Stack is empty");
            }
            else
            {
                int num2 = _stack.pop ();
                int num1;

                // Special case, when only one number on the stack:
                // use this number for both operands

                if (_stack.is_empty ())
                {
                    num1 = num2;
                }
                else
                {
                    num1 = _stack.pop ();
                }

                _stack.push (calculate (num1, num2, token));
                status = true;
            }
        }
        return status;
    }

    calculator::stack_type const &
    calculator::get_stack () /*const*/
    {
        _done = true;
        return _stack;
    }


} // namespace ecal
