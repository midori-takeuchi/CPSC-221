//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
  // empty, nothing to do 
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since list is not dynamically allocated
}

void HeapPriorityQueue::add(PuzzleState *elem) { 
  heap.push_back(elem);

  swap_up(size() - 1);
}

PuzzleState * HeapPriorityQueue::remove() {
    assert(size() > 0);
    PuzzleState *returnVal = heap[0];
    heap[0] = heap[size()-1];

    // Just inserting the last element in the array into the first index
    // and removing it from the end of the array
    heap.pop_back();
    swap_down(0);
    return returnVal;	
}

void HeapPriorityQueue::swap_up(int ix) {
    // stop swapping if element is at the root node
    if (is_root(ix)) return;//return ix;
    int parent = parent_(ix);
    // keep swapping up until the condition no longer holds
    if (heap[ix] < heap[parent]) {
	PuzzleState *temp = heap[ix];
	heap[ix] = heap[parent];
	heap[parent] = temp;
	swap_up(parent);
     }
}
  
void HeapPriorityQueue::swap_down(int ix) {
    // Stop swapping if the element is at a leaf node
    if (is_leaf(ix)) return;//return ix;
    int rightChild = right_child(ix), leftChild = left_child(ix), swap_index = ix;
    // Find which child has the smaller value
    if (heap[ix] >= heap[leftChild]) 
	swap_index = leftChild;
    if (num_child(ix) == 2) {
	if (heap[swap_index] >= heap[rightChild])
	  swap_index = rightChild;
	}
    // Swap down until the children are greater than the parent
    if (swap_index != ix) {
	PuzzleState *temp = heap[ix];
	heap[ix] = heap[swap_index];
	heap[swap_index] = temp;
	swap_down(swap_index);
	}
  }

PuzzleState *HeapPriorityQueue::get_next() {
  if (heap.size() < 1) 
	return NULL;
  return heap[1];
}

bool HeapPriorityQueue::is_empty() {
   return (heap.size() == 0);
}

int HeapPriorityQueue::size() {
  return int(heap.size());
}

int HeapPriorityQueue::parent_(int index) {
  return int((index-1)/2);
}

bool HeapPriorityQueue::is_root(int index) {
  return (index == 0);
}

bool HeapPriorityQueue::is_leaf(int index) {
    return (num_child(index) == 0);
}

int HeapPriorityQueue::left_child(int index) {
    return (2*index +1);
}

int HeapPriorityQueue::right_child(int index) {
    return (2*index +2);
}

int HeapPriorityQueue::num_child(int index) {
    int children = 0;
    if (left_child(index) < size()) children++;
    if (right_child(index) < size()) children++;
    return children;
}


#endif
