#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "interpreter.h"

TEST_CASE("Interpreter_default_constructor", "[Interpreter][default_constructor]") {
	Interpreter i;

	REQUIRE(!i.hasMoreInstructions());
}

TEST_CASE("Interpreter_copy_constructor", "[Interpreter][copy_constructor]") {
	Interpreter i;

	i.load("");

	Interpreter j(i);

	REQUIRE(j.hasMoreInstructions());
}

TEST_CASE("Intepreter_assignment_operator", "[Interpreter][assignment_operator]") {
	Interpreter i;

	i.load("");

	Interpreter j;
	j.operator=(i);

	REQUIRE(j.hasMoreInstructions());
}

TEST_CASE("Interpreter_hasMoreInstructions", "[Interpreter][hasMoreInstructions]") {
	Interpreter i;

	i.load("");

	REQUIRE(i.hasMoreInstructions());

	i.next();

	REQUIRE(!i.hasMoreInstructions());
}

TEST_CASE("Interpreter_load", "[Interpreter][load]") {
	Interpreter i;

	i.load("#");
	i.load("#");

	for (int x = 0; x < 4; x++) {
		REQUIRE(i.hasMoreInstructions());

		i.next();
	}

	REQUIRE(!i.hasMoreInstructions());
}

TEST_CASE("Interpreter_next", "[Interpreter][next]") {
	Interpreter i;

	i.load("#");

	i.next();

	REQUIRE(i.hasMoreInstructions());

	i.next();

	REQUIRE(!i.hasMoreInstructions());
}

TEST_CASE("Interpreter_run", "[Interpreter][next]") {
	Interpreter i;

	i.load("#");

	REQUIRE(i.run() == "\n");

	REQUIRE(!i.hasMoreInstructions());
}

TEST_CASE("Interpreter_clear", "[Interpreter][clear]") {
	Interpreter i;

	i.load("");

	i.clear();

	REQUIRE(!i.hasMoreInstructions());
}

TEST_CASE("Interpreter_plus", "[Interpreter][plus]") {
	Interpreter i;

	i.load("1 2 + PRINT");

	REQUIRE(i.run() == "# 3");
}

TEST_CASE("Interpreter_minus", "[Interpreter][minus]") {
	Interpreter i;

	i.load("2 1 - PRINT");

	REQUIRE(i.run() == "# 1");
}

TEST_CASE("Interpreter_times", "[Interpreter][times]") {
	Interpreter i;

	i.load("2 3 * PRINT");

	REQUIRE(i.run() == "# 6");
}

TEST_CASE("Interpreter_over", "[Interpreter][over]") {
	Interpreter i;

	i.load("10 5 / PRINT");

	REQUIRE(i.run() == "# 2");
}

TEST_CASE("Interpreter_power", "[Interpreter][power]") {
	Interpreter i;

	i.load("2 3 ^ PRINT");

	REQUIRE(i.run() == "# 8");
}

TEST_CASE("Interpreter_rq", "[Interpreter][rq]") {
	Interpreter i;

	i.load("4 3 RQ # 2 1 RQ");

	REQUIRE(i.run() == "3 4\n1 2 3 4\n");
}

TEST_CASE("Interpreter_print", "[Interpreter][print]") {
	Interpreter i;

	i.load("PRINT 1 2");

	REQUIRE(i.run() == "1 2 #");
}

TEST_CASE("Interpreter_error", "[Interpreter][error]") {
  Interpreter i;
  
  i.load("+");
  
  REQUIRE_THROWS(i.run());
}

// Pause case is implicitly tested through the tests for the next function
