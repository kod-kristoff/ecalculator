#ifndef ECAL_INPUT_HPP_
#   define ECAL_INPUT_HPP_

#include "input_fwd.hpp"

namespace ecal
{
    const int max_buf       = 100;

    const int token_number  = 1;
    const int token_error   = 2;
    class input
    {
    public:
        input ();

        int
        token ()
        const;

        int
        number ()
        const;
    private:
        int     _token;
        char    _buf [max_buf];
    };
} // namespace ecal
#endif // ECAL_INPUT_HPP_
