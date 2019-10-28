#include <iostream>
using namespace std;


/*
Each node in the tree has this structure
*/
struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};


/*
Variables and functions for Tree ADT
*/
class Tree
{

  public:
    Node *root;
    Tree();
    void createTree();
    void printTree(Node * root);
    bool isMinHeap(Node * root);
};

/*
Constructor for a Tree object
*/
Tree::Tree()
{
  this->root = NULL;
}


void Tree::printTree(Node * root)
{
  if(!root)
  {
    return;
  }
  cout << root->data << " ";
  
  printTree(root->left);
  printTree(root->right);
}


void Tree::createTree()
{
  Node *root         = new Node(3);
  root->left         = new Node(5);
  root->right        = new Node(4);
  root->right->left  = new Node(9);

  this->root = root;
}

bool Tree::isMinHeap(Node * root)
{
  bool flag = true;
  if(!root->left && !root->right)
  {
    return flag;
  }

if(root->left != NULL && root->right == NULL)
{
  if(root->left->data < root->data)
  {
    return flag = false;
  }
}
if(root->right != NULL && root->left == NULL)
{
  if(root->right->data < root->data)
  {
    return flag = false;
  }
}
  flag = isMinHeap(root->left);
  flag = isMinHeap(root->right);

}

/*
 Main function that calls create tree, print Tree and all the traversal functions.
 */
int main()
{
  Tree t;
  t.createTree();
  t.printTree(t.root);
  cout << endl;
  bool flag = t.isMinHeap(t.root);

  cout << flag << endl;
  return 0;
}
