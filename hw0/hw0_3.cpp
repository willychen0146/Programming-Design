#include <iostream>

using namespace std;

int main(){
	int feet, feetInches, inches, type, iteration;
    cin >> iteration;

    for (int i = 0; i <= (iteration-1); i++){
        cin >> type;

        if (type == 0){
            cin >> inches;
            feet = inches / 12; 
            feetInches = inches % 12;
            cout << feet << "," << feetInches << "\n";
        }
        else if(type == 1){
            cin >> feet;
            inches = feet * 12;
            cout << inches << "\n";
        }

    }

	return 0;
}

