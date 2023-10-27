#include <iostream>
using namespace std;

const int MAX_VALUE_CNT = 100;

// assuming valueCnt >= 2 
int secondLargest(const int values[], int valueCnt, int firstTwo[]);

int main()
{
  int valueCnt = 0;
  int values[MAX_VALUE_CNT] = {0};
  
  cin >> valueCnt;
  for(int i = 0; i < valueCnt; i++)
    cin >> values[i];
  
  int firstTwo[2] = {0};  
  secondLargest(values, valueCnt, firstTwo);  
  
  cout << firstTwo[1]; 
  
  return 0;
}

int secondLargest(const int values[], int valueCnt, int firstTwo[])
{
  if(valueCnt == 2)
  {
    firstTwo[0] = values[0];
	firstTwo[1] = values[1];

    if(values[0] < values[1])
    {
      firstTwo[1] = values[0];
	  firstTwo[0] = values[1]; 
	}
  }
  else
  {
    int last = values[valueCnt - 1];
    secondLargest(values, valueCnt - 1, firstTwo);
  
    if(last >= firstTwo[0]) 
    {
      firstTwo[1] = firstTwo[0];
	  firstTwo[0] = last; 
    }
    else if(last > firstTwo[1])
    {
      firstTwo[1] = last;
    } 
  } 
}
