// file: 2jjalloc.h
#ifndef _JJALLOC_
#define _JJALLOC_

#include <new>          // for placement new
#include <cstddef>      // for ptrdiff_t, size_t
#include <cstdlib>      // for exit
#include <climits>      // for UINT_MAX
#include <iostream>     // for cerr

namespace JJ
{

template <class T>
inline T* _allocate(ptrdiff_t size, T*) {
    std::set_new_handler(0); // 作用：将new操作失败时的处理函数设为0，即不处理
    T* tmp = (T*)(::operator new((size_t)(size * sizeof(T))));  // ::operator new is a global function
                                                                // that allocates memory.
                                                                // It is called with the size of the memory to be allocated.
                                                                // It returns a pointer to the allocated memory.
    if (tmp == 0) {
        std::cerr << "out of memory" << std::endl;    // cerr is an object of class ostream
        exit(1);
    }
    return tmp;
}

// deallocate memory
template <class T>
inline void _deallocate(T* buffer) {
    ::operator delete(buffer);
}

// construct a new object
template <class T1, class T2>
inline void _construct(T1* p, const T2& value) {
    new(p) T1(value);   // 使用placement new在已分配的内存上构造对象
}

// destroy an object
template <class T>
inline void _destroy(T* ptr) {
    ptr->~T();
}

// a simple allocator
template <class T>
class allocator {
public:
    typedef T           value_type;
    typedef T*          pointer;
    typedef const T*    const_pointer;
    typedef T&          reference;
    typedef const T&    const_reference;
    typedef size_t      size_type;
    typedef ptrdiff_t   difference_type;

    // rebind allocator of type U
    template <class U>
    struct rebind {
        typedef allocator<U> other;
    };

    // hint used for locality. ref.[Austern], p189
    pointer allocate(size_type n, const void* hint = 0) {
        return _allocate((difference_type)n, (pointer)0);
    }

    void deallocate(pointer p, size_type n) {
        _deallocate(p);
    }

    void construct(pointer p, const T& value) {
        _construct(p, value);
    }

    void destroy(pointer p) {
        _destroy(p);
    }

    pointer address(reference x) {
        return (pointer)&x;
    }

    const_pointer const_address(const_reference x) {
        return (const_pointer)&x;
    }

    size_type max_size() const {
        return size_type(UINT_MAX / sizeof(T)); 
    }

};

}   // end of namespace JJ

#endif