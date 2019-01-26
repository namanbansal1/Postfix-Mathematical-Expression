

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "arrayclass.h"

template <typename T>
class Queue
{
  private:
    unsigned int front;       // starting index of queue
    unsigned int _size;        // number of items stored in queue
    ArrayClass<T> ac;

    #include "queueprivate.h" // define and implement your private
                              // member functions in this file

  public:
    // default constructor
    Queue();

    // copy constructor
    Queue(const Queue& qq);

    // assignment operator
    Queue& operator=(const Queue& qq);

    ///////////////
    // accessors //
    ///////////////

    // Return true if the queue contains no items
    bool isEmpty() const;

    // Returns the number of items stored in the queue
    unsigned int size() const;

    // Return a reference to the front item of the queue
    // Throws an out_of_range exception if the queue is empty
    T& peek();

    //////////////
    // mutators //
    //////////////

    // Inserts an item to the back of the queue
    void enqueue(const T item);

    // Removes and returns (a copy of) the front item of the queue
    // Throws an out_of_range exception if the queue is empty
    T dequeue();
};

#include "queue.cpp"

#endif