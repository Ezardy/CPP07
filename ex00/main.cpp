#include <string>

#include "../test.hpp"
#include "whatever.hpp"

static bool swap_test(void);
static bool min_test(void);
static bool max_test(void);
static bool default_test(void);

int main() {
	bool   success = true;
	bool   (*tests[])(void) = {swap_test, min_test, max_test, default_test};
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
TEST_START(default_test)
	TEST_LOGIC_START
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

		expected =
			"a = 3, b = 2\n"
			"min( a, b ) = 2\n"
			"max( a, b ) = 3\n"
			"c = chaine2, d = chaine1\n"
			"min( c, d ) = chaine1\n"
			"max( c, d ) = chaine2\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(max_test)
	TEST_LOGIC_START
		char		ca = 'a';
		char		cb = 'b';
		int			ia = 1;
		int			ib = 20;
		std::string	sa = "Apollo";
		std::string	sb = "Bioshock";

		TEST_ASSERT(&max(cb, ca) == &cb)
		TEST_ASSERT(&max(ca, cb) == &cb)

		TEST_ASSERT(&max(ib, ia) == &ib)
		TEST_ASSERT(&max(ia, ib) == &ib)

		TEST_ASSERT(&::max(sb, sa) == &sb)
		TEST_ASSERT(&::max(sa, sb) == &sb)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(min_test)
	TEST_LOGIC_START
		char		ca = 'a';
		char		cb = 'b';
		int			ia = 1;
		int			ib = 20;
		std::string	sa = "Apollo";
		std::string	sb = "Bioshock";

		TEST_ASSERT(&min(cb, ca) == &ca)
		TEST_ASSERT(&min(ca, cb) == &ca)

		TEST_ASSERT(&min(ib, ia) == &ia)
		TEST_ASSERT(&min(ia, ib) == &ia)

		TEST_ASSERT(&::min(sb, sa) == &sa)
		TEST_ASSERT(&::min(sa, sb) == &sa)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(swap_test)
	TEST_LOGIC_START
		char		ca = 'a';
		char		cb = 'b';
		int			ia = 1;
		int			ib = 20;
		std::string	sa = "Apollo";
		std::string	sb = "Bioshock";

		swap(ca, cb);
		TEST_ASSERT(ca == 'b')
		TEST_ASSERT(cb == 'a')

		swap(ia, ib);
		TEST_ASSERT(ia == 20)
		TEST_ASSERT(ib == 1)

		::swap(sa, sb);
		TEST_ASSERT(sa == "Bioshock")
		TEST_ASSERT(sb == "Apollo")
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END
// clang-format on
