#include <iostream>
using namespace std;

void printTwoDigits(int n);

class Time
{
private:
  static bool hourIn12;
  int hour;
  int minute;
  int second;
  int secUntilNow();
public:
  Time(int h, int m, int s);
  static void set12Hour(bool in12);
  bool isEarlierThan(Time t);
  void print();
  void printNicely();
};

bool Time::hourIn12 = false;

void Time::set12Hour(bool in12)
{
  Time::hourIn12 = in12;
}

int Time::secUntilNow()
{
  return 3600 * hour + 60 * minute + second;
}

Time::Time(int h, int m, int s)
{
  hour = h;
  minute = m;
  second = s;
}

bool Time::isEarlierThan(Time t)
{
  int numSecSelf = 3600 * hour + 60 * minute + second;
  int numSecT = 3600 * t.hour + 60 * t.minute + t.second;
  if(numSecSelf < numSecT)
    return true;
  else
    return false;
}

void Time::print()
{
  if(Time::hourIn12 == false)
    cout << hour << ":" << minute << ":" << second;
  else
  {
    if(hour < 12)
      cout << hour << ":" << minute << ":" << second << " AM";
    else
      cout << (hour - 12) << ":" << minute << ":" << second << " PM";      
  }
}

void Time::printNicely()
{
  if(Time::hourIn12 == false || hour < 12)
    printTwoDigits(hour);
  else
    printTwoDigits(hour - 12);
  cout << ":"; 
  
  printTwoDigits(minute); 
  cout << ":"; 
  
  printTwoDigits(second);
  
  if(hourIn12 == true)
    cout << (hour < 12 ? " AM" : " PM");
}






int main()
{
  Time t1(14, 30, 0); 
  Time t2(14, 25, 5);
  
  t1.printNicely();
  cout << "\n";
  t2.print();
  cout << "\n";

  Time::set12Hour(true);

  t1.printNicely();
  cout << "\n";
  t2.print();
  cout << "\n";
  
  return 0;
}





void printTwoDigits(int n)
{
  cout << (n < 10 ? "0" : "");
  cout << n; 
}


