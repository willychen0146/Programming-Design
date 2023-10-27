#include <iostream>
using namespace std;

const int VALUE_CNT_MAX = 100; 

bool binarySearch(int values[], int indexFrom, int indexTo, int target);

int main()
{
  int valueCnt = 0;
  int target = 0;
  int values[VALUE_CNT_MAX] = {0};
  
  cin >> valueCnt >> target;
  for(int i = 0; i < valueCnt; i++)
    cin >> values[i];
  
  cout << binarySearch(values, 0, valueCnt - 1, target);
  
  return 0;
}

bool binarySearch(int values[], int indexFrom, int indexTo, int target)
{
  if(indexFrom > indexTo)
    return false;
    
  int median = values[(indexFrom + indexTo) / 2];

  if(indexFrom == indexTo)
    return (values[indexTo] == target);
  else
  {		
    if(target == median)
      return true;
    else if(target < median)
      return binarySearch(values, indexFrom, (indexFrom + indexTo) / 2 - 1, target);
    else 
      return binarySearch(values, (indexFrom + indexTo) / 2 + 1, indexTo, target);
  }
}

