#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct wordItem{
  string word;
  int count;
};

// store all ignore words inside an array of strings
void getStopWords(char *ignoreWordFileName, string ignoreWords[]){

// read file into input file stream called IgnoreWords
ifstream IgnoreWords(ignoreWordFileName);
string word;
int i = 0;

// if stream is open, read line by line and store each word into array
if(IgnoreWords.is_open())
{
  while(getline(IgnoreWords, word))
  {
  ignoreWords[i] = word;
  i++;
  }
}

IgnoreWords.close();
}
// determine if word is inside ignoreWords array
bool isStopWord(string word, string ignoreWords[]){

// loop through ignoreWords array, if word is inside, return true. Otherwise return false
for (int i = 0; i < 50; i++){
  if(ignoreWords[i] == word){
    return true;
  }
}
return false;
}

// add up total number of words inside unique word array
int getTotalNumberNonStopWords(wordItem list[], int length){
  int wordcount = 0;
for(int i = 0; i < length; i++){
  wordcount += list[i].count;
}
return wordcount;
}

// sort the array by word frequency, with most frequent first
void arraySort(wordItem list[], int length){
  wordItem temp;
for (int i = 0; i < length; i++){
  for (int j = i + 1; j < length; j++){
    if (list[i].count < list[j].count){
      temp = list[i];
      list[i] = list[j];
      list[j] = temp;
    }
  }
}
}

// print the top "N" of words of the sorted array
void printTopN(wordItem wordItemList[], int topN){
for (int i = 0; i < topN; i++){
  cout << wordItemList[i].count << " - " << wordItemList[i].word << endl;
}
}

wordItem * doublesize(int capacity, wordItem *ptr){
wordItem *newptr = new wordItem[2 * capacity];
for(int i = 0; i < capacity; i++){
newptr[i] = ptr[i];
}
delete [] ptr;
return newptr;
}


int main(int argc, char * argv[]){
if (argc != 4){
  cout << "please give most frequent words, text file, and ignore words file" << endl;
}
int N = stoi(argv[1]);
ifstream HungerGames(argv[2]);
int capacity = 100;
wordItem *ptr = new wordItem[capacity];

// initialize string of length 50 to store ignore words inside and call function to
// store ignore words

string ignoreWords[50];
getStopWords(argv[3], ignoreWords);
string line;
string word;
int index = 0;
bool unique;
int counter = 0;

// start loop
// read line by line of hunger games and store into word
if (HungerGames.is_open()){
  while(getline(HungerGames, line)){
    stringstream ss(line);
    while(ss >> word){
      // default state of new word is unique, until we compare it to existing array
      unique = true;

      // check if input word will exceed capacity and double size if so
      if((index + 1) >= capacity)
      {
        ptr = doublesize(capacity, ptr);
        capacity = capacity * 2;
        counter++;
      }

  // check if word is one of the ignorewords. If it is not, store into array of structs
  bool flag = isStopWord(word, ignoreWords);
  if (flag == false){

    // compare new word to each in existing array, if not unique, increment counter
    for (int j = 0; j <= index; j++)
    {
      if(ptr[j].word == word)
      {
        ptr[j].count++;
        unique = false;
        break;
      }

    }
    // if word doesnt already exist, add to end of array
    if (unique == true)
    {
    ptr[index].word = word;
    ptr[index].count++;
    index++;
    }
  }

}

}

}

int wordcount = getTotalNumberNonStopWords(ptr, index + 1);
arraySort(ptr, index + 1);
printTopN(ptr, N);
cout << "#" << endl << "Array doubled: " << counter << endl;
cout << "#" << endl << "Unique non-common words: " << index << endl;
cout << "#" << endl << "Total non-common words: " << wordcount << endl;

HungerGames.close();
delete [] ptr;
}
