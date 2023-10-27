#include <iostream>
using namespace std;

int main()
{
    int itemCnt = 0, capacity = 0;
    cin >> itemCnt >> capacity;
    
    const int MAX_ITEM_CNT = 100;
    int weight[MAX_ITEM_CNT] = {0};
    int value[MAX_ITEM_CNT] = {0};
    bool bring[MAX_ITEM_CNT] = {0};

/*
    int* weight = new int[n];
    for(int i = 0; i < n; i++)
        weight[i] = 0;
    int* value = new int[n];
    for(int i = 0; i < n; i++)
        value[i] = 0;
    bool* bring = new bool[n];
    for(int i = 0; i < n; i++)
        bring[i] = 0;
*/

    for(int i = 0; i < itemCnt; i++)
        cin >> weight[i];
    for(int i = 0; i < itemCnt; i++)
        cin >> value[i];
    for(int i = 0; i < itemCnt; i++)
        cin >> bring[i];
        
    int totalWeight = 0;
    for(int i = 0; i < itemCnt; i++)
    {
        if(bring[i] == true)
            totalWeight += weight[i];
    }
    if(totalWeight > capacity)
        cout << 0;
    else
    {
        int totalValue = 0;
        for(int i = 0; i < itemCnt; i++)
        {
            if(bring[i] == true)
                totalValue += value[i]; 
        }
        cout << totalWeight << "," << totalValue;
    }
    
    return 0;
}
