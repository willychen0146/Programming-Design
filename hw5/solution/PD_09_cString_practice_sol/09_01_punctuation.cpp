#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int SEN_LEN_MAX = 1000;

int main()
{
  char sentence[SEN_LEN_MAX + 1] = {0};
  cin.getline(sentence, SEN_LEN_MAX);
  
  int punctCnt = 0;
  for(int i = 0; i < strlen(sentence); i++)
  {
    if(ispunct(sentence[i]) != 0)
      punctCnt++;
  }
  
  cout << punctCnt;
  
  return 0;
}

