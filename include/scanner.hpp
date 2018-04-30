#ifndef KX_SCANNER_HPP_INCLUDED_
#   define KX_SCANNER_HPP_INCLUDED_

namespace ecal
{
    enum expr_token
    {
        t_end,
        t_error,
        t_number,
        t_plus,
        t_mult
    };

    class scanner
    {
    public:
        // =======================
        // lifecycle
        // =======================
        scanner (char const * buf);

        // =======================
        // api
        // =======================
        expr_token  token () const;
        expr_token  accept ();

        double      number () const;
    private:
        // =======================
        // helpers
        // =======================
        void eat_white ();

        char const * const  _buf;
        int                 _look;
        expr_token          _token;
        double              _number;
    };
} // namespace ecal
# endif // KX_SCANNER_HPP_INCLUDED_
