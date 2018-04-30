#ifndef KX_STACK_FF_HPP_INCLUDED_
#   define KX_STACK_FF_HPP_INCLUDED_

#include <iostream>
#include <cassert>

namespace kx
{
    template<class T> class stack_ff_range;

    template<class T>
    class stack_ff
    {
        friend class stack_ff_range<T>;
    public:
        // ===========================
        // member types
        // ===========================

        typedef int                 size_type;
        typedef T                   value_type;
        typedef T &                 reference;
        typedef T const &           const_reference;
        typedef stack_ff_range<T>   range;
        // ===========================
        // lifecycle
        // ===========================
        explicit stack_ff (size_type capacity);
        ~stack_ff ();

        // ===========================
        // element access
        // ===========================
        reference       top ();
        const_reference top ()   const;

        // ===========================
        // capacity
        // ===========================
        bool            is_empty () const;
        bool            is_full () const;
        size_type       size ()  const;
        size_type       capacity ()  const;

        // ===========================
        // modifiers
        // ===========================
        void push (value_type value);
        void pop ();
        void clear ();
    private: // data
        value_type *    _data;
        size_type       _size;
        size_type       _capacity;
    };

    template<class T>
    class stack_ff_range
    {
    public:
        // ===========================
        // member types
        // ===========================
        typedef stack_ff<T> stack_type;
        typedef T const &   const_reference;
        typedef int         size_type;
        // ===========================
        // lifecycle
        // ===========================
        stack_ff_range (stack_type const & stack);

        // ===========================
        // access
        // ===========================
        const_reference get () const;

        // ===========================
        // traversal
        // ===========================
        bool at_end () const;
        void advance ();
    private:
        stack_type const &  _stack;
        size_type           _current;
    };

    template<class T>
    stack_ff_range<T> begin (stack_ff<T> const & stack);
    // ===========================
    // stack_ff implementation
    // ===========================
    // lifecycle
    // ===========================

    template<class T>
    stack_ff<T>::stack_ff (
        stack_ff<T>::size_type capacity
    )
        :   _data (nullptr)
        ,   _size (0)
        ,   _capacity (capacity)
    {
        assert (_capacity > 0);
        _data = new T[_capacity];
    }

    template<class T>
    stack_ff<T>::~stack_ff ()
    {
        delete [] _data;
    }

    // ===========================
    // element access
    // ===========================
    template<class T>
    typename stack_ff<T>::reference
    stack_ff<T>::top ()
    {
        assert (_size > 0);
        return _data [_size - 1];
    }

    template<class T>
    typename stack_ff<T>::const_reference
    stack_ff<T>::top ()
    const
    {
        assert (_size > 0);
        return _data [_size - 1];
    }

    // ===========================
    // capacity
    // ===========================
    template<class T>
    bool
    stack_ff<T>::is_empty ()
    const
    {
        return (0 == _size);
    }

    template<class T>
    bool
    stack_ff<T>::is_full ()
    const
    {
        return (_size == _capacity);
    }

    template<class T>
    typename stack_ff<T>::size_type
    stack_ff<T>::size ()
    const
    {
        return _size;
    }

    template<class T>
    typename stack_ff<T>::size_type
    stack_ff<T>::capacity ()
    const
    {
        return _capacity;
    }

    // ===========================
    // modifiers
    // ===========================
    template<class T>
    void
    stack_ff<T>::push (
        stack_ff<T>::value_type value
    )
    {
        assert (_size + 1 < _capacity);
        _data [_size] = value;
        ++_size;
    }

    template<class T>
    void
    stack_ff<T>::pop ()
    {
        assert (_size > 0);
        --_size;
    }

    template<class T>
    void
    stack_ff<T>::clear ()
    {
        _size = 0;
    }

    // ===========================
    // helpers
    // ===========================


    // ===========================
    // stack_ff_range implementation
    // ===========================
    // lifecycle
    // ===========================
    template<class T>
    stack_ff_range<T>::stack_ff_range (
        stack_ff_range<T>::stack_type const & stack
    )
        :   _stack (stack)
        ,   _current (0)
    {}

    // ===========================
    // access
    // ===========================
    template<class T>
    typename stack_ff_range<T>::const_reference
    stack_ff_range<T>::get ()
    const
    {
        return _stack._data [_current];
    }

    // ===========================
    // traversal
    // ===========================
    template<class T>
    bool
    stack_ff_range<T>::at_end ()
    const
    {
        return _current == _stack.size ();
    }

    template<class T>
    void
    stack_ff_range<T>::advance ()
    {
        assert (!at_end ());
        ++_current;
    }

    template<class T>
    stack_ff_range<T> begin (
        stack_ff<T> const & stack
    )
    {
        return stack_ff_range<T> (stack);
    }
} // namespace kx

#endif // KX_STACK_FF_HPP_INCLUDED_
