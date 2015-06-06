//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
LinkedListQueue::LinkedListQueue()
{
  front = NULL;
  back = NULL;
}

void LinkedListQueue::add(PuzzleState *elem)
{
  node *temp = new node;
    temp->data = elem;
    temp->next = NULL;
    if (front == NULL) {
       front = temp;
    } else {
      back->next = temp;
    }
    back = temp;
}

PuzzleState *LinkedListQueue::remove()
{
  assert(front != NULL);
  PuzzleState *ret = front->data;
  node* temp = front;
  front = front->next;
  delete temp;
  return ret;
}

bool LinkedListQueue::is_empty()
{
  return front == NULL;
}

LinkedListQueue::~LinkedListQueue()
{
  while (front != NULL)
	remove();
}

#endif

