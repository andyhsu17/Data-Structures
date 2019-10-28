#include <iostream>

using namespace std;
class Node{
public:
  int data;
  Node *next;
  Node();
};

class LinkedList{
public:
  bool lengthIsEven();
  void createLLeven();
  void createLLodd();
  void createLLempty();
  void printLL();
  LinkedList();

private:
  Node *head;


};

Node::Node(){
  next = NULL;
}

LinkedList::LinkedList(){
  head = NULL;
}

// create linked list of length 4
void LinkedList::createLLeven(){
  Node *object = new Node;
  this->head = object;
  object->next = NULL;
  object->data = 1;

  object = new Node;
  head->next = object;
  object->next = NULL;
  object->data = 2;

  object = new Node;
  object->next = NULL;
  object->data = 3;
  head->next->next = object;

  object = new Node;
  object->next = NULL;
  object->data = 4;
  head->next->next->next = object;
}

// create linked list of length 3
void LinkedList::createLLodd(){
  Node *object = new Node;
  this->head = object;
  object->next = NULL;
  object->data = 1;

  object = new Node;
  head->next = object;
  object->next = NULL;
  object->data = 2;

  object = new Node;
  object->next = NULL;
  object->data = 3;
  head->next->next = object;
}

// create empty linked list
void LinkedList::createLLempty(){
  head = NULL;
}

bool LinkedList::lengthIsEven(){
  Node *iterator = head;
  bool isEven = true;
  int count = 0;
  if(head == NULL){
    return isEven;
  }
  else{
    while(iterator != NULL){
      count++;
      iterator = iterator->next;
    }
  }
if(count % 2 == 0){
  return true;
}
else return false;
}

void LinkedList::printLL(){

  Node * iterator = head;
  while(iterator != NULL){
    cout << iterator->data << " ";
    iterator = iterator->next;
}
cout << endl;
}



int main(){
// even linked list returns true, prints out linked list
  LinkedList bet;
  bet.createLLeven();
  bool test = bet.lengthIsEven();
  cout << test << endl;
  bet.printLL();

// odd linked list returns false, prints out linked list
  bet.createLLodd();
  test = bet.lengthIsEven();
  cout << test << endl;
  bet.printLL();

//empty linked list returns true, prints null linked list
  bet.createLLempty();
  test = bet.lengthIsEven();
  cout << test << endl;
  bet.printLL();





}
