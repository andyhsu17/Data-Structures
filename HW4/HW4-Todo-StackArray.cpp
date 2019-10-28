#include <string>
#include <iostream>
#include "HW4-Todo-StackArray.hpp"
using namespace std;

TodoStackArray::TodoStackArray(){
  stackTop = -1;
}
bool TodoStackArray::isEmpty(){
if(stackTop == -1) return true;
else return false;
}
bool TodoStackArray::isFull(){
  if(stackTop == MAX_STACK_SIZE - 1) return true;
  else return false;
}

void TodoStackArray::push(std::string todoItem){
  if(isFull()){
    cout << "Stack full, cannot add new todo item." << endl;
  }
  else if(isEmpty()){

    stack[++stackTop].todo = todoItem;
  }
  else{
    stackTop++;
    stack[stackTop].todo = todoItem;
  }
}
void TodoStackArray::pop(){
  if(isEmpty()){
    cout << "Stack empty, cannot pop an item." << endl;
  }
  else stackTop--;

}
TodoItem TodoStackArray::peek(){
  if(isEmpty()){
    cout << "Stack empty, cannot peek." << endl;
    return stack[stackTop];
  }
  else{
    return stack[stackTop];
  }
}
