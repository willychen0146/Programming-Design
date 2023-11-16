#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void makeLowercase(string& str);

int main()
{
  int wordCnt = 0;
  cin >> wordCnt;
  string target = "";
  cin >> target;
  makeLowercase(target);
  
  string* dict = new string[wordCnt];
  for(int i = 0; i < wordCnt; i++)
    cin >> dict[i];
  
  // just a linear search
  bool targetExist = false;
  for(int i = 0; i < wordCnt; i++)
  {
    if(target.compare(dict[i]) == 0)
    {
      cout << 1; 
      targetExist = true;
      break;
    }
  }
  if(targetExist == false)
    cout << 0;

  delete [] dict;

  return 0;
}

void makeLowercase(string& str)
{
  for(int i = 0; i < str.length(); i++)
    str[i] = tolower(str[i]);
}
