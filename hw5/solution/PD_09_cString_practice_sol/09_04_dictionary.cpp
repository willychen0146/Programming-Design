#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int WORD_LEN_MAX = 51;

void makeLowercase(char* str);

int main()
{
  int wordCnt = 0;
  cin >> wordCnt;
  char target[WORD_LEN_MAX] = {0};
  cin >> target; // why cin.getline(target, WORD_LEN_MAX); fail?  
  makeLowercase(target);
  
  char** dict = new char*[wordCnt];
  for(int i = 0; i < wordCnt; i++)
  {
    dict[i] = new char[WORD_LEN_MAX];
    cin >> dict[i]; // cin.getline(dict[i], WORD_LEN_MAX);
  }
  
  // just a linear search
  bool targetExist = false;
  for(int i = 0; i < wordCnt; i++)
  {
    if(strcmp(dict[i], target) == 0)
    {
      cout << 1; 
      targetExist = true;
      break;
    }
  }
  if(targetExist == false)
    cout << 0;

  for(int i = 0; i < wordCnt; i++)
    delete [] dict[i];
  delete [] dict;

  return 0;
}

void makeLowercase(char* str)
{
  for(int i = 0; i < strlen(str); i++)
    str[i] = tolower(str[i]);
}





