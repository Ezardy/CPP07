#ifndef EX02_ARRAY_TPP
#define EX02_ARRAY_TPP

#include <cstddef>
#include <exception>
#include <stdexcept>

template<typename T>
Array<T>::Array(void) throw() : s(0), arr(NULL) {
}

template<typename T>
Array<T>::Array(unsigned n) throw(std::bad_alloc) : s(n), arr(new T[n]()) {
}

template<typename T>
Array<T>::Array(Array const& other) throw(std::bad_alloc) : arr(NULL) {
	*this = other;
}

template<typename T>
Array<T>& Array<T>::operator=(Array const& other) throw(std::bad_alloc) {
	if (this != &other) {
		delete[] arr;
		arr = new T[other.s];
		s = other.s;
		for (unsigned i = 0; i < s; i += 1)
			arr[i] = other.arr[i];
	}
	return *this;
}

template<typename T>
Array<T>::~Array(void) throw() {
	delete[] arr;
}

template<typename T>
T& Array<T>::operator[](long idx) throw(std::exception) {
	if (idx >= 0 && idx < s)
		return arr[idx];
	else
		throw std::exception();
}

template<typename T>
T const& Array<T>::operator[](long idx) const throw(std::exception) {
	if (idx >= 0 && idx < s)
		return arr[idx];
	else
		throw std::exception();
}

template<typename T>
unsigned Array<T>::size(void) const throw() {
	return s;
}

#endif
