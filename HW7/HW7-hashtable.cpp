#include "HashTable.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


HashTable::HashTable(int HashTableSize)
{
  numCollisions = 0;
  numUniqueWords = 0;
  hashTableSize = HashTableSize;

  hashTable = new wordItem* [hashTableSize];
  for(int i = 0; i < hashTableSize; i++){
    hashTable[i] = NULL;
  }

}

HashTable::~HashTable()
{
  delete [] hashTable;
}

void HashTable::getStopWords(char *ignoreWordFileName)
{
  string line;
  string word;
  int i = 0;
  ifstream myfile(ignoreWordFileName);
  while(getline(myfile, line)){
    stringstream ss(line);
    ss >> word;
    vecIgnoreWords[i] = word;
    i++;
 }
}

bool HashTable::isStopWord(string word)
{
  bool var = false;
  for(int i = 0; i < 50; i++){
    if(word == vecIgnoreWords[i]){
      var = true;
    }
  }
  return var;
}

bool HashTable::isInTable(string word)
{

  int index = getHash(word);
  wordItem* ptr = hashTable[index];
  bool flag = false;
  while(ptr != NULL)
  {
    if(word == ptr->word)
    {
      return flag = true;
    }
    ptr = ptr->next;
  }
  return flag;
}

void HashTable::incrementCount(string word)
{
  wordItem* temp = searchTable(word);
  temp->count++;


}

void HashTable::addWord(string word)
{
  int index = getHash(word);
  if(hashTable[index] != NULL){
    numCollisions++;
  }
  wordItem *foo = new wordItem;
  foo->word = word;
  foo->count = 1;
  foo->next = NULL;
  if(hashTable[index] == NULL)
  {
  hashTable[index] = foo;
  }
  else
  {
    wordItem *ptr = hashTable[index];
    while(ptr->next != NULL)
    {
      if(word == ptr->word){
        ptr->count++;
        break;
      }
      ptr = ptr->next;
    }

    ptr->next = foo;

  }
}

int HashTable::getTotalNumberNonStopWords()
{
  int count = 0;

for(int i = 0; i < hashTableSize; i++){
  if(hashTable[i] == NULL)
  {
    continue;
  }
  // else if(hashTable[i]->next == NULL){
  //   count += hashTable[i]->count;
  // }
  else {
    wordItem * ptr = hashTable[i];
    while(ptr != NULL){
      count += ptr->count;
      ptr = ptr->next;
    }
  }
}
return count;
}

void HashTable::printTopN(int n)
{

  int totalwords = getNumUniqueWords();
  wordItem** Array = new wordItem*[totalwords];
  for(int i = 0; i < totalwords; i++)
  {
    Array[i] = NULL;
  }
  int i = 0;
  int j = 0;
  while(i < totalwords){
    if(hashTable[j] == NULL)
    {
      j++;
      continue;
    }
    // if no linked list exists at index
    // else if(hashTable[j]->next == NULL)
    // {
    //   Array[i] = hashTable[j];
    //   i++;
    //   j++;
    // }

    // linked list occurs at index
    else
    {
      wordItem * ptr = hashTable[j];
      while(ptr != NULL)
      {
        Array[i] = ptr;
        i++;
        ptr = ptr->next;
      }
      j++;
    }
  }

// sorting from largest count to lowest

for(int i = 0; i < totalwords; i++){
  for(int j = i + 1; j < totalwords; j++){
    if(Array[i]->count < Array[j]->count){
      wordItem* temp = Array[i];
      Array[i] = Array[j];
      Array[j] = temp;
    }
  }
}
for(int i = 0; i < n; i++){
  cout << Array[i]->count << " - " << Array[i]->word << endl;
}
}

int HashTable::getNumUniqueWords()
{
  int count = 0;
  for(int i = 0; i < hashTableSize; i++)
  {
    if(hashTable[i] == NULL)
    {
      continue;
    }
    // else if(hashTable[i]->next == NULL){
    //   count++;
    // }

    else
    {
      wordItem* ptr = hashTable[i];
      while(ptr != NULL){
        count++;
        ptr = ptr->next;
      }
    }
  }
  return count;
}

int HashTable::getNumCollisions()
{
  return numCollisions;
}

int HashTable::getHash(string word)
{
  int hash = 5381;
  for(int i = 0; i < word.length(); i++)
  {
    hash = hash * 33 + word[i];
  }
  hash = hash % hashTableSize;
  if(hash < 0){
    hash += hashTableSize;
  }
  return hash;
}

wordItem* HashTable::searchTable(string word)
{

    int index = getHash(word);
    wordItem* ptr = hashTable[index];
    while(ptr != NULL){
      if(word == ptr->word){
        return ptr;
      }
      ptr = ptr->next;
    }
    return NULL;
  }
