#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::addEdge(std::string v1, std::string v2, int distance)
{

  vertex * city1 = findVertex(v1);
  vertex * city2 = findVertex(v2);
  Edge nedge1;
  nedge1.v = city2;
  nedge1.distance = distance;

  city1->Edges.push_back(nedge1);

}

void Graph::addVertex(std::string name)
{
  vertex nvertex;
  nvertex.name = name;
  nvertex.district = 0;
  nvertex.visited = false;
  vertices.push_back(nvertex);
}

void Graph::displayEdges()
{
  vector <Edge>::iterator iter;
  for(int i = 0; i < vertices.size(); i++)
  {
    cout << vertices[i].district << ":" << vertices[i].name << "-->";
    for(int j = 0; j < vertices[i].Edges.size(); j++)
    {
    cout << vertices[i].Edges[j].v->name << " (" << vertices[i].Edges[j].distance << " miles)";
    if(j != vertices[i].Edges.size()-1)
    {
      cout << "***";
    }
    }
    cout << endl;
  }
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
    cout << v->name << endl;
    v->visited = true;
  }
  for(int i = 0; i < v->Edges.size(); i++)
  {
    if(v->Edges[i].v->visited == false)
    {
      cout << v->Edges[i].v->name << endl;
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

vertex* Graph::findVertex(std::string name)
{
  vertex* ptr;
  for(int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i].name == name)
    {
      ptr = &vertices[i];
      return ptr;
    }
  }
}

void Graph::assignDistricts()
{
  setAllVerticesUnvisited();
  int district = 1;

  for(int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i].visited == false)
    {
    BFTraversalLabel(vertices[i].name, district);
    district++;
    }
  }

}
void Graph::BFTraversalLabel(std::string startingCity, int distID)
{
  queue <vertex> q;
  vector <Edge>::iterator iterator;
  vertex * city = findVertex(startingCity);
  city->visited = true;
  city->district = distID;
  q.push(*city);

  while(!q.empty())
  {
    // prints out front of queue, which is edges of starting node
    vertex temp = q.front();
    cout << temp << " ";
    q.pop();
    for(iterator = temp.Edges.begin(); iterator != temp.Edges.end(); iterator++)
    {
    if(iterator->v->visited == false)
      {
        iterator->v->visited = true;
        iterator->v->district = distID;
        q.push(*(iterator->v));
      }
    }
  }

}
