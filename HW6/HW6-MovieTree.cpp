

#include <iostream>
#include <string>
#include "MovieTree.hpp"

using namespace std;


MovieTree::MovieTree(){
  root = NULL;
}
void deleteTree(MovieNode *temp){
  if(temp->leftChild != NULL){
    deleteTree(temp->leftChild);
  }
  if(temp->rightChild != NULL){
    deleteTree(temp->rightChild);
  }
  delete temp;
}

MovieTree::~MovieTree(){
  deleteTree(root);
  exit(0);
}

MovieNode* MovieTree::search(string title){
  MovieNode *temp = root;
  while(temp != NULL){
    if(title.compare(temp->title) < 0){
      temp = temp->leftChild;
    }
    else if(title.compare(temp->title) > 0){
      temp = temp->rightChild;
    }
    else if(title.compare(temp->title) == 0){
      break;
    }
  }
  return temp;
}

void printMovie(MovieNode *temp){
  if(temp == NULL){
    return;
  }
  if(temp->leftChild != NULL){
    printMovie(temp->leftChild);
  }
  cout<< "Movie: "<< temp->title << " " << temp->quantity << endl;
  if(temp->rightChild != NULL){
    printMovie(temp->rightChild);
  }
}
void MovieTree::printMovieInventory(){
  printMovie(root);
}
void MovieTree::addMovieNode(int ranking, string title, int year, int quantity){
  MovieNode *newMovie = new MovieNode(ranking,title,year,quantity);
  if(root == NULL){
    root = newMovie;
  }
  else{
    MovieNode *temp = root;
    while(temp != NULL){
      if(title.compare(temp->title) < 0){
        if(temp->leftChild != NULL){
          temp = temp->leftChild;
        }
        else{
          temp->leftChild = newMovie;
          newMovie->parent = temp;
          temp = NULL;
        }
      }
      else{
        if(temp->rightChild != NULL){
          temp = temp->rightChild;
        }
        else{
          temp->rightChild = newMovie;
          newMovie->parent = temp;
          temp = NULL;
        }
      }
    }
  }
}
void MovieTree::findMovie(string title){
  MovieNode *temp = search(title);
  if(temp == NULL){
    cout << "Movie not found." << endl;
    return;
  }
  cout << "Movie Info:" << endl;
  cout << "===========" << endl;
  cout << "Ranking:" << temp->ranking << endl;
  cout << "Title:" << temp->title << endl;
  cout << "Year:" << temp->year << endl;
  cout << "Quantity:" << temp->quantity << endl;


}
void MovieTree::rentMovie(string title){
  MovieNode *temp = search(title);
  if(temp == NULL){
    cout << "Movie not found." << endl;
    return;
  }
  if(temp->quantity <= 0){
    cout << "Movie out of stock." << endl;
    return;
  }
  temp->quantity = temp->quantity - 1;

  cout << "Movie has been rented." << endl;
  cout << "Movie Info:" << endl;
  cout << "===========" << endl;
  cout << "Ranking:" << temp->ranking << endl;
  cout << "Title:" << temp->title << endl;
  cout << "Year:" << temp->year << endl;
  cout << "Quantity:" << temp->quantity << endl;

  if(temp->quantity == 0){
    deleteMovie(title);
  }
}

MovieNode* findMin(MovieNode *min){
  while(min->leftChild != NULL){
    min = min->leftChild;
  }
  return min;
}

void MovieTree::deleteMovie(std::string title){
  MovieNode *del = search(title);
  MovieNode * temp = NULL;
  // movie not found
  if(!del){
    cout << "Movie not found." << endl;
    return;
  }
  // if movie is leaf node
  if (del->leftChild == NULL && del->rightChild == NULL){
    if(del->parent == NULL){
      root = NULL;
    }
    else if(del->parent->leftChild == del){
      del->parent->leftChild = NULL;
    }
    else{
      del->parent->rightChild = NULL;
    }
  }
// if movie has one child (right or left)
  else if(del->rightChild == NULL || del->leftChild == NULL){
    // if only left child exists
    if(!del->rightChild){
      temp = del->leftChild;
    }
    // only right child exists
    else{
      temp = del->rightChild;
    }

    if(del->parent == NULL){
      root = temp;
    }
    // if del is the left child
    else if(del->parent->leftChild == del){
      del->parent->leftChild = temp;
    }
    // if del is the right child
    else{
      del->parent->rightChild = temp;
    }
    temp->parent = del->parent;
  }

// del has both right and left child
  else{
    // temp is the right child of node to be deleted
    temp = del->rightChild;
    // go to the very left child of node to be deleted right child
    while(temp->leftChild){
      temp = temp->leftChild;
    }
    // if del is the root
    if(!del->parent){
      root = temp;
    }
    // if del is left child, set del equal to temp
    else if(del->parent->leftChild == del){
      del->parent->leftChild = temp;
    }
    // if del is right child
    else{
      del->parent->rightChild = temp;
    }
    // base case where temp should equal del
    if(temp != del->rightChild){
      del->rightChild->parent = temp;
      temp->parent->leftChild = temp->rightChild;
      // set temp equal to parent
      if(temp->rightChild){
        temp->rightChild->parent = temp->parent;
      }
      // move right side of tree to be right child of parent
      temp->rightChild = del->rightChild;
    }
    temp->parent = del->parent;
    temp->leftChild = del->leftChild;
    temp->leftChild->parent = temp;
  }
  delete del;
}

int countHelper(MovieNode *temp){
  if(temp == NULL){
    return 0;
  }
  else{
    return 1+ countHelper(temp->leftChild) + countHelper(temp->rightChild);
  }
}
void MovieTree::countMovies(){
  cout << "Count = " << countHelper(root) << endl;
}
