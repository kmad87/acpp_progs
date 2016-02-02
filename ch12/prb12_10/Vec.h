#pragma once

#include <memory>
#include <algorithm>
#include <cctype>

template <class T>
class Vec {
    public:
        typedef size_t size_type;
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef ptrdiff_t difference_type;
        typedef T value_type;

        size_type size() {avail - data;}
        
        T& operator[](size_type i) {return data[i];}
        const T& operator[](size_type i) {return data[i];}

        explicit Vec(size_type n, const T& val) {create(n, val);}
        Vec() {create();}
        Vec(const Vec& v) {create(v.begin(), v.end());}
        template<class In>
            Vec(In b, In e) {create(b, e);}

        Vec& operator=(const Vec&);

        ~Vec() {uncreate();}



    private:
        iterator data;
        iterator avail;
        iterator limit;

        std::allocator<T> alloc;

        void create();
        void create(size_type, const T&);
        void create(const_iterator, const_iterator);
};

template<class T>
void Vec<T>::create() {
    data = avail = limit = 0;
}

template<class T>
void Vec<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);
    std::uninitialized_fill(n, val);
    avail = limit = data + n;
}

template<class T>
void Vec<T>::create(const_iterator b, const_iterator e)
{
    data = alloc.allocate(e - b);
    avail = limit = std::uninitialized_copy(b, e, data);
}

template<class T>
void Vec<T>::uncreate()
{
}
