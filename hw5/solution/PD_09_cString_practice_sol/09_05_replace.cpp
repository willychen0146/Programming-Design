#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int WORD_CNT_MAX = 100;
const int SEN_LEN_MAX = 1000;
const int WORD_LEN_MAX = 51;

bool hasZero(char* word);
bool hasAlphaDigit(char* word);
bool hasPunct(char* word);

int main()
{
  char sentence[SEN_LEN_MAX + 1] = {0};
  cin.getline(sentence, SEN_LEN_MAX);

  // get words split by spaces
  char delim[] = " ";
  char word[WORD_CNT_MAX][WORD_LEN_MAX] = {0};
  int wordCnt = 0;
  char* start = strtok(sentence, delim);
  while(start != nullptr)
  {
    strcpy(word[wordCnt], start);
    wordCnt++;
    start = strtok(nullptr, delim);
  }
    
  for(int i = 0; i < wordCnt; i++)
  {
    // determine whether it has a "0" and no other letters and digits
    if(hasZero(word[i]) == true && hasAlphaDigit(word[i]) == false)
    {
      // determine whether it is just a "0"
      if(hasPunct(word[i]) == false)
        strcpy(word[i], "zero");
      else
      {
        char tempWord[WORD_LEN_MAX] = "";
        strcpy(tempWord, "zero");
        strcat(tempWord, &word[i][1]);
        strcpy(word[i], tempWord);
      }        
    }
  }
  
  for(int i = 0; i < wordCnt; i++)
    cout << word[i] << " ";

  return 0;
}

bool hasZero(char* word)
{
  for(int i = 0; i < strlen(word); i++)
  {
    if(word[i] == '0')
      return true;
  }
  return false;
}

bool hasAlphaDigit(char* word)
{
  for(int i = 0; i < strlen(word); i++)
  {
    if(word[i] != '0' && isalnum(word[i]) != 0)
      return true;
  }
  return false;
}

bool hasPunct(char* word)
{
  for(int i = 0; i < strlen(word); i++)
  {
    if(ispunct(word[i]) != 0)
      return true;
  }
  return false;
}

