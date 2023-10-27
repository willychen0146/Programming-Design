#include <iostream>

using namespace std;
    
int main(){                                                  
    int numBusStop, numOrgPeople, numPeopleUp, numPeopleDown, finalPeople; //not include start bus stop
    cin >> numBusStop;
    cin >> numOrgPeople;

    for(int i = 0; i < (numBusStop - 1); i++){                                                                        
        cin >> numPeopleUp;                                  
        numOrgPeople += numPeopleUp;
    }
    for(int j = 0; j < (numBusStop - 1); j++){                                                                        
        cin >> numPeopleDown;
        numOrgPeople -= numPeopleDown;
    }
    
    finalPeople  = numOrgPeople;
    cout << finalPeople;
    return 0;
}
