#include <iostream>
#include <iostream>
#include "HW4-Todo-QueueArray.hpp"
#include <string>
using namespace std;

TodoQueueArray::TodoQueueArray(){
  queueFront = queueEnd = -1;
}

bool TodoQueueArray::isEmpty(){
  return(queueFront == -1 && queueEnd == -1);
}

bool TodoQueueArray::isFull(){
  if((queueEnd + 1) % 5 == queueFront) return true;
  else return false;
}

void TodoQueueArray::enqueue(string todoItem){
  if(isFull()){
    cout << "Queue full, cannot add new todo item." << endl;
  }
  else if(isEmpty()){
    queueFront = queueEnd = 0;
    queue[queueEnd].todo = todoItem;
  }

  else{
    queueEnd = (queueEnd + 1) % 5;
    queue[queueEnd].todo = todoItem;
  }
}

void TodoQueueArray::dequeue(){
  if(isEmpty()){
    cout << "Queue empty, cannot dequeue an item." << endl;
  }
  else if (queueEnd == queueFront){
    queueEnd = queueFront = -1;
    }

  else{
    queueFront = (queueFront + 1) % 5;
  }
}

TodoItem TodoQueueArray::peek(){
  if(isEmpty()){
    cout << "Queue empty, cannot peek." << endl;
    return queue[queueFront];
  }
  else{
    return queue[queueFront];
  }
  }
