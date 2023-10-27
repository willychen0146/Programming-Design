#include<iostream>
using namespace std;

int main()
{
  // Step 1: reading data from the input 
  int nodeCnt = 0;
  int** neighbors = nullptr;
  int* degrees = nullptr;
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
  
  // Step 2: printing out the desired results
  // Step 2.1: create an empty adjacency matrix
  int** matrix = new int*[nodeCnt];
  for(int i = 0; i < nodeCnt; i++)
  {
    matrix[i] = new int[nodeCnt];
    for(int j = 0; j < nodeCnt; j++)
      matrix[i][j] = 0;
  }
  
  // Step 2.2: fill in the matrix
  for(int i = 0; i < nodeCnt; i++)
  {
    // for each node i, let's ...
    for(int j = 0; j < degrees[i]; j++)
    {
      // the jth neighbor of node i
      int neighborID = neighbors[i][j];
      matrix[i][neighborID] = 1;
    }
  }
  
  // Step 2.3: print out the matrix
  for(int i = 0; i < nodeCnt; i++)
  {
    for(int j = 0; j < nodeCnt - 1; j++)
      cout << matrix[i][j] << " ";
    cout << matrix[i][nodeCnt - 1] << "\n";
  }
  
  // Step 2.4: release the dynamically allocated memory
  for(int i = 0; i < nodeCnt; i++)
    delete [] matrix[i];
  delete [] matrix;  
  
  // Step 3: release the dynamically allocated memory
  for(int i = 0; i < nodeCnt; i++)
    delete [] neighbors[i];
  delete [] neighbors;
  delete [] degrees;

  return 0;
}

