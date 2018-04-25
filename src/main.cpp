#include <iostream>
namespace kx
{
    void
    write_ln(char const * str)
    {
        std::cout << str << std::endl;
    }

    class stack {};

    class stack_seq
    {
    public:
        stack_seq (stack const & stack_)
            :   _stack (stack_)
            ,   _done (false)
        {
            write_ln ("stack sequencer created");
        }

        bool
        at_end () const
        {
            return _done;
        }

        void
        advance ()
        {
            _done = true;
        }

        int
        get_num () const
        {
            return 13;
        }
    private:
        stack const &   _stack;
        bool            _done;
    };

    class input
    {
    public:
        input ()
        {
            write_ln ("input created");
        }
    };

    class calculator
    {
    public:
        calculator () : _done (false)
        {
            write_ln ("calculator created");
        }

        bool execute (input & input_)
        {
            write_ln ("calculator::execute");
            return !_done;
        }

        stack const & get_stack () /*const*/
        {
            _done = true;
            return _stack;
        }
    private:
        stack   _stack;
        bool    _done;
    };
} // namespace kx

int
main ()
{
    kx::calculator calc;
    bool status;
    do
    {
        // Prompt for input
        std::cout << "> ";
        kx::input input_;
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
