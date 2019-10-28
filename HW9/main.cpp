#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
  Graph bet;
  ifstream myfile(argv[1]);
  string line;
  string word;
  vector <string> citynames;
  bool firstrow = true;
  int rowcount = 0;
  int columncount = 0;
  bool skip = true;
  while(getline(myfile,line))
  {
    columncount = 0;
    // row 1 has all cities
    if(firstrow)
    {
    stringstream ss(line);
    while(getline(ss, word, ','))
    {
      if(word == "cities")
      {
        columncount++;
        continue;
      }
      bet.addVertex(word);
      citynames.push_back(word);
      columncount++;
    }
    firstrow = false;
    rowcount++;
    }
    // rest of file has one city and rest edges
    else
    {
      stringstream ss(line);
      while(getline(ss, word, ','))
      {
        if(skip)
        {
          skip = false;
          columncount++;
          continue;
        }
        else
        {
          int distance = stoi(word);
          if(distance > 0)
          {

          bet.addEdge(citynames[rowcount-1], citynames[columncount-1], distance);
          cout << " ... Reading in " << citynames[rowcount-1] << " -- "
          << citynames[columncount-1] << " -- " << distance << endl;
          }
          columncount++;
        }
      }
      skip = true;
      rowcount++;
    }
  }
  bet.assignDistricts();
  bet.displayEdges();
}
