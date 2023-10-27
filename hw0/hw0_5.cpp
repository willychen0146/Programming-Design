#include <iostream>

using namespace std;

int main(){
	int numPeople, threshold;
    int feet, inches;
    int numPosition;
    int numGuard = 0, numForward = 0, numCenter = 0;

    cin >> Numpeople;
    cin >> threshold;

    for (int i = 0; i <= (numPeople-1); i++){
            cin >> inches;
            feet = inches / 12; 

            cin >> Numposition;
            
            if((feet >= threshold) && (Numposition == 1)){
                numGuard += 1;
            }
            if((feet >= threshold) && (Numposition == 2)){
                numForward += 1;
            }
            if((feet >= threshold) && (Numposition == 3)){
                numCenter += 1;
            }
    }

    cout << numGuard << "," << numForward << "," << numCenter;
	return 0;
}

