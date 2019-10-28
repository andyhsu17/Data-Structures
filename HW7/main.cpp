#include "HashTable.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char * argv[])
{
   // if(argc != 5)
   // {
   //   cout << "please enter five input arguments" << endl;
   // }
   //

  string line;
// 1. number of most common words
// 2. name of hunger games file
// 3. name of stop words file
// 4. size of hash table

  ifstream textfile(argv[2]);
  int num = stoi(argv[1]);
  HashTable bet(stoi(argv[4]));
  bet.getStopWords(argv[3]);
  string word;
  bool check;

  //input hunger game text word by word
  //if word is not a stop word, add it to hash table
  while(getline(textfile, line)){
    stringstream ss(line);
    while(ss >> word){
    check = bet.isStopWord(word);
    if(check == false){
      bet.addWord(word);
    }
  }
    }
    bet.printTopN(num);
    cout << "#" << endl;
    cout << "Number of collisions: " <<
    bet.getNumCollisions() << endl;
    cout << "#" << endl;
    cout << "Unique non-stop words: " <<
    bet.getNumUniqueWords() << endl;
    cout << "#" << endl;
    cout << "Total non-stop words: " <<
    bet.getTotalNumberNonStopWords() << endl;
    bet.incrementCount("peeta");
}
