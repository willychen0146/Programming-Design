#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int SEN_LEN_MAX = 1000;

int main()
{
  char sentence[SEN_LEN_MAX + 1] = {0};
  cin.getline(sentence, SEN_LEN_MAX);
  
  sentence[0] = toupper(sentence[0]);
  
  for(int i = 1; i < strlen(sentence); i++)
  {
    if(sentence[i - 1] == ' ')
      sentence[i] = toupper(sentence[i]);
    else
      sentence[i] = tolower(sentence[i]);      
  }
  
  cout << sentence;
  
  return 0;
}

