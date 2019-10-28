#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"sentimentAnalysis.hpp"

using namespace std;
// creating the two hash tables
// one storing type Tweet which holds the tweet, user, and scores
// other storing type wordScore which stores a word and its sentimal score
Sentiment::Sentiment(int s){
  this->table_size = s;
  tweetScoreTable = new vector<Tweet>[table_size];
  wordScoreTable = new vector<WordScores>[table_size];
}
Sentiment::~Sentiment(){

}
// parses the word.txt file grabing the words/phrases and their
// scores and then placing them into a hashtable
void Sentiment::parseWordScores(char *wordScores_file){
  string ifile = wordScores_file;
  string line;
  string part;
  WordScores newWord;
  ifstream data;

  data.open(ifile.c_str());
  if(data.is_open()){
    while(getline(data, line)){
      stringstream ss(line);
      getline(ss, part,',');
      newWord.word = part;
      getline(ss, part,'\r');
      newWord.score = stof(part);
      addWordScore(newWord);
    }
  }
  data.close();
}
// phrases the input statements we want to score
void Sentiment::parseTwitterFile(char *twitter_file){
  string ifile = twitter_file;
  string line;
  string user;
  string word;
  Tweet newTweet;

  ifstream data;
  data.open(ifile.c_str());
  if(data.is_open()){
		while(getline(data, line)){
			if(line != "\r"){
				stringstream ss(line);
        getline(ss, word,',');
        newTweet.user = word;
        newTweet.tweet.clear();
				while(getline(ss, word, ' ')){
          // gets rid of capital letters and punc.
          for(int i = 0; i<word.length(); i++){
            if(word[i] <= 'Z' && word[i] >= 'A'){
              word[i] += 32;;
            }
            if((word[i] != '-') && (ispunct(word[i]))){
              word.erase(i--,1);
            }
          }
          newTweet.tweet.push_back(word);
				}
        scoreTweet(newTweet);
			}
		}
	}
	data.close();
}
// scores tweet by summing up the all the scores of words/phrases found
// in the tweet
void Sentiment::scoreTweet(Tweet newTweet){
  float total = 0;
  float temp;
  cout << newTweet.user << " - ";
  for(int i = 0; i<newTweet.tweet.size(); i++){
    cout << newTweet.tweet[i] << " ";
  }
  // makes sure grabs full phrase found in the word.txt and its score
  for(int i = 0; i<newTweet.tweet.size(); i++){
    if(i <= newTweet.tweet.size() - 3){
      temp = getWordScore(newTweet.tweet[i] + " " + newTweet.tweet[i+1] + " " + newTweet.tweet[i+2],newTweet.tweet[i -1]);
      if(!temp){
        temp = getWordScore(newTweet.tweet[i] + " " + newTweet.tweet[i+1],newTweet.tweet[i -1]);
        if(!temp){
          temp = getWordScore(newTweet.tweet[i],newTweet.tweet[i -1]);
        }
        else{
          i++;
        }
      }
      else{
        i += 2;
      }
    }
    else if(i <= newTweet.tweet.size() - 2){
      temp = getWordScore(newTweet.tweet[i] + " " + newTweet.tweet[i+1],newTweet.tweet[i -1]);
      if(!temp){
        temp = getWordScore(newTweet.tweet[i],newTweet.tweet[i -1]);
      }
      else{
        i++;
      }
    }
    else if(i <= newTweet.tweet.size() - 1){
      temp = getWordScore(newTweet.tweet[i],newTweet.tweet[i -1]);
    }
    // suming up the total of all the words/phrase found in statement and word.txt
    total += temp;
  }
  newTweet.score = total;
  cout << "----> Score: " << newTweet.score << endl << endl;
  // adds tweet, score, and user to hash table
  addTweetScore(newTweet);
}

// returns the score found in wordScoreTable of the the word or phrase found in tweet
float Sentiment::getWordScore(string word, string prev){
  int index = getWordHash(word);
  for(int i = 0; i<wordScoreTable[index].size(); i++){
    if(word == wordScoreTable[index][i].word){
      // inverting the score based on whether not or dont found before it
      if(prev == "not" || prev == "dont"){
        return wordScoreTable[index][i].score * -1;
      }
      else{
        return wordScoreTable[index][i].score;
      }
    }
  }
  return 0;
}

void Sentiment::addWordScore(WordScores newWord){
  int index = getWordHash(newWord.word);
  wordScoreTable[index].push_back(newWord);
}

void Sentiment::addTweetScore(Tweet newTweet){
  int count = 0;
  for(int i = 0; i<newTweet.tweet.size(); i++){
    // allowing us to use a veration of the score for hash tableSize
    // because cannot index with a float
    count += 8*getWordScore(newTweet.tweet[i],"0") + 8;
  }
  int index = getScoreHash(count);
  tweetScoreTable[index].push_back(newTweet);
}

int Sentiment::getWordHash(string word){
  int hash = 5381;
  for(int i = 0; i < word.length(); i++){
    hash = hash*33 + (int)word[i];
  }
  hash = hash % table_size;
  if(hash < 0) hash += table_size;
  return hash;
}

int Sentiment::getScoreHash(int score){
  return score%table_size;
}

// used for debuging hash tables
void Sentiment::displayHash(){
  for (int i = 0; i < table_size; i++){
    cout << i;
    for (int j = 0; j<tweetScoreTable[i].size(); j++){
      cout << " --> User: " << tweetScoreTable[i][j].user<< " Score: ";
      cout << tweetScoreTable[i][j].score << " Tweet: ";
      for(int k = 0; k<tweetScoreTable[i][j].tweet.size(); k++){
        cout << tweetScoreTable[i][j].tweet[k] << " ";
      }
    }
    cout << endl;
  }
}
void Sentiment::displayHash2(){
  for (int i = 0; i < table_size; i++){
    cout << i;
    for (int j = 0; j<wordScoreTable[i].size(); j++){
      cout << " --> Word: " << wordScoreTable[i][j].word<< " Score: ";
      cout << wordScoreTable[i][j].score;
    }
    cout << endl;
  }
}
