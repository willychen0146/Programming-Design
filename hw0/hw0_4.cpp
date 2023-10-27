#include <iostream>

using namespace std;

int main(){
	int numPeople, threshold, feet, inches, totalNum;
    cin >> numPeople;
    cin >> threshold;
    totalNum = 0;

    for (int i = 0; i <= (numPeople-1); i++){
            cin >> inches;
            feet = inches / 12; 
            
            if(feet >= threshold){
                totalNum += 1;
            }
    }

    cout << totalNum;
	return 0;
}

