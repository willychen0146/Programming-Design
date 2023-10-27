#include <iostream>

using namespace std;

int main(){
	int feet, feetInches, inches, type;
	cin >> type;

    if (type == 0){
        cin >> inches;
	    feet = inches / 12; 
	    feetInches = inches % 12;
	    cout << feet << "," << feetInches;
    }
    else if(type == 1){
        cin >> feet;
        inches = feet * 12;
	    cout << inches;
    }

	return 0;
}

