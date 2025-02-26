#ifndef EX02_ARRAY_HPP
#define EX02_ARRAY_HPP

#include <cstddef>
#include <exception>
#include <new>

template<typename T>
class Array {
public:
	Array(void) throw();
	Array(unsigned n) throw(std::bad_alloc);
	Array(Array const& other) throw(std::bad_alloc);
	~Array(void) throw();

	Array&	 operator=(Array const& other) throw(std::bad_alloc);
	T&		 operator[](long idx) throw(std::exception);
	T const& operator[](long idx) const throw(std::exception);

	unsigned size(void) const throw();

private:
	unsigned s;
	T*		 arr;
};

#include "Array.tpp"
#endif
