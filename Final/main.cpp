#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"sentimentAnalysis.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  int tableSize = 10000;
  cout << endl;

  Sentiment s(tableSize);
  s.parseWordScores(argv[1]);
  s.parseTwitterFile(argv[2]);

  return 0;
}
