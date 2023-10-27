#include<iostream>
using namespace std; 

struct Time
{
  int hour;
  int minute;
  int second;
  void setTime(int h, int m, int s);
  bool isEarlierThan(Time t); 
  void print();
};

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

int main()
{
  const int TIME_CNT = 3;
  const int TIME_ELE_CNT = 3; 
   
  int input[TIME_CNT * TIME_ELE_CNT] = {0};
  for(int i = 0; i < TIME_CNT * TIME_ELE_CNT; i++)
    cin >> input[i];
    
  Time t[TIME_CNT];
  for(int i = 0; i < TIME_CNT; i++)
    t[i] = {input[i * TIME_ELE_CNT], 
	        input[i * TIME_ELE_CNT + 1], 
		    input[i * TIME_ELE_CNT + 2]}; 

  if(t[0].isEarlierThan(t[1]))
  {
    if(t[1].isEarlierThan(t[2]))
	  cout << 3;
	else
	  cout << 2; 
  } 
  else
  {
    if(t[0].isEarlierThan(t[2]))
	  cout << 3;
	else
	  cout << 1; 
  } 
  
  return 0;
}

