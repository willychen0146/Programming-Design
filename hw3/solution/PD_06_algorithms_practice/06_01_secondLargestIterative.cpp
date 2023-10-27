#include <iostream>
using namespace std;

const int MAX_VALUE_CNT = 100;

// assuming valueCnt >= 2 
int secondLargest(const int values[], int valueCnt);

int main()
{
  int valueCnt = 0;
  int values[MAX_VALUE_CNT] = {0};
  
  cin >> valueCnt;
  for(int i = 0; i < valueCnt; i++)
    cin >> values[i];
    
  cout << secondLargest(values, valueCnt);  
  
  return 0;
}

int secondLargest(const int values[], int valueCnt)
{
  int first = values[0];
  int second = values[1];
  if(second > first)
  {
    int temp = first;
	first = second;
	second = temp; 
  } 
  
  for(int i = 2; i < valueCnt; i++)
  {
    int cur = values[i];
	
	if(cur >= first)
	{
	  second = first;
	  first = cur; 
	}
	else if(cur > second)
	  second = cur; 
  }
  
  return second; 
}
