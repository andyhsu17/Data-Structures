#include <iostream>
#include <string>
#include "HW4-Todo-QueueLinkedList.hpp"
using namespace std;

TodoQueueLinkedList::TodoQueueLinkedList(){
  queueFront = NULL;
  queueEnd = NULL;
}

bool TodoQueueLinkedList::isEmpty(){
  if(queueFront == NULL)
  return true;
  else {
    return false;
  }
}

TodoQueueLinkedList::~TodoQueueLinkedList(){
}

void TodoQueueLinkedList::enqueue(std::string todoItem){
  if(isEmpty()){
    TodoItem *item = new TodoItem;
    item->todo = todoItem;
    item->next = NULL;
    queueFront = item;
    queueEnd = item;
  }
  else{
  TodoItem * item = new TodoItem;
  item->todo = todoItem;
  item->next = NULL;
  queueEnd->next = item;
  queueEnd = queueEnd->next;
}
}

void TodoQueueLinkedList::dequeue(){
  if (isEmpty()){
    cout << "Queue empty, cannot dequeue an item." << endl;
  }
  else{
    TodoItem *temp = queueFront;
    queueFront = queueFront->next;
    delete temp;
  }
}

TodoItem* TodoQueueLinkedList::peek(){
  if (isEmpty()){
    cout << "Queue empty, cannot peek" << endl;
    return NULL;
  }
  else{
    return queueFront;
  }
}
