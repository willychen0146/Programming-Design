#include <iostream>
using namespace std;

struct Time
{
  int id; 
  int hour;
  int minute;
  int second; 
  void setTime(int h, int m, int s);
  bool isEarlierThan(Time t); 
  void print();
  void printNicely();
};

// should this be global or a member of Time?
void printTwoDigits(int n);

void Time::setTime(int h, int m, int s)
{
  hour = h;
  minute = m;
  second = s;
}

bool Time::isEarlierThan(Time t)
{
  int mySec = hour * 3600 + minute * 60 + second;
  int itsSec = t.hour * 3600 + t.minute * 60 + t.second;
  if(mySec < itsSec)
    return true;
  else 
    return false;  
} 

void Time::print()
{
  cout << hour << ":" 
       << minute << ":" 
       << second;
}

void Time::printNicely()
{
  printTwoDigits(hour);
  cout << ":"; 
  printTwoDigits(minute); 
  cout << ":"; 
  printTwoDigits(second);
}

void printTwoDigits(int n)
{
  cout << (n < 10 ? "0" : "");
  cout << n; 
}

void insertionSort(const Time unsorted[], int sortedIndices[], int len);

int main()
{
  int timeCnt = 0;
  cin >> timeCnt;

  Time* unsorted = new Time[timeCnt];
  int* sortedIndices = new int[timeCnt];
  
  for(int i = 0; i < timeCnt; i++)
    unsorted[i].id = i + 1;
  for(int i = 0; i < timeCnt; i++)
    cin >> unsorted[i].hour;
  for(int i = 0; i < timeCnt; i++)
    cin >> unsorted[i].minute;
  for(int i = 0; i < timeCnt; i++)
    cin >> unsorted[i].second;

  insertionSort(unsorted, sortedIndices, timeCnt);
  delete [] unsorted;

  for(int i = 0; i < timeCnt - 1; i++)
  {
    cout << sortedIndices[i];
    cout << " ";
  }
  cout << sortedIndices[timeCnt - 1];

  delete [] sortedIndices;
    
  return 0;
}

void insertionSort(const Time unsorted[], int sortedIndices[], int len)
{
  Time* sorted = new Time[len];

  for(int i = 0; i < len; i++)
    sorted[i] = unsorted[i];
  
  for(int i = 0; i < len; i++)
  {
    for(int j = i; j > 0; j--)
    {
      if(sorted[j].isEarlierThan(sorted[j - 1]))
      {
        Time temp = sorted[j];
        sorted[j] = sorted[j - 1];
        sorted[j - 1] = temp;
      }
      else
        break;
    }
  }
  
  for(int i = 0; i < len; i++)
    sortedIndices[i] = sorted[i].id;
  
  delete [] sorted;
}
