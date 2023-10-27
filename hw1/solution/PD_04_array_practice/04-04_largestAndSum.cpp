#include <iostream>
using namespace std;

int main()
{
    int valueCnt = 0;
    cin >> valueCnt; 
    
    int largest = -100; // why not 0? 
    int total = 0; 
    for(int i = 0; i < valueCnt; i++)
    {
        int theValue = 0;
    cin >> theValue;
    
    if(theValue > largest)
        largest = theValue;
    
    total += theValue;   
    } 
    
    cout << largest << "," << total; 
    
    return 0;
}
