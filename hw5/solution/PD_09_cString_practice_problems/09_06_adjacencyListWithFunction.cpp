#include<iostream>
using namespace std;

int inputGraphInfo(int**& neighbors, int*& degrees);
void printGraph(const int** neighbors, const int* degrees, int nodeCnt);
void releaseMemory(int** neighbors, int* degrees, int nodeCnt);

int main()
{
  // reading data from the input 
  int nodeCnt = 0;
  int** neighbors = nullptr;
  int* degrees = nullptr;

  nodeCnt = inputGraphInfo(neighbors, degrees);
  
  // printing out the desired results
  printGraph(const_cast<const int**>(neighbors), 
             const_cast<const int*>(degrees), nodeCnt);

  // release the dynamically allocated memory
  releaseMemory(neighbors, degrees, nodeCnt);

  return 0;
}

