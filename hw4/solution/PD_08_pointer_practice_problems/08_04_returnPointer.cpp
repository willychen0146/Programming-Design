#include<iostream>
using namespace std;

int* max(int a, int b)
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
  int* maxAddr = max(a, b);
  cout << *maxAddr << "\n";
  return 0;
}

