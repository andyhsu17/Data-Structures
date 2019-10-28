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
  void createLL1();
  void createLL2();
  void deleteNegatives();
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

// create linked list
void LinkedList::createLL1(){
  Node *object = new Node;
  this->head = object;
  object->next = NULL;
  object->data = -3;

  object = new Node;
  head->next = object;
  object->next = NULL;
  object->data = 9;

  object = new Node;
  object->next = NULL;
  object->data = 2;
  head->next->next = object;

  object = new Node;
  object->next = NULL;
  object->data = -4;
  head->next->next->next = object;

  // object = new Node;
  // object->next = NULL;
  // object->data = -2;
  // head->next->next->next->next = object;
  //
  // object = new Node;
  // object->next = NULL;
  // object->data = 3;
  // head->next->next->next->next->next = object;
}

void LinkedList::createLL2(){
  Node *object = new Node;
  this->head = object;
  object->next = NULL;
  object->data = 7;

  object = new Node;
  head->next = object;
  object->next = NULL;
  object->data = 6;

  object = new Node;
  object->next = NULL;
  object->data = 5;
  head->next->next = object;


}
void LinkedList::printLL(){

  Node * iterator = head;
  while(iterator != NULL){
    cout << iterator->data << " ";
    iterator = iterator->next;
}
cout << endl;
}

void LinkedList::deleteNegatives(){
  if(head == NULL){
    cout << "Linked List is Empty, cannot delete anything" << endl;
    return;
  }
  else{
    Node *temp = NULL;
    Node *curr = head;
    while(curr->next != NULL){
      if(head->data < 0){
        curr = head;
        head = head->next;
        temp = curr;
        curr = curr->next;
        delete temp;
        if(curr == NULL) break;
      }
      else if(curr->next->data < 0){
        temp = curr->next;
        curr->next = temp->next;
        temp->next = NULL;
        delete temp;
      }
      curr = curr->next;
      if(curr == NULL) break;

    }
  }

}



int main(){
  // create linked list with first and last elements negative, and print
  // delete all negative values and print
LinkedList bet;
bet.createLL1();
bet.printLL();
cout << endl;
bet.deleteNegatives();
bet.printLL();

// create second linked list with all positive values and print
// delete all negative values and print. (should delete nothing)
bet.createLL2();
bet.printLL();
cout << endl;
bet.deleteNegatives();
bet.printLL();




}
