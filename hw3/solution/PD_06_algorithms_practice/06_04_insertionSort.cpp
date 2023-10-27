#include <iostream>
using namespace std;

const int VALUE_CNT_MAX = 100; 

void insertionSort(const int unsorted[], int sorted[], int len);

int main()
{
  int valueCnt = 0;
  int values[VALUE_CNT_MAX] = {0};
  int sortedValues[VALUE_CNT_MAX] = {0}; 
  
  cin >> valueCnt;
  for(int i = 0; i < valueCnt; i++)
    cin >> values[i];
   
  insertionSort(values, sortedValues, valueCnt);

  for(int i = 0; i < valueCnt - 1; i++)
    cout << sortedValues[i] << ","; 
  cout << sortedValues[valueCnt - 1];

  return 0;
}

void insertionSort(const int unsorted[], int sorted[], int len)
{
  for(int i = 0; i < len; i++)
    sorted[i] = unsorted[i];
    
  for(int i = 0; i < len; i++)
  {
    for(int j = i; j > 0; j--)
    {
      if(sorted[j] < sorted[j - 1])
      {
        int temp = sorted[j];
        sorted[j] = sorted[j - 1];
        sorted[j - 1] = temp;
      }
      else
        break;
    }
  }    
}
