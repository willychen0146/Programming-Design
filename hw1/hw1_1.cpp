#include <iostream>

using namespace std;

int main(){
    int numBusStop, numOrgPeople, numPeople, finalPeople; //not include start bus stop                        
    cin >> numBusStop;
    cin >> numOrgPeople;

    while(numBusStop > 1){
        cin >> numPeople;                                    
	numOrgPeople -= numPeople;                           
        finalPeople  = numOrgPeople;                         
        numBusStop -= 1;                             
    }
    cout << finalPeople;
    return 0;
}
