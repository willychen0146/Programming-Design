#include <iostream>
#define MAX_NUM 100
using namespace std;

int main(){
    int item_num, capacity, max_value, current_weight, count, max_value_id, sum_value; // Initiate the parameter
    bool flag;
    cin >> item_num >> capacity; // total_item_num, bag_capacity
    
    // Initiate array
    int weight[MAX_NUM] = {0};
    int value[MAX_NUM] = {0};
    int is_choosed[MAX_NUM] = {0};
    int result[MAX_NUM] = {0};

    for(int i = 0; i < item_num; i++)
        cin >> weight[i];
    for(int i = 0; i < item_num; i++)
        cin >> value[i];
    
    // Greedy algorithm
    current_weight = 0; // Set the current_weight to 0 first
    count = 0; // Loop count
    sum_value = 0; // set the sum_value to 0 first
    while(1){
        max_value = 0; // Set the max_value = 0 first, ensure the for loop run correctly for the first time
        flag = false; // If enter the for loop and find the item, flag = true
        // Find the item if the condition is correct
        for(int i = 0; i < item_num; i++){
            if(value[i] > max_value && (current_weight + weight[i]) <= capacity && is_choosed[i] == 0){
                flag = true;
                max_value = value[i];
                max_value_id = i;
            }
        }
        // If not enter the for loop --> break
        if(!flag){
            break;
        }
        // Process the finding result
        is_choosed[max_value_id] = 1;
        current_weight += weight[max_value_id];
        result[count++] = max_value_id + 1;
        sum_value += value[max_value_id];
    }

    // Output the result
    for(int i = 0; i < count; i++){
        if(i == count - 1){
            cout << result[i];
        }
        else{
            cout << result[i] << ",";
        }
    }
    cout << ";" << sum_value << endl;
    
    return 0;
}
