#include <iostream>
using namespace std;
const int MAX_ITEM_CNT = 100;

// This is the prototype of the function that you should complete
void knapsack(int itemCnt, int capacity, const int weight[], const int value[], const bool bring[], int ret[]);

int main()
{
    int itemCnt = 0, capacity = 0;
    cin >> itemCnt >> capacity; // total_item_num, capacity
    
    int weight[MAX_ITEM_CNT] = {0};
    int value[MAX_ITEM_CNT] = {0};
    bool bring[MAX_ITEM_CNT] = {0};
    int ret[2] = {0};

    for(int i = 0; i < itemCnt; i++)
        cin >> weight[i];
    for(int i = 0; i < itemCnt; i++)
        cin >> value[i];
    for(int i = 0; i < itemCnt; i++)
        cin >> bring[i]; // 1 or 0
    
    knapsack(itemCnt, capacity, weight, value, bring, ret);
    
    if(ret[0] == -1)
        cout << -1;
    else
        cout << ret[0] << "," << ret[1];
    
    return 0;
}

// PDOGS will copy and paste your codes here before compilation
// int itemCnt, int capacity, const int weight[], const int value[], const bool bring[], int ret[]
void knapsack(int total_item_num, int capacity, const int item_weight[], const int item_value[], const bool bring[], int ret[]){
    int temp_weight = 0, temp_value = 0;  
    for(int i = 0; i < total_item_num; i++){
        temp_weight += bring[i] * item_weight[i];
        temp_value += bring[i] * item_value[i];
    }
    
    if(temp_weight <= capacity){
        ret[0] = temp_weight;
        ret[1] = temp_value;
    }
    else{
        ret[0] = -1;
    }
}