#include<iostream>
using namespace std;

int* maxAddr(int a, int b)
{
  int* cPtr = new int(a);
  if(b > a)
    *cPtr = b;
  return cPtr;
}

int main()
{
  int a = 0, b = 0;
  cin >> a >> b;
  int* maxLoc = maxAddr(a, b);
  cout << *maxLoc << "\n";
  
  delete maxLoc; // otherwise memory leak
  return 0;
}
