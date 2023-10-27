#include <iostream>

using namespace std;
    
int main(){                                                  
    int numBusStop, numOrgPeople, numPeopleUpDown, finalPeople, largestClearUpPeople, temp; // numBusStop not include started bus stop 

    // get input
    cin >> numBusStop;
    cin >> numOrgPeople;

    // create the 2*x matrix to store the people up and down
    int numPeopleFlow[2][numBusStop - 1] = {0}; 

    // set finalPeople as numOrgPeople first
    finalPeople = numOrgPeople; 

    // store up and down people into matrix, and calculate final people
    for(int i = 0; i < 2; i++){ 
        for(int j = 0; j < (numBusStop - 1); j++){
    	    cin >> numPeopleUpDown;
	        numPeopleFlow[i][j] = numPeopleUpDown;

            if(i == 0){
                finalPeople += numPeopleUpDown;
            }
            if(i == 1){
                finalPeople -= numPeopleUpDown;
            }
        }
    }

    // initiate the largest num as [0][0] - [1][0]
    largestClearUpPeople = numPeopleFlow[0][0] - numPeopleFlow[1][0]; 

    // winer taking over it (largestClearUpPeople)
    for(int i = 0; i < (numBusStop - 1); i++){ 
        temp = numPeopleFlow[0][i] - numPeopleFlow[1][i];
        
        if(temp > largestClearUpPeople){
            largestClearUpPeople = temp;
        }
    }

    cout << finalPeople << "," << largestClearUpPeople;
    return 0;
}
