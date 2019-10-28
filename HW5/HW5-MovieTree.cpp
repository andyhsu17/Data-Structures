#include "HW5-MovieTree.hpp"
#include <iostream>
#include <string>

using namespace std;

MovieTree::MovieTree(){
  root = NULL;
}
void deleteNodes(MovieNode* root){
  if(!root){
    return;
  }
  deleteNodes(root->leftChild);
  deleteNodes(root->rightChild);
  delete root;
}

MovieTree::~MovieTree(){
  deleteNodes(root);
  root = NULL;

}



void printMovieHelper(MovieNode* root){
  if(!root){
    return;
  }
  printMovieHelper(root->leftChild);
  cout << "Movie: " << root->title << " " << root->quantity << endl;
  printMovieHelper(root->rightChild);
}


void MovieTree::printMovieInventory(){
  printMovieHelper(root);
}

MovieNode* addMovieHelper(MovieNode* node, int ranking, string title, int year, int quantity){
  //if root is null, set root equal to the new node

  if(!node){
    node = new MovieNode(ranking, title, year, quantity);
    return node;
  }

  if(title < node->title){
    // cout << "title should add to left child" << endl;
    node->leftChild = addMovieHelper(node->leftChild, ranking, title, year, quantity);
  }

  else{
    // cout << "title should add to right child" << endl;
    node->rightChild = addMovieHelper(node->rightChild, ranking, title, year, quantity);
  }
  return node;
}

void MovieTree::addMovieNode(int ranking, string title, int year, int quantity){
  root = addMovieHelper(root, ranking, title, year, quantity);
}


void MovieTree::findMovie(string title){
  MovieNode* tempMovie = search(title);
  if(!tempMovie){
    cout << "Movie not found." << endl;
  }
  else{
  cout << "Movie Info:" << endl;
  cout << "===========" << endl;
  cout << "Ranking:" << tempMovie->ranking << endl;
  cout << "Title:" << tempMovie->title << endl;
  cout << "Year:" << tempMovie->year << endl;
  cout << "Quantity:" << tempMovie->quantity << endl;
}
}

void MovieTree::rentMovie(string title){
  MovieNode* tempMovie = search(title);
  if(!tempMovie){
    cout << "Movie not found." << endl;
    return;
  }
  if(tempMovie->quantity > 0){
  tempMovie->quantity--;
  cout << "Movie has been rented." << endl;
  cout << "Movie Info:" << endl;
  cout << "===========" << endl;
  cout << "Ranking:" << tempMovie->ranking << endl;
  cout << "Title:" << tempMovie->title << endl;
  cout << "Year:" << tempMovie->year << endl;
  cout << "Quantity:" << tempMovie->quantity << endl;
}
else{
  cout << "Movie out of stock." << endl;
}
}



MovieNode* MovieTree::search(std::string title){
  while(root != NULL){
  if(title == root->title){
    return root;
  }
  else if(title < root->title){
    root = root->leftChild;
  }
  else{
    root = root->rightChild;
  }

}
return root;
}
