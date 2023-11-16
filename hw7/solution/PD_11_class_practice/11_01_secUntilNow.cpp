#include <iostream>
using namespace std;

void printTwoDigits(int n);

class Time
{
private:
  int hour;
  int minute;
  int second;
  int secUntilNow();
public:
  Time(); 
  Time(int h, int m, int s);
  void setTime(int h, int m, int s); 
  bool isEarlierThan(Time t);
  void print();
  void printNicely();
};

int Time::secUntilNow()
{
  return 3600 * hour + 60 * minute + second;
}

Time::Time()
{
  hour = 0;
  minute = 0;
  second = 0; 
} 

Time::Time(int h, int m, int s)
{
  hour = h;
  minute = m;
  second = s;
}

void Time::setTime(int h, int m, int s)
{
  hour = h;
  minute = m;
  second = s; 
} 

bool Time::isEarlierThan(Time t)
{
  int numSecSelf = secUntilNow();
  int numSecT = t.secUntilNow();
  if(numSecSelf < numSecT)
    return true;
  else
    return false;
}

void Time::print()
{
  cout << hour << ":" << minute << ":" << second;
}

void Time::printNicely()
{
  printTwoDigits(hour);
  cout << ":"; 
  printTwoDigits(minute); 
  cout << ":"; 
  printTwoDigits(second);
}






int main()
{
  Time t1(14, 30, 0); 
  Time t2; // should be set to 00:00:00
  t2.print(); // 0:0:0
  cout << "\n";
  t2.setTime(14, 25, 5);
  
  if(t2.isEarlierThan(t1))
  {
    t2.print(); // 14:25:5
    cout << "\n";
    t2.printNicely(); // 14:25:05
  }
  
  return 0;
}





void printTwoDigits(int n)
{
  cout << (n < 10 ? "0" : "");
  cout << n; 
}

