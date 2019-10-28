#include <iostream>
#include "HW4-Todo-StackLinkedList.hpp"

using namespace std;

TodoStackLinkedList::TodoStackLinkedList(){
  stackHead = NULL;
}
TodoStackLinkedList::~TodoStackLinkedList(){
  TodoItem *temp = new TodoItem;
  temp = NULL;
  while(stackHead != NULL){
    temp = stackHead;
    stackHead = stackHead->next;
    delete temp;
  }
}
bool TodoStackLinkedList::isEmpty(){
  return (!stackHead);
}
void TodoStackLinkedList::push(std::string todoItem){
  TodoItem *item = new TodoItem;
  item->todo = todoItem;
  item->next = NULL;
  if(isEmpty()){
    stackHead = item;
  }
  else{
    item->next = stackHead;
    stackHead = item;
  }
}
void TodoStackLinkedList::pop(){
  if(isEmpty()){
    cout << "Stack empty, cannot pop an item." << endl;
  }
  else{
    TodoItem *temp = new TodoItem;
    temp = stackHead;
    stackHead = stackHead->next;
    delete temp;
  }
}
TodoItem* TodoStackLinkedList::peek(){
  if(isEmpty()){
    cout << "Stack empty, cannot peek." << endl;
    return NULL;
  }
  else return stackHead;
  }
