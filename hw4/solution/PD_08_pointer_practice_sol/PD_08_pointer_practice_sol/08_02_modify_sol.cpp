#include<iostream>
using namespace std;

int main()
{
  int a = 0;
  int* aPtr = &a;
  cin >> *aPtr;
  cout << a << "\n";

  return 0;  
}
