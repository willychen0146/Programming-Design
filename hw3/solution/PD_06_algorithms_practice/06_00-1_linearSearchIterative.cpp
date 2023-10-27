#include <iostream>
using namespace std;

const int MAX_VALUE_CNT = 100;

bool search(const int value[], int n, int t)
{
  for(int i = 0; i < n; i++)
  {
    if(value[i] == t)
      return true;
  }
  return false;
}

int main()
{
  int n = 0, t = 0;
  int value[MAX_VALUE_CNT] = {0};
  
  cin >> n >> t;
  for(int i = 0; i < n; i++)
    cin >> value[i];
    
  cout << search(value, n, t);  
  
  return 0;
}
