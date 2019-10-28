#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Movie{
private:
   string movie;
   int year;
   float rating;

public:
  string getTitle(){
    return movie;
  }

  void setTitle(string newTitle){
    movie = newTitle;
  }

  int getYear(){
    return year;
  }

  void setYear(int newYear){
    year = newYear;
  }

  float getRating(){
    return rating;
  }

  void setRating(float newRating){
    rating = newRating;
  }

  Movie(){
    setTitle("unknown");
    setYear(2018);
    setRating(0.0);
  }

  Movie(string title, int yr, float rt){

    setTitle(title);
    setYear(yr);
    setRating(rt);

  }

};
int main(){
  
}
