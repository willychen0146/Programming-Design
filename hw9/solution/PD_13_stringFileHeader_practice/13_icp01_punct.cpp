#include <iostream>
#include <string>
using namespace std;

bool isMyPunct(char c, string punct);

int main()
{
  string s = "";
  getline(cin, s);
  
  int numMyPunct = 0;
  for(int i = 0; i < s.length(); i++)
    if(isMyPunct(s[i], ",.:;!?"))
      numMyPunct++;
  
  cout << numMyPunct << endl;
  
  return 0;
}

bool isMyPunct(char c, string punct)
{
  for(int i = 0; i < punct.length(); i++)
    if(c == punct[i])
      return true;
  return false;
}


