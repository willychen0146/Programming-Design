#include <iostream>
#include <string>
using namespace std;

const int MAX_DIGIT = 100;

string toDollarNumber(int value)
{
  // one way of converting an integer to a C++ string
  // char c[MAX_DIGIT] = {0};
  // itoa(value, c, 10);
  // string s = c;

  // another way
  string s = to_string(value);
  
  string dn = "$";
  int n = s.length();

  int startPos = n % 3;
  if(startPos == 1)
    dn = dn + s[0] + ",";
  else if(startPos == 2)
    dn = dn + s.substr(0, 2) + ",";

  for(int i = startPos; i < n; i += 3)
    dn = dn + s.substr(i, 3) + ",";
  dn.erase(dn.length() - 1);
  
  return dn;
}

int main()
{
  int dollar = 0;
  cin >> dollar; 
  
  cout << toDollarNumber(dollar) << endl;
  
  return 0;
}

