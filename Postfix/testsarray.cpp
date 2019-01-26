#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "arrayclass.h"

TEST_CASE("ArrayClass_default_constructor", "[ArrayClass][default_constructor]") {
	ArrayClass<int> a;

	REQUIRE(a.empty());
	REQUIRE(a.size() == 0);
}

TEST_CASE("ArrayClass_capacity_constructor", "[ArrayClass][capacity_constructor]") {
	ArrayClass<int> a{ 16 };

	REQUIRE(a.empty());
	REQUIRE(a.capacity() == 16);
}

TEST_CASE("ArrayClass_copy_constructor", "[ArrayClass][copy_constructor]") {
	ArrayClass<int> a;

	a.pushBack(1);
	a.pushBack(2);
	a.pushBack(3);

	ArrayClass<int> b{ a };

	REQUIRE(b.size() == 3);
	REQUIRE(b.back() == 3);
	b.popBack();
	REQUIRE(b.size() == 2);
	REQUIRE(b.back() == 2);
	b.popBack();
	REQUIRE(b.size() == 1);
	REQUIRE(b.back() == 1);
	b.popBack();
	REQUIRE(b.empty());
}

TEST_CASE("ArrayClass_assignment_operator", "[ArrayClass][assignment_operator]") {
	ArrayClass<int> a;

	a.pushBack(1);
	a.pushBack(2);
	a.pushBack(3);

	ArrayClass<int> b;
	// Ensure the copy is not elided
	b.operator=(a);

	for (int i = 0; i < 3; i++) {
		REQUIRE(b[i] == a[i]);
	}
}

TEST_CASE("ArrayClass_resize_down", "[ArrayClass][resize_down]") {
	ArrayClass<int> a;

	a.pushBack(1);
	a.pushBack(2);
	a.pushBack(3);
	a.pushBack(4);
	a.pushBack(5);

	a.resize(3);

	REQUIRE(a.size() == 3);

	for (int i = 0; i < 3; i++) {
		REQUIRE(a[i] == i + 1);
	}
}

TEST_CASE("ArrayClass_resize_up", "[ArrayClass][resize_up]") {
	ArrayClass<int> a;

	a.pushBack(1);
	a.pushBack(2);
	a.pushBack(3);
	a.pushBack(4);
	a.pushBack(5);

	a.resize(10);

	REQUIRE(a.size() == 5);

	for (int i = 0; i < 5; i++) {
		REQUIRE(a[i] == i + 1);
	}
}

TEST_CASE("ArrayClass_shrinkToFit", "[ArrayClass][shrinkToFit]") {
	ArrayClass<int> a{ 16 };

	REQUIRE(a.capacity() == 16);

	for (int i = 1; i <= 5; i++) {
		a.pushBack(i);
	}

	a.shrinkToFit();

	REQUIRE(a.capacity() == 5);
}

TEST_CASE("ArrayClass_operator_brackets", "[ArrayClass][operator_brackets]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	for (int i = 0; i < 10; i++) {
		REQUIRE(a[i] == i);
	}
}

TEST_CASE("ArrayClass_operator_brackets_throws", "[ArrayClass][operator_brackets][throws]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	REQUIRE_THROWS_AS(a[10], std::out_of_range);
}

TEST_CASE("ArrayClass_at", "[ArrayClass][at]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	for (int i = 0; i < 10; i++) {
		REQUIRE(a.at(i) == i);
	}
}

TEST_CASE("ArrayClass_at_throws", "[ArrayClass][at][throws]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	REQUIRE_THROWS_AS(a.at(10), std::out_of_range);
}

TEST_CASE("ArrayClass_front", "[ArrayClass][front]") {
	ArrayClass<int> a;

	a.pushBack(1);
	a.pushBack(2);
	a.pushBack(3);

	REQUIRE(a.front() == 1);
}

TEST_CASE("ArrayClass_front_throws", "[ArrayClass][front][throws]") {
	ArrayClass<int> a;

	REQUIRE_THROWS_AS(a.front(), std::out_of_range);
}

TEST_CASE("ArrayClass_back", "[ArrayClass][back]") {
	ArrayClass<int> a;

	a.pushBack(1);
	a.pushBack(2);
	a.pushBack(3);

	REQUIRE(a.back() == 3);
}

TEST_CASE("ArrayClass_back_throws", "[ArrayClass][back][throws]") {
	ArrayClass<int> a;

	REQUIRE_THROWS_AS(a.back(), std::out_of_range);
}

TEST_CASE("ArrayClass_pushBack", "[ArrayClass][pushBack]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	REQUIRE(a.size() == 10);

	for (int i = 0; i < 10; i++) {
		REQUIRE(a[i] == i);
	}
}

TEST_CASE("ArrayClass_pushBack_large", "[ArrayClass][pushBack][large]") {
	ArrayClass<int> a;

	for (int i = 0; i < 100; i++) {
		a.pushBack(i);
	}

	REQUIRE(a.size() == 100);
	REQUIRE(a.capacity() >= 100);

	for (int i = 0; i < 100; i++) {
		REQUIRE(a[i] == i);
	}
}

TEST_CASE("ArrayClass_popBack", "[ArrayClass][popBack]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	for (int i = 0; i < 5; i++) {
		a.popBack();
	}

	REQUIRE(a.size() == 5);
	REQUIRE(a.back() == 4);
}

TEST_CASE("ArrayClass_popBack_empty", "[ArrayClass][popBack][empty]") {
	ArrayClass<int> a;

	a.popBack();

	REQUIRE(a.size() == 0);
	REQUIRE(a.empty());
}

TEST_CASE("ArrayClass_insert", "[ArrayClass][insert]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	a.insert(4, 100);
	a.insert(5, 200);

	for (int i = 0; i < 4; i++) {
		REQUIRE(a[i] == i);
	}

	REQUIRE(a[4] == 100);
	REQUIRE(a[5] == 200);

	for (int i = 6; i < 12; i++) {
		REQUIRE(a[i] == i - 2);
	}
}

TEST_CASE("ArrayClass_insert_end", "[ArrayClass][insert][end]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.insert(i, i);
	}

	for (int i = 0; i < 10; i++) {
		REQUIRE(a[i] == i);
	}
}

TEST_CASE("ArrayClass_insert_throws", "[ArrayClass][insert][throws]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	REQUIRE_THROWS_AS(a.insert(100, 100), std::out_of_range);
}

TEST_CASE("ArrayClass_erase", "[ArrayClass][erase]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	a.erase(4);

	REQUIRE(a.size() == 9);

	for (int i = 0; i < 4; i++) {
		REQUIRE(a[i] == i);
	}

	for (int i = 4; i < 9; i++) {
		REQUIRE(a[i] == i + 1);
	}
}

TEST_CASE("ArrayClass_erase_throws", "[ArrayClass][erase][throws]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	REQUIRE_THROWS_AS(a.erase(10), std::out_of_range);
	REQUIRE_THROWS_AS(a.erase(100), std::out_of_range);
}

TEST_CASE("ArrayClass_startFrom", "[ArrayClass][startFrom]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	a.startFrom(5);

	for (int i = 0; i < 10; i++) {
		REQUIRE(a[(i + 5) % 10] == i);
	}
}

TEST_CASE("ArrayClass_startFrom_at_start", "[ArrayClass][startFrom][at_start]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	a.startFrom(0);

	for (int i = 0; i < 10; i++) {
		REQUIRE(a[i] == i);
	}
}

TEST_CASE("ArrayClass_startFrom_out_of_range", "[ArrayClass][startFrom][out_of_range]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	a.startFrom(10);

	for (int i = 0; i < 10; i++) {
		REQUIRE(a[i] == i);
	}
}

TEST_CASE("ArrayClass_startFrom_far_out_of_range", "[ArrayClass][startFrom][far_out_of_range]") {
	ArrayClass<int> a;

	for (int i = 0; i < 10; i++) {
		a.pushBack(i);
	}

	a.startFrom(100);

	for (int i = 0; i < 10; i++) {
		REQUIRE(a[i] == i);
	}
}
