#include <cstddef>
#include <string>

#include "../test.hpp"
#include "iter.hpp"

static bool iter_test(void);

template<typename T>
static void print_element(T& e) {
	std::cout << e << ' ';
}

template<typename T>
static void inc_element(T& e) {
	++e;
}

int main() {
	bool   success = true;
	bool   (*tests[])(void) = {iter_test};
	size_t tests_count = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; success && i < tests_count; i += 1) {
		success = tests[i]();
		std::cout << '\n';
	}
	if (success)
		std::cout << "OK\n";
	return success;
}

// clang-format off
TEST_START(iter_test)
	TEST_LOGIC_START
		char		carr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
		int			iarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		std::string	sarr[] = {"one", "two", "three", "four", "five"};

		iter(carr, sizeof(carr) / sizeof(char), print_element);
		TEST_STDOUT("0 1 2 3 4 5 6 7 8 ")
		iter(carr, sizeof(carr) / sizeof(char), inc_element);
		iter(carr, sizeof(carr) / sizeof(char), print_element);
		TEST_STDOUT("1 2 3 4 5 6 7 8 9 ")

		iter(iarr, sizeof(iarr) / sizeof(int), print_element);
		TEST_STDOUT("1 2 3 4 5 6 7 8 9 10 ")
		iter(iarr, sizeof(iarr) / sizeof(int), inc_element);
		iter(iarr, sizeof(iarr) / sizeof(int), print_element);
		TEST_STDOUT("2 3 4 5 6 7 8 9 10 11 ")

		iter(sarr, sizeof(sarr) / sizeof(std::string), print_element);
		TEST_STDOUT("one two three four five ")
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END
// clang-format on
