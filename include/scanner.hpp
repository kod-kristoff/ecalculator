#ifndef KX_SCANNER_HPP_INCLUDED_
#   define KX_SCANNER_HPP_INCLUDED_

namespace ecal
{
    class scanner
    {
    public:
        // =======================
        // lifecycle
        // =======================
        scanner (char const * buf);
    private:
        char const * const _buf;
    };
} // namespace ecal
# endif // KX_SCANNER_HPP_INCLUDED_
