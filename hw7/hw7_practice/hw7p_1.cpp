#include <iostream>
#include <cstring>
using namespace std;

void printTwoDigits(int n);

class Time{
private:
  int hour;
  int minute;
  int second;
  static bool format_12;
public:
  Time(); 
  Time(int h, int m, int s);
  void setTime(int h, int m, int s); 
  bool isEarlierThan(Time t);
  int secUtilNow();
  void print();
  void printNicely();
  static void which_format(bool is_12);
};

class Event{
private:
  char* name;
  Time start;
  Time end;
public:
  Event(char* n, Time s, Time t);
  Event(const Event& event);
  ~Event();
  void setName(char* n);
  void printNicely();
}

bool Time::format_12 = false;

Time::Time(){
  hour = 0;
  minute = 0;
  second = 0; 
} 

Time::Time(int h, int m, int s){
  hour = h;
  minute = m;
  second = s;
}

void Time::setTime(int h, int m, int s){
  hour = h;
  minute = m;
  second = s; 
} 

bool Time::isEarlierThan(Time t){
  int numSecSelf = secUtilNow();
  int numSecT = t.secUtilNow();
  if(numSecSelf < numSecT)
    return true;
  else
    return false;
}

void Time::print(){
  if(format_12 == false || hour <= 12)
    cout << hour << ":" << minute << ":" << second;
  else {
    cout << hour-12 << ":" << minute << ":" << second;
  }
}

void Time::printNicely(){
  if(format_12 == false || hour <= 12)
    printTwoDigits(hour);
  else {
    printTwoDigits(hour-12)
  }
  cout << ":"; 
  printTwoDigits(minute); 
  cout << ":"; 
  printTwoDigits(second);
}

int Time::secUtilNow(){
  return 3600 * h + 60 * m + s;
}

void Time::which_format(bool is_12){
  Time::format_12 = true;
}

Event::Event(char* n, Time s, Time t){
  int len = strlen(n);
  name = new char[len + 1];
  strcpy(name, n);
  start = s;
  end = t;
}

Event::~Event(){
  delete [] name;
}

Event::Event(const Event& event){
  int len = strlen(event.name);
  start = event.start;
  end = event.end;
  name = new char[len + 1];
  strcpy(name, event.name);
}
  
void Event::printNicely(){
  cout <<  *name  << endl;
  cout << "Start: ";
  start.printNicely();
  cout << endl;
  cout << "End: ";
  end.printNicely();
  cout << endl;
}

void Event::setName(char* n){
  delete [] name;
  int len = strlen(n);
  name = new char[len + 1];
  strcpy(name, n);
}

int main(){
  Time t1(14, 30, 0); 
  Time t2; // should be set to 00:00:00
  t2.print(); // 0:0:0
  cout << "\n";
  t2.setTime(14, 25, 5);
  
  if(t2.isEarlierThan(t1)){
    t2.print(); // 14:25:5
    cout << "\n";
    t2.printNicely(); // 14:25:05
  }
  
  return 0;
}





void printTwoDigits(int n){
  cout << (n < 10 ? "0" : "");
  cout << n; 
}



