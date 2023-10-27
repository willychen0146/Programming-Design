#include <iostream>
using namespace std;

int min(int a, int b)
{
    return (a < b ? a : b);
}

int main()
{
    int buy = 0, sell = 0, cost = 0, price = 0;
    cin >> buy >> sell >> cost >> price;
    
    int profit = price * min(buy, sell) - cost * buy;
    cout << profit;
    
    return 0;
}

