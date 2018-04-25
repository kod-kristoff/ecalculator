#include <iostream>

#include "calculator.hpp"
#include "input.hpp"

#include "kx/stack_seq.hpp"

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
            for (kx::stack_seq seq (calc.get_stack());
                !seq.at_end ();
                seq.advance ())
            {
                std::cout << "    " << seq.get_num () << std::endl;
            }
        }
    } while(status);
}
