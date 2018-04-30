#ifndef KX_PARSER_HPP_INCLUDED_
#   define KX_PARSER_HPP_INCLUDED_

namespace ecal
{
    enum status
    {
        st_ok,
        st_quit,
        st_error
    };

    class scanner;
    class symbol_table;

    class parser
    {
    public:
        // =====================
        // lifecycle
        // =====================
        parser (
            scanner & scanner_,
            symbol_table & sym_tab_
        );
        ~parser ();

        // =====================
        // api
        // =====================
        status eval ();
    private:
        scanner &       _scanner;
        symbol_table &  _sym_tab;
    };
} // namespace ecal
#endif // KX_PARSER_HPP_INCLUDED_
