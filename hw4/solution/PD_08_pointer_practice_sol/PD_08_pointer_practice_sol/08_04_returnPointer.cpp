#include<iostream>
using namespace std;

int* maxAddr(int a, int b)
{
  int c = a;
  if(b > a)
    c = b;
  return &c;
}

int main()
{
  int a = 0, b = 0;
  cin >> a >> b;
  int* maxLoc = maxAddr(a, b);
  cout << *maxLoc << "\n";
  return 0;
}

