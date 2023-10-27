#include <iostream>
using namespace std;

int min(int a, int b)
{
    return (a < b ? a : b);
}

int main()
{
    int itemCnt = 0, threshold = 0;
    cin >> itemCnt >> threshold;
    
    int profit = 0;
    for(int i = 0; i < itemCnt; i++)
    {
        int buy = 0, sell = 0, cost = 0, price = 0;
        cin >> buy >> sell >> cost >> price;
    
        profit += price * min(buy, sell) - cost * buy;
    }
    cout << profit << (profit >= threshold ? ",great" : ",sad");
    
    // the ternary if opeartor ? : is equivalent to
    /*
    if(profit >= threshold)
        cout << profit << ",great";
    else
        cout << profit << ",sad";
    */
    
    return 0;
}

