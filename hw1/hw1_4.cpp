#include <iostream>

using namespace std;
    
int main(){                                                  
    int numBusStop, numOrgPeople, numPeopleUpDown, finalPeople, largestClearUpPeople; // numBusStop not include started bus stop 
    int error = 0; // initiate error (assumption: no error first)

    // get input
    cin >> numBusStop;
    cin >> numOrgPeople;

    // create the 2*x matrix to store the people up and down
    int numPeopleFlow[2][numBusStop - 1] = {0}; 

    // set finalPeople as numOrgPeople first
    finalPeople = numOrgPeople; 

    // store up and down people into matrix
    for(int i = 0; i < 2; i++){ 
        for(int j = 0; j < (numBusStop - 1); j++){
    	    cin >> numPeopleUpDown;
	        numPeopleFlow[i][j] = numPeopleUpDown;
        }
    }

    // screening for if some station numPeopleUpDown biger than the people standing on the car
    for(int i = 0; i < (numBusStop - 1); i++){
        finalPeople -= numPeopleFlow[1][i];
        if(finalPeople < 0){
            error = i + 1;
            break;
        }
        finalPeople += numPeopleFlow[0][i];
    }  

    cout << error;
    return 0;
}
