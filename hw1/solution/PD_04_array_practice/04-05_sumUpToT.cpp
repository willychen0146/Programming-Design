#include <iostream>
using namespace std;

int main()
{
    int valueCnt = 0;
    int toStopValue = 0; 
    cin >> valueCnt >> toStopValue; 
    
    int total = 0; 
    for(int i = 0; i < valueCnt; i++)
    {
        int theValue = 0;
    cin >> theValue;
    
    if(theValue == toStopValue)
        break;
    
    total += theValue;   
    } 
    
    cout << total; 
    
    return 0;
}
