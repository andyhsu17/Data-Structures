#include "HW5-MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ostream>
using namespace std;

int menu(){
  string choice;
  cout << "======Main Menu======" << endl;
  cout << "1. Find a movie" << endl;
  cout << "2. Rent a movie" << endl;
  cout << "3. Print the inventory" << endl;
  cout << "4. Quit" << endl;
  getline(cin, choice);
  return stoi(choice);
}

int main(int argc, char *argv[]){
   MovieTree bet;
   bet.addMovieNode(1, "hello", 3, 4);
   bet.addMovieNode(1, "bitch", 3, 4);
   bet.addMovieNode(1, "narsty", 3, 4);
   bet.printMovieInventory();

   bet.~MovieTree();
   bet.printMovieInventory();
   cout << "done" << endl;


//   MovieTree bet;
//   int nranking;
//   int nyear;
//   int nquantity;
//   ifstream myfile(argv[1]);
//   stringstream ss;
//   string line;
//   string component;
//   string ranking;
//   string title;
//   string year;
//   string quantity;
//   if (myfile.is_open()){
//   while(getline(myfile, line)){
//     stringstream ss(line);
//       for (int i = 0; i < 4; i++){
//     getline(ss, component, ',');
//     if(i == 0)  ranking = component;
//
//     if(i == 1) title = component;
//     if(i == 2) year = component;
//     if(i == 3) quantity = component;
//   }
//   nranking = stoi(ranking);
//   nyear = stoi(year);
//   nquantity = stoi(quantity);
//   bet.addMovieNode(nranking, title, nyear, nquantity);
//   }
// }
//
//   int input;
//   string inputTitle;
//
// bool quit = false;
//   while(!quit){
//     input = menu();
//     switch(input){
//     case 1:
//     cout << "Enter title:" << endl;
//     getline(std::cin, inputTitle);
//     bet.findMovie(inputTitle);
//     break;
//
//
//     case 2:
//     cout << "Enter title:" << endl;
//     getline(cin, inputTitle);
//     bet.rentMovie(inputTitle);
//     break;
//
//     case 3:
//     bet.printMovieInventory();
//     break;
//
//     case 4:
//     quit = true;
//     break;
// }
//
//   }
//   cout << "Goodbye!" << endl;

}
