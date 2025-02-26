#include <cstddef>
#include <exception>
#include <streambuf>
#include <string>

#include "../test.hpp"
#include "Array.hpp"

static bool Array_default_constructor(void);
static bool Array_constructor(void);
static bool Array_copy_assignment(void);
static bool Array_copy_constructor(void);

int main() {
	bool   success = true;
	bool   (*tests[])(void) = {Array_default_constructor, Array_constructor, Array_copy_assignment,
							   Array_copy_constructor};
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
TEST_START(Array_copy_constructor)
	TEST_LOGIC_START
		Array<char>			ca1(10);
		Array<int>			ia1;
		Array<std::string>	sa1(4);

		for (unsigned i = 0; i < ca1.size(); i += 1)
			ca1[i] = i;
		Array<char>	ca2 = ca1;
		TEST_ASSERT(ca2.size() == ca1.size())
		for (unsigned i = 0; i < ca1.size(); i += 1)
			TEST_ASSERT(ca1[i] == ca2[i])
		ca1[9] = 'a';
		ca2[9] = 'b';
		TEST_ASSERT(ca1[9] != ca2[9])

		Array<int>	ia2 = ia1;
		TEST_ASSERT(ia2.size() == ia1.size())

		std::string const	strs[4] = {"one", "two", "three", "four"};
		for (unsigned i = 0; i < sa1.size(); i += 1)
			sa1[i] = strs[i];
		Array<std::string>	sa2 = sa1;
		TEST_ASSERT(sa2.size() == sa1.size())
		for (unsigned i = 0; i < sa1.size(); i += 1)
			TEST_ASSERT(sa1[i] == sa2[i])
		sa2[3] = "world";
		TEST_ASSERT(sa1[3] != sa2[3])
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(Array_copy_assignment)
	TEST_LOGIC_START
		Array<char>			ca1(10);
		Array<char>			ca2(3);
		Array<int>			ia1;
		Array<int>			ia2(10);
		Array<std::string>	sa1(4);
		Array<std::string>	sa2;

		for (unsigned i = 0; i < ca1.size(); i += 1)
			ca1[i] = i;
		ca2 = ca1;
		TEST_ASSERT(ca2.size() == ca1.size())
		for (unsigned i = 0; i < ca1.size(); i += 1)
			TEST_ASSERT(ca1[i] == ca2[i])
		ca1[9] = 'a';
		ca2[9] = 'b';
		TEST_ASSERT(ca1[9] != ca2[9])

		ia2 = ia1;
		TEST_ASSERT(ia2.size() == ia1.size())

		std::string const	strs[4] = {"one", "two", "three", "four"};
		for (unsigned i = 0; i < sa1.size(); i += 1)
			sa1[i] = strs[i];
		sa2 = sa1;
		TEST_ASSERT(sa2.size() == sa1.size())
		for (unsigned i = 0; i < sa1.size(); i += 1)
			TEST_ASSERT(sa1[i] == sa2[i])
		sa2[3] = "world";
		TEST_ASSERT(sa1[3] != sa2[3])
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(Array_constructor)
	TEST_LOGIC_START
		Array<char>			carr(1);
		Array<int>			iarr(10);
		Array<std::string>	sarr(5);

		for (unsigned i = 0; i < carr.size(); i += 1)
			TEST_ASSERT(carr[i] == '\0')
		carr[0] = 'a';
		TEST_ASSERT(carr[0] == 'a')
		TEST_ANY_EXCEPTION(carr[1])
		TEST_ANY_EXCEPTION(carr[1] = 'b')

		for (unsigned i = 0; i < iarr.size(); i += 1)
			TEST_ASSERT(iarr[i] == 0)
		for (unsigned i = 0; i < iarr.size(); i += 1)
			iarr[i] = i;
		for (unsigned i = 0; i < iarr.size(); i += 1)
			TEST_ASSERT(iarr[i] == static_cast<int>(i))
		TEST_ANY_EXCEPTION(iarr[11])
		TEST_ANY_EXCEPTION(iarr[11] = 2)

		for (unsigned i = 0; i < sarr.size(); i += 1)
			TEST_ASSERT(sarr[i].empty())
		std::string const	strs[5] = {"one", "two", "three", "four", "five"};
		for (unsigned i = 0; i < sarr.size(); i += 1)
			sarr[i] = strs[i];
		for (unsigned i = 0; i < sarr.size(); i += 1)
			TEST_ASSERT(sarr[i] == strs[i])
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(Array_default_constructor)
	TEST_LOGIC_START
		Array<char>			carr;
		Array<int>			iarr;
		Array<std::string>	sarr;

		TEST_ASSERT(carr.size() == 0)
		TEST_ANY_EXCEPTION(carr[0] = 'a')
		TEST_ANY_EXCEPTION(carr[0])

		TEST_ASSERT(iarr.size() == 0)
		TEST_ANY_EXCEPTION(iarr[0])
		TEST_ANY_EXCEPTION(iarr[0] = 1)

		TEST_ASSERT(sarr.size() == 0)
		TEST_ANY_EXCEPTION(sarr[0])
		TEST_ANY_EXCEPTION(sarr[0] = "test")
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END
// clang-format on
