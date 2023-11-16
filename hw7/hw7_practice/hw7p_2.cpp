#include <iostream>
using namespace std;

struct Time
{
  int hour;
  int minute;
  int second;
  void setTime(int h, int m, int s);
  bool isEarlierThan(int t)
  void print();
  void printNicely();
};

void Time::setTime(int h, int m, int s)
{
  hour = h;
  minute = m;
  second = s;
}

void Time::print()
{
  cout << hour << ":"
       << minute << ":"
       << second;
}

void Time::printNicely()
{
	if(hour < 10)
		cout << "0" << hour << ":";
	else
  		cout << hour << ":";
	if(minute < 10)
		cout << "0" << minute << ":";
	else
  		cout << minute << ":";
	if(second < 10)
		cout << "0" << second;
	else
  		cout << second;
}

bool Time::isEarlierThan(int t1, int t2){
	int total1. total2;
	total1 = hour * 3600 + minute * 60 + second;
	total2 = t.hour * 3600 + minute * 60 + second;
	if(total1 < total2)
		return true;
	else
		return false;
}

int main(){
	int temp1, temp2, temp3;
	cin >> temp1 >> temp2 >> temp3;
	Time t1 = {temp1, temp2, temp3};
	cin >> temp1 >> temp2 >> temp3;
	Time t2 = {temp1, temp2, temp3};
	cin >> temp1 >> temp2 >> temp3;
	Time t3 = {temp1, temp2, temp3};
	if(t2.isEarlierThan)	
	
  	
    return 0;
}

