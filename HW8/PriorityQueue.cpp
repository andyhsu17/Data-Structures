#include "PriorityQueue.hpp"
#include <iostream>
#include <fstream>
using namespace std;

PriorityQueue::PriorityQueue(int queueSize)
{
  priorityQueue = new PatientNode[queueSize];
  currentQueueSize = 0;
  maxQueueSize = queueSize;
}

PriorityQueue::~PriorityQueue()
{
  delete [] priorityQueue;
}

void PriorityQueue::enqueue(std::string _name, int _injurySeverity, int _treatmentTime)
{
  if(isFull())
  {
    return;
  }
  PatientNode patient;
  patient.name = _name;
  patient.injurySeverity = _injurySeverity;
  patient.treatmentTime = _treatmentTime;
  priorityQueue[currentQueueSize+1] = patient;
  currentQueueSize++;
  repairUpward(currentQueueSize);

}

void PriorityQueue::dequeue()
{

  priorityQueue[1] = priorityQueue[currentQueueSize];
  currentQueueSize--;
  repairDownward(1);

}

std::string PriorityQueue::peekName()
{
  return priorityQueue[1].name;
}

int PriorityQueue::peekInjurySeverity()
{
  return priorityQueue[1].injurySeverity;
}

int PriorityQueue::peekTreatmentTime()
{
  return priorityQueue[1].treatmentTime;
}

bool PriorityQueue::isFull()
{
  if(currentQueueSize == maxQueueSize)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool PriorityQueue::isEmpty()
{
  if(currentQueueSize == 0)
  {
    return true;
  }

  else
  {
    return false;
  }
}

void PriorityQueue::repairUpward(int nodeIndex)
{

  if(nodeIndex == 1)
  {
    return;
  }

  if(priorityQueue[nodeIndex].injurySeverity > priorityQueue[nodeIndex/2].injurySeverity)
  {
    PatientNode temp = priorityQueue[nodeIndex];
    priorityQueue[nodeIndex] = priorityQueue[nodeIndex/2];
    priorityQueue[nodeIndex/2] = temp;
    repairUpward(nodeIndex/2);
  }

  else if(priorityQueue[nodeIndex].injurySeverity == priorityQueue[nodeIndex/2].injurySeverity)
  {
    if(priorityQueue[nodeIndex].treatmentTime < priorityQueue[nodeIndex/2].treatmentTime)
    {
      PatientNode temp = priorityQueue[nodeIndex];
      priorityQueue[nodeIndex] = priorityQueue[nodeIndex/2];
      priorityQueue[nodeIndex/2] = temp;
      repairUpward(nodeIndex/2);
    }
  }
  return;

}

void PriorityQueue::repairDownward(int nodeIndex)
{

  if(nodeIndex > currentQueueSize/2)
  {
    return;
  }
  if(priorityQueue[nodeIndex].injurySeverity < priorityQueue[2*nodeIndex].injurySeverity)
  {
    PatientNode temp = priorityQueue[nodeIndex];
    priorityQueue[nodeIndex] = priorityQueue[2*nodeIndex];
    priorityQueue[2*nodeIndex] = temp;
    repairDownward(2*nodeIndex);
  }
  if(priorityQueue[nodeIndex].injurySeverity < priorityQueue[2*nodeIndex+1].injurySeverity)
  {
    PatientNode temp = priorityQueue[nodeIndex];
    priorityQueue[nodeIndex] = priorityQueue[2*nodeIndex+1];
    priorityQueue[2*nodeIndex+1] = temp;
    repairDownward(2*nodeIndex+1);
  }
  if(priorityQueue[nodeIndex].injurySeverity == priorityQueue[2*nodeIndex].injurySeverity)
  {
    if(priorityQueue[nodeIndex].treatmentTime > priorityQueue[2*nodeIndex].treatmentTime)
    {
      PatientNode temp = priorityQueue[nodeIndex];
      priorityQueue[nodeIndex] = priorityQueue[2*nodeIndex];
      priorityQueue[2*nodeIndex] = temp;
      repairDownward(2*nodeIndex);
    }
  }
  if(priorityQueue[nodeIndex].injurySeverity == priorityQueue[2*nodeIndex+1].injurySeverity)
  {
    if(priorityQueue[nodeIndex].treatmentTime > priorityQueue[2*nodeIndex+1].treatmentTime)
    {
      PatientNode temp = priorityQueue[nodeIndex];
      priorityQueue[nodeIndex] = priorityQueue[2*nodeIndex+1];
      priorityQueue[2*nodeIndex+1] = temp;
      repairDownward(2*nodeIndex+1);
    }
  }
  return;
}
