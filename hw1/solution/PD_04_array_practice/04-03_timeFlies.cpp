#include <iostream>
using namespace std;

const int NUM_VALUES_MAX = 10;

int main()
{
    // read data
    int numValues = 0;
    int target = 0;
    cin >> numValues >> target; 
    
    int values[NUM_VALUES_MAX] = {0};
    for(int i = 0; i < numValues; i++)
    {
        cin >> values[i];
    }
    
    // do some calculation
    int sum = 0;
    
    for(int i = 0; i < numValues; i++)
    {
        if(target == values[i])
            break;
        else
            sum += values[i];
    }
    
    // output results
    cout << sum;  

    return 0;
}

