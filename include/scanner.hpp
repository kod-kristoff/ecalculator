#ifndef KX_SCANNER_HPP_INCLUDED_
#   define KX_SCANNER_HPP_INCLUDED_

namespace ecal
{
    enum expr_token
    {
        t_end,
        t_error,
        t_number,   // literal number
        t_plus,     // +
        t_mult,     // *
        t_minus,    // -
        t_divide,   // /
        t_l_paren,  // (
        t_r_paren,  // )
        t_assign,   // =
        t_ident     // identifier (symbolic name)
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
        void        symbol_name (
            char *  str_out,
            int &   len);
    private:
        // =======================
        // helpers
        // =======================
        void eat_white ();

        char const * const  _buf;
        int                 _look;
        expr_token          _token;
        double              _number;
        int                 _symbol_len;
        int                 _symbol;
    };
} // namespace ecal
# endif // KX_SCANNER_HPP_INCLUDED_
