#include <iostream>

#include "calculator.hpp"
#include "input.hpp"

#include "kx/stack_ff.hpp"

int
main ()
{
    ecal::calculator calc;
    bool status;
    do
    {
        // Prompt for input
        std::cout << "> ";
        ecal::input input_;
        status = calc.execute (input_);
        if (status)
        {
            for (auto seq = begin (calc.get_stack());
                !seq.at_end ();
                seq.advance ())
            {
                std::cout << "    " << seq.get () << std::endl;
            }
        }
    } while(status);
}
