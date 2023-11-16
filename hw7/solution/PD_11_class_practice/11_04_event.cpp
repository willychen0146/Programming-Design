#include <iostream>
#include <cstring> 
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
  Time();
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






class Event
{
private:
  char* name;
  Time start;
  Time end;
public:
  Event(char* n, Time s, Time t);
  ~Event();
  void printNicely();
};

Event::Event(char* n, Time s, Time t)
{
  int nameLen = strlen(n);
  name = new char[nameLen + 1];
  strcpy(name, n);
  start = s;
  end = t;
}

Event::~Event()
{
  delete [] name;
}

void Event::printNicely()
{
  cout << "\"" << name << "\"\n";
  cout << "Start: ";
  start.printNicely();
  cout << "\n";
  cout << "End:   ";
  end.printNicely();
  cout << "\n";
}










int main()
{
  char n1[] = "PD";
  Event e1(n1, Time(14, 20, 0), Time(17, 20, 0));
  e1.printNicely(); // "PD"
                    // Start: 14:20:00
                    // End:   17:20:00
    
  return 0;
}





void printTwoDigits(int n)
{
  cout << (n < 10 ? "0" : "");
  cout << n; 
}
