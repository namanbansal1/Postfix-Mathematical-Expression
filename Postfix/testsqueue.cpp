#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "queue.h"

TEST_CASE("Queue_default_constructor", "[Queue][default_constructor]") {
	Queue<int> q;

	REQUIRE(q.isEmpty());
	REQUIRE(q.size() == 0);
}

TEST_CASE("Queue_copy_constructor", "[Queue][copy_constructor]") {
	Queue<int> q;

	for (int i = 0; i < 10; i++) {
		q.enqueue(i);
	}

	Queue<int> r(q);

	REQUIRE(r.size() == 10);

	for (int i = 0; i < 10; i++) {
		REQUIRE(r.dequeue() == i);
	}
}

TEST_CASE("Queue_assignment_operator", "[Queue][assignment_operator]") {
	Queue<int> q;

	for (int i = 0; i < 10; i++) {
		q.enqueue(i);
	}

	Queue<int> r;

	// Ensure the assignment operator is called
	r.operator=(q);

	for (int i = 0; i < 10; i++) {
		REQUIRE(r.dequeue() == i);
	}
}

TEST_CASE("Queue_peek", "[Queue][peek]") {
	Queue<int> q;

	for (int i = 0; i < 10; i++) {
		q.enqueue(i);
	}

	for (int i = 0; i < 10; i++) {
		REQUIRE(q.peek() == i);
		q.dequeue();
	}
}

TEST_CASE("Queue_peek_throws", "[Queue][peek][throws]") {
	Queue<int> q;

	REQUIRE_THROWS_AS(q.peek(), std::out_of_range);
}

TEST_CASE("Queue_enqueue", "[Queue][enqueue]") {
	Queue<int> q;

	for (int i = 0; i < 10; i++) {
		q.enqueue(i);
	}

	REQUIRE(q.size() == 10);
}

TEST_CASE("Queue_enqueue_dequeue", "[Queue][enqueue][dequeue]") {
	Queue<int> q;

	for (int i = 0; i < 10; i++) {
		q.enqueue(i);
	}

	REQUIRE(q.size() == 10);

	for (int i = 0; i < 10; i++) {
		REQUIRE(q.dequeue() == i);
	}

	REQUIRE(q.isEmpty());
}

TEST_CASE("Queue_enqueue_dequeue_large", "[Queue][enqueue][dequeue][large]") {
	Queue<int> q;

	for (int i = 0; i < 100; i++) {
		q.enqueue(i);
	}

	REQUIRE(q.size() == 100);

	for (int i = 0; i < 100; i++) {
		REQUIRE(q.dequeue() == i);
	}

	REQUIRE(q.isEmpty());
}

TEST_CASE("Queue_enqueue_after_dequeue", "[Queue][enqueue][after_dequeue]") {
	Queue<int> q;

	for (int i = 0; i < 10; i++) {
		q.enqueue(i);
	}

	REQUIRE(q.size() == 10);

	for (int i = 0; i < 5; i++) {
		q.dequeue();
	}

	REQUIRE(q.size() == 5);

	for (int i = 0; i < 5; i++) {
		q.enqueue(i);
	}

	REQUIRE(q.size() == 10);

	for (int i = 0; i < 5; i++) {
		REQUIRE(q.dequeue() == 5 + i);
	}

	REQUIRE(q.size() == 5);

	for (int i = 0; i < 5; i++) {
		REQUIRE(q.dequeue() == i);
	}

	REQUIRE(q.isEmpty());
}

TEST_CASE("Queue_dequeue_throws", "[Queue][dequeue][throws]") {
	Queue<int> q;

	REQUIRE_THROWS_AS(q.dequeue(), std::out_of_range);
}
