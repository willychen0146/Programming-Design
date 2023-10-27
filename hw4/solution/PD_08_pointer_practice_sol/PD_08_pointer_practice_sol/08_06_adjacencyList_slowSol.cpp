#include<iostream>
using namespace std;

bool isNeighbor(int* neighbors[], const int degrees[], int node1, int node2);
 
int main()
{
  // reading data from the input 
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
  
  // printing out the desired results in a matrix
  for(int i = 0; i < nodeCnt; i++)
  {
    for(int j = 0; j < nodeCnt - 1; j++)
      cout << isNeighbor(neighbors, degrees, i, j) << " ";   
    cout << isNeighbor(neighbors, degrees, i, nodeCnt - 1) << "\n";
  }  
  
  // release the dynamically allocated memory
  for(int i = 0; i < nodeCnt; i++)
    delete [] neighbors[i];
  delete [] neighbors;
  delete [] degrees;

  return 0;
}

bool isNeighbor(int* neighbors[], const int degrees[], int node1, int node2)
{
  for(int i = 0; i < degrees[node1]; i++)
  {
    if(node2 == neighbors[node1][i])
      return true;
  }
  return false;
}
