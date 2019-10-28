#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

struct WordScores{
  string word;
  float score;
};

struct Tweet{
  vector<string> tweet;
  float score;
  string user;
};

class Sentiment{
  int table_size;
  vector<Tweet> *tweetScoreTable;
  vector<WordScores> *wordScoreTable;


public:
  Sentiment(int s);
  ~Sentiment();
  float getWordScore(std::string word,string prev);
  void addWordScore(WordScores newWord);
  void displayHash();
  void displayHash2();
  void addTweetScore(Tweet newTweet);
  void parseWordScores(char *wordScores_file);
  void scoreTweet(Tweet newTweet);
  void parseTwitterFile(char *twitter_file);
  int getWordHash(std::string word);
  int getScoreHash(int score);
};
