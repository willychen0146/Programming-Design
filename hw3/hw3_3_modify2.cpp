#include <iostream>
#define MAX_NUM 100
using namespace std;

void greedyKnapsack(int item_num, int capacity, int weight[], int value[], int result[], int &sum_value) {
    int current_weight = 0; 
    int count = 0;
    sum_value = 0;
    int is_choosed[MAX_NUM] = {0};
    
    while(1){
        int max_value = 0;
        bool flag = false;

        for(int i = 0; i < item_num; i++){
            if(value[i] > max_value && (current_weight + weight[i]) <= capacity && is_choosed[i] == 0){
                flag = true;
                max_value = value[i];
                result[count] = i + 1;
            }
        }
        
        if(!flag){
            break;
        }
        
        is_choosed[result[count] - 1] = 1;
        current_weight += weight[result[count] - 1];
        sum_value += value[result[count] - 1];
        count++;
    }
}

int main(){
    int item_num, capacity;
    cin >> item_num >> capacity;

    int weight[MAX_NUM] = {0};
    int value[MAX_NUM] = {0};
    int result[MAX_NUM] = {0};
    int sum_value;

    for(int i = 0; i < item_num; i++)
        cin >> weight[i];
    for(int i = 0; i < item_num; i++)
        cin >> value[i];

    greedyKnapsack(item_num, capacity, weight, value, result, sum_value);

    for(int i = 0; i < item_num; i++){
        if(result[i] != 0){
            if(i == item_num - 1){
                cout << result[i];
            }
            else{
                cout << result[i] << ",";
            }
        }
    }
    cout << ";" << sum_value << endl;

    return 0;
}
