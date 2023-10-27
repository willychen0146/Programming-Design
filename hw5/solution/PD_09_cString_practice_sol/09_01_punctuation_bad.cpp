#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int SEN_LEN_MAX = 1000;

int main()
{
  char sentence[SEN_LEN_MAX + 1] = {0};
  cin.getline(sentence, SEN_LEN_MAX);
  
  int punctCnt;
  for(int i = 0; i < SEN_LEN_MAX; i++)
  {
    if(sentence[i] == ',' || sentence[i] == '.'
      || sentence[i] == ':' || sentence[i] == ';'
      || sentence[i] == '!' || sentence[i] == '?')
      punctCnt++;
  }
  
  cout << punctCnt;
  
  return 0;
}

