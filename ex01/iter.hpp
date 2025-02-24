#ifndef EX01_ITER_HPP
#define EX01_ITER_HPP

#include <cstddef>

template<typename T>
void iter(T* arr, std::size_t len, void (*f)(T& e)) {
	for (std::size_t i = 0; i < len; i += 1)
		f(arr[i]);
}

template<typename T>
void iter(T const* arr, std::size_t len, void (*f)(T const& e)) {
	for (std::size_t i = 0; i < len; i += 1)
		f(arr[i]);
}
#endif
