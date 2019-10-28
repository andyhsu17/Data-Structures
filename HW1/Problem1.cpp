#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <algorithm>

using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValues){
  myArray[numEntries] = newValues;
  int length = numEntries + 1;
  int temp;
for (int i = 0; i < length; i++){
  for (int j = i + 1; j < length; j++){

    if (myArray[i] > myArray[j]){
      temp = myArray[i];
      myArray[i] = myArray[j];
      myArray[j] = temp;

    }
  }
  }
    cout << myArray[0];
  for (int i = 1; i < length; i++){

    cout << "," << myArray[i];

  }
  cout << endl;
  return length;
}

int main(int argc, char * argv[]){
if(argc < 2){
  cout<<("enter file name") << endl;
  return -1;
}
int array[100];
ifstream myfile (argv[1]);

string x;
int length = 0;

if(myfile.is_open()){
  while(getline(myfile, x)){
length = insertIntoSortedArray(array, length, stoi(x));

  }
}



myfile.close();


}
