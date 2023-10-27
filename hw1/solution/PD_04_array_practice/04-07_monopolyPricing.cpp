#include <iostream>
using namespace std;

int main()
{
    int baseDemand = 0, sensitivity = 0, cost = 0;
    cin >> baseDemand >> sensitivity >> cost;
    
    int optPrice = 0;
    int optProfit = 0;
    
    for(int price = cost + 1; price <= baseDemand / sensitivity; price++)
    {
        int profit = (price - cost) * (baseDemand - sensitivity * price);
        
        if(profit > optProfit)
        {
            optPrice = price;
            optProfit = profit;
        }
    }
    
    cout << optPrice << "," << optProfit;
    
    return 0;
}
