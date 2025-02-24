#ifndef EX00_WHATEVER_HPP
#define EX00_WHATEVER_HPP

template<typename T>
void swap(T& a, T& b) {
	T const tmp = a;

	a = b;
	b = tmp;
}

template<typename T>
T const& min(T const& a, T const& b) {
	return a < b ? a : b;
}

template<typename T>
T const& max(T const& a, T const& b) {
	return a > b ? a : b;
}

#endif
