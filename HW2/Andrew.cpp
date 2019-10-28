#include <iostream>
#include <fstream>
using namespace std;

struct UniqueWord
{
    string word;
    int occurrences;
};


int main()
{
    UniqueWord aStructArray[100000];
    string word;
    int index = 0;
    ifstream inputFile;

    inputFile.open("hungergames.txt");
    while(inputFile >> word)
    {

        // create boolean unique variable
        bool isUnique = true; // default word is unique
        // loop through  aStructarray and compare it to every item in there
        for(int i = 0; i < index; i++)
        {
            // is this word already in our aStructWords array?
            // if it is, then increment the count for that word
            if(aStructArray[i].word == word)
            {
                aStructArray[i].occurrences++;
                isUnique = false;
            }
        }
        // scenario where we have never seen this word before
        if(isUnique == true)
        {
            // add the word and set the number of occurrences to 1 which is the default
            aStructArray[index].word = word;
            aStructArray[index].occurrences = 1;
            index++;
        }
    }
    // close our file (just good practice)
    inputFile.close();
    UniqueWord newArray[index];

    for(int i = 0; i < index; i++)
    {
        newArray[i] = aStructArray[i];
    }
    
    
    UniqueWord temp;
   //now lets sort by the number of occurrences 
    for(int i = 0; i < index; i++)
    {
        for(int j = i + 1; j < index; j++)
        {
            if(aStructArray[i].occurrences > aStructArray[j].occurrences)
            {
                temp = aStructArray[i];
                aStructArray[i] = aStructArray[j];
                aStructArray[j] = temp;
            }
        }
    }
    for(int i = 0; i < index; i++)
    {
        cout << aStructArray[i].word << ": " << aStructArray[i].occurrences;
        cout << endl;
    }
     

    
    
}