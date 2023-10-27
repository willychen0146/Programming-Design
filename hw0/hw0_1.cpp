#include <iostream>

using namespace std;

int main(){
	int feet, feetInches, inches;
	cin >> inches;
	feet = inches / 12; 
	feetInches = inches % 12;
	cout << feet << "," << feetInches;
	return 0;
}

