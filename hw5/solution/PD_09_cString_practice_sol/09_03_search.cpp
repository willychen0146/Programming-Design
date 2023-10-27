#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int SEN_LEN_MAX = 1000;

void makeLowercase(char str[]);

int main()
{
  char sentence[SEN_LEN_MAX + 1] = {0};
  char target[SEN_LEN_MAX + 1] = {0};
  
  cin.getline(sentence, SEN_LEN_MAX);
  cin.getline(target, SEN_LEN_MAX);  
  
  makeLowercase(sentence);
  makeLowercase(target);
  
  if(strstr(sentence, target) != nullptr)
    cout << 1;
  else
    cout << 0;
  
  return 0;
}

void makeLowercase(char str[])
{
  for(int i = 0; i < strlen(str); i++)
    str[i] = tolower(str[i]);
}
