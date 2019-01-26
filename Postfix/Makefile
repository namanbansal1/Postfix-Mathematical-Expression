# Settings
CXX := clang++
CXXFLAGS := -g -Wall -std=c++1y -stdlib=libc++

# Utility variables
OBJS := testsinterpreter.o testsqueue.o testsstack.o testsarray.o interpreter.o

# Utility targets
all: testsinterpreter testsqueue testsstack testsarray

clean:
	$(RM) $(OBJS)
	$(RM) testsinterpreter
	$(RM) testsqueue
	$(RM) testsstack
	$(RM) testsarray

# Binary targets
testsinterpreter: testsinterpreter.o interpreter.o
	$(CXX) $(CXXFLAGS) -g -o $@ $^
	
testsqueue: testsqueue.o
	$(CXX) $(CXXFLAGS) -g -o $@ $^
	
testsstack: testsstack.o
	$(CXX) $(CXXFLAGS) -g -o $@ $^
	
testsarray: testsarray.o
	$(CXX) $(CXXFLAGS) -g -o $@ $^

# Object targets
testsinterpreter.o : testsinterpreter.cpp catch.hpp interpreter.h

testsqueue.o : testsqueue.cpp catch.hpp queue.h

testsstack.o : testsstack.cpp catch.hpp stack.h

testsarray.o : testsarray.cpp catch.hpp arrayclass.h

interpreter.o: interpreter.h

# Dependency "targets"
arrayclass.h: arrayclassprivate.h arrayclass.cpp
	touch $@

stack.h: arrayclass.h stackprivate.h stack.cpp
	touch $@

queue.h: arrayclass.h queueprivate.h queue.cpp
	touch $@

interpreter.h: stack.h queue.h interpreterprivate.h
	touch $@

# Mark utility targets as phony
.PHONY: all clean