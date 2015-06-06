//ArrayQueue.hpp
#ifndef _ARRAYQUEUE_HPP
#define _ARRAYQUEUE_HPP

#include "BagOfPuzzleStates.hpp"

// This skeleton file (along with the .cpp) is
// here to help get you started, but you are
// free to change function signatures, etc.
// as long as ArrayQueue is some subtype
// of BagOfPuzzleStates
class ArrayQueue: public BagOfPuzzleStates
{
 public:
  ArrayQueue(); // constructor
  
  // TodoList interface
  void add(PuzzleState *elem);
  PuzzleState *remove();
  bool is_empty();

  ~ArrayQueue(); // destructor

  static const int INIT_SIZE = 15 ;
 private:
  // A helper function that consumes a number and ensures the queue
  // has enough space for that many elements.
  void ensure_capacity(int n);

  // a pointer to the underlying array with elements of type (PuzzleState *)
  // use an explicit pointer, NOT PuzzleState *array[..] so you can resize.
  PuzzleState **array;

  // TODO: list additional private member variables here,

  // the index of the element currently at the front of the ArrayQueue
  int front;

  // the index of the element currently at the back of the ArrayQueue
  int back;  

  // how many elements the queue is capable of holding in the underlying array
  int capacity;
 
};


#endif
