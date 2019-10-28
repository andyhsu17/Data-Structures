#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct User {
  string username;
  float gpa;
  int age;
};



void addUser(vector <User> * users, string _username, float _gpa, int _age){
  struct User newUser;
  newUser.username = _username;
  newUser.gpa = _gpa;
  newUser.age = _age;
  users->push_back(newUser);
}

void printList(const vector <User> users){
  for (int i = 0; i < users.size(); ++i){
    cout << users[i].username << " [" << users[i].gpa << "]" << " age:" << users[i].age << endl;
  }
  }


int main(int argc, char * argv[]){
  if (argc != 2){
    cout << "please enter filename" << endl;
    return -1;
  }
  ifstream myfile(argv[1]);
  string line;
  vector <User> users;
  vector <User> *ptr = &users;
  string username;
  string gpa;
  string age;

  if (myfile.is_open()){
    while(getline(myfile, line)){
      stringstream ss(line);
      ss >> username;
      ss >> gpa;
      ss >> age;
      float ngpa = stof(gpa);
      int nage = stoi(age);
      addUser(ptr, username, ngpa, nage);
    }
  }
  printList(users);

  myfile.close();
}
