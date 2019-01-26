#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "stack.h"

TEST_CASE("Stack_default_constructor", "[Stack][default_constructor]") {
	Stack<int> s;

	REQUIRE(s.isEmpty());
	REQUIRE(s.size() == 0);
}

TEST_CASE("Stack_copy_constructor", "[Stack][copy_constructor]") {
	Stack<int> s;

	for (int i = 0; i < 10; i++) {
		s.push(i);
	}

	Stack<int> t(s);

	REQUIRE(t.size() == 10);

	for (int i = 9; i >= 0; i--) {
		REQUIRE(t.pop() == i);
	}
}

TEST_CASE("Stack_assignment_operator", "[Stack][assignment_operator]") {
	Stack<int> s;

	for (int i = 0; i < 10; i++) {
		s.push(i);
	}

	Stack<int> t;
	t.operator=(s);

	REQUIRE(t.size() == 10);

	for (int i = 9; i >= 0; i--) {
		REQUIRE(t.pop() == i);
	}
}

TEST_CASE("Stack_peek", "[Stack][peek]") {
	Stack<int> s;

	for (int i = 0; i < 10; i++) {
		s.push(i);
	}

	for (int i = 9; i >= 0; i--) {
		REQUIRE(s.peek() == i);
		s.pop();
	}
}

TEST_CASE("Stack_peek_throws", "[Stack][peek][throws]") {
	Stack<int> s;

	REQUIRE_THROWS_AS(s.peek(), std::out_of_range);
}

TEST_CASE("Stack_push", "[Stack][push]") {
	Stack<int> s;

	for (int i = 0; i < 10; i++) {
		s.push(i);
	}

	REQUIRE(s.size() == 10);
}

TEST_CASE("Stack_pop", "[Stack][pop]") {
	Stack<int> s;

	for (int i = 0; i < 10; i++) {
		s.push(i);
	}

	for (int i = 9; i >= 0; i--) {
		REQUIRE(s.pop() == i);
	}

	REQUIRE(s.isEmpty());
}

TEST_CASE("Stack_pop_throws", "[Stack][pop][throws]") {
	Stack<int> s;

	REQUIRE_THROWS_AS(s.pop(), std::out_of_range);
}
