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

int inputGraphInfo(int**& neighbors, int*& degrees)
{
  int nodeCnt = 0;
  cin >> nodeCnt;
  neighbors = new int*[nodeCnt];
  degrees = new int[nodeCnt];
  
  for(int i = 0; i < nodeCnt; i++)
  {
    cin >> degrees[i];
    neighbors[i] = new int[degrees[i]];
    for(int j = 0; j < degrees[i]; j++)
      cin >> neighbors[i][j];
  }  
  
  return nodeCnt;
}

void printGraph(const int** neighbors, const int* degrees, int nodeCnt)
{
  for(int i = 0; i < nodeCnt; i++)
  {
    for(int j = 0; j < degrees[i] - 1; j++)
      cout << neighbors[i][j] << " ";
    cout << neighbors[i][degrees[i] - 1] << "\n";
  }
}

void releaseMemory(int** neighbors, int* degrees, int nodeCnt)
{
  for(int i = 0; i < nodeCnt; i++)
    delete [] neighbors[i];
  delete [] neighbors;
  delete [] degrees;
}

