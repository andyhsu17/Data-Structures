#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include <list>
#include <queue>
#include <string>

using namespace std;

struct vertex;

/*This is the struct for the adjacent vertices for each
vertex in the graph. */

struct Edge
{
    vertex *v;

};

/*this is the struct for each vertex in the graph. */
struct vertex
{
    int value;
    bool visited;
    std::vector<Edge> Edges; //stores edges to adjacent vertices
};

class Graph
{
  public:

    int mostIncoming(int n);
    int mostOutgoing(int n);
    /*
class constructor
Purpose: perform all operations necessary to instantiate a class
object
Parameters: none
*/
    Graph();

    /*
class destructor
Purpose: free all resources that the object has aquired
Parameters: none
*/
    ~Graph();

    /*
Method Name: addEdge
Purpose: Creates an edge between two vertices (using an Edge
struct)
Param: v1 - vertex at one end of edge
Param: v2 - vertex at opposite end of edge
*/
    void addEdge(int v1, int v2);

    /*
Method Name: addVertex
Purpose: Creates a vertex

Param: name - name of the vertex (city name)
*/
    void addVertex(int n);

    /*
Method Name: displayEdges
Purpose: print all edges in graph (see writeup for format)
Parameters: none
*/
    void displayEdges();

    /*
Method Name: assignDistricts
Purpose: Iterate through the vertices, perform BFT to find connected
components, and assign to district
Parameters: none
*/

/*
Method Name: printDFS
Purpose: Iterate through the vertices, perform DFS by calling the
DFTraversal function
Parameters: none
*/
   void printDFS();

/*
  Method Name: setAllVerticesUnvisited
  Purpose: Iterate through the vertices, mark them unvisited.
          This function is called prior to calling DFS after BFS
          has been performed so that the nodes can revisited again
          when DFS is called.
  Parameters: None
*/
  void setAllVerticesUnvisited();

  void BFThelper(int n);

    void printShortestPath(int start, int end);
  private:
    std::vector<vertex> vertices; //stores vertices

    /*
Method Name: findVertex
Purpose: Find and return the vertex of the specified city
Param: name - name of the city vertex to be returned
returns pointer to a vertex
*/
    vertex *findVertex(int n);

    /*
Method Name: BFTraversalLabel
Purpose: Call BFTraversalLabel from within assignDistricts to label
the districts. This method should implement a breadth first
traversal from the startingCity and assign all cities
encountered the distID value
Param: name - name of starting city for breadth first traversal
*/

    void BFTraversalLabel(int n);

    void DFTraversal(vertex *v);



};

#endif // GRAPH_HPP



Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::addEdge(int v1, int v2)
{

  vertex * city1 = findVertex(v1);
  vertex * city2 = findVertex(v2);
  Edge nedge1;
  nedge1.v = city2;
  city1->Edges.push_back(nedge1);



}

void Graph::addVertex(int n)
{
  vertex nvertex;

  nvertex.value = n;
  nvertex.visited = false;
  vertices.push_back(nvertex);
}




void Graph::printDFS()
{
  for(int i = 0; i < vertices.size(); i++)
  {

  vertex * ptr = &vertices[i];

  DFTraversal(ptr);
}
}

void Graph::DFTraversal(vertex *v)
{
  if(v->visited == false)
  {
    cout << v->value << endl;
    v->visited = true;
  }
  for(int i = 0; i < v->Edges.size(); i++)
  {
    if(v->Edges[i].v->visited == false)
    {
      cout << v->Edges[i].v->value << endl;
      v->Edges[i].v->visited = true;
      DFTraversal(v->Edges[i].v);
    }
  }

}


void Graph::setAllVerticesUnvisited()
{

  for(int i = 0; i < vertices.size(); i++)
  {
    vertices[i].visited = false;
  }
}

vertex* Graph::findVertex(int n)
{
  vertex* ptr;
  for(int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i].value == n)
    {
      ptr = &vertices[i];
      return ptr;
    }
  }
  cout << "vertex not found" << endl;
}




void Graph::BFTraversalLabel(int n)
{
  queue <vertex> q;
  vector <Edge>::iterator iterator;
  vertex * city = findVertex(n);
  city->visited = true;

  q.push(*city);

  while(!q.empty())
  {
    // prints out front of queue, which is edges of starting node
    vertex temp = q.front();
    cout << temp.value << endl;
    q.pop();
    for(iterator = temp.Edges.begin(); iterator != temp.Edges.end(); iterator++)
    {
    if(iterator->v->visited == false)
      {
        iterator->v->visited = true;
        q.push(*(iterator->v));
      }
    }
  }

}

void Graph::BFThelper(int n)
{
  BFTraversalLabel(n);
}



int Graph::mostOutgoing(int n)
{
  queue <vertex> q;
  vector <Edge>::iterator iterator;
  vertex * city = findVertex(n);
  city->visited = true;
  int max = 0;
  int count = 0;

  q.push(*city);

  while(!q.empty())
  {
    // prints out front of queue, which is edges of starting node
    vertex temp = q.front();
    q.pop();
    count = 0;
    for(iterator = temp.Edges.begin(); iterator != temp.Edges.end(); iterator++)
    {
    if(iterator->v->visited == false)
      {
        iterator->v->visited = true;
        q.push(*(iterator->v));
        count++;
      }
    }
    if(count > max)
    {
      max = count;
    }
  }
  return max;

}

int Graph::mostIncoming(int n)
{
  queue <vertex> q;
  vector <Edge>::iterator iterator;
  vertex * city = findVertex(n);
  city->visited = true;
  int max = 0;
  int count = 0;

  q.push(*city);

  while(!q.empty())
  {
    // prints out front of queue, which is edges of starting node
    vertex temp = q.front();
    q.pop();
    count = 0;
    for(iterator = temp.Edges.begin(); iterator != temp.Edges.end(); iterator++)
    {
    if(iterator->v->visited == false)
      {
        iterator->v->visited = true;
        q.push(*(iterator->v));
        count++;
      }
    }
    if(count > max)
    {
      max = count;
    }
  }
  return max;
}
int main()
{
  Graph bet;
  bet.addVertex(1);
  bet.addVertex(2);
  bet.addVertex(3);
  bet.addVertex(6);
  bet.addVertex(5);
  bet.addVertex(4);
  bet.addEdge(2,1);
  bet.addEdge(2,3);
  bet.addEdge(2,5);
  bet.addEdge(3,2);
  bet.addEdge(4,5);
  bet.addEdge(5,4);
  bet.addEdge(5,3);
  bet.addEdge(6,3);





  int test1 = bet.mostIncoming(3);

  int test = bet.mostOutgoing(2);
  cout << test << endl;
  cout << test1<< endl;
}
