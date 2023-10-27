#include <iostream>
#define MAX_NUM 100
using namespace std;

int main(){
    int item_num, capacity, max_value, current_weight, drop_count, current_value_id, sum_value, current_value; // Initiate the parameter
    bool flag_1;
    bool flag_2;
    cin >> item_num >> capacity; // total_item_num, bag_capacity
    
    // Initiate array
    int weight[MAX_NUM] = {0};
    int value[MAX_NUM] = {0};
    int is_choosed[MAX_NUM] = {0};

    for(int i = 0; i < item_num; i++)
        cin >> weight[i];
    for(int i = 0; i < item_num; i++)
        cin >> value[i];
    
    // Setting current weight to max
    current_weight = 0;
    for(int i = 0; i < item_num; i++){
        current_weight += weight[i];
    }

    // Setting sum of value to max
    sum_value = 0;
    for(int i = 0; i < item_num; i++){
        sum_value += value[i];
    }

    // Remove slowly algorithm (kind of greedy algorithm)
    drop_count = 0; // Count the drop
    current_value_id = 0; // Id we found
    while(1){
        current_value = sum_value; // Setting current value to be max first
        flag_1 = false; // if enter loop 1 --> true
        flag_2 = false; // if enter loop 2 --> true

        // loop 1 for searching condition 1 (if true skip loop 2)
        // If drop only one thing can let the current_weight <= capacity --> drop
        for(int i = 0; i < item_num; i++){
            if(is_choosed[i] == 0 && current_weight > capacity && (current_weight - weight[i]) <= capacity){ 
                flag_1 = true;

                if(current_value - value[i] == 0 && item_num == (drop_count + 1))
                    current_value_id = i;
                if(value[i] < current_value){
                    current_value = value[i];
                    current_value_id = i;
                }
            }
        }        

        // loop 2 for searching condition 2 (if not enter loop 1)
        // Found the lowest value thing and drop it
        for(int i = 0; i < item_num; i++){
            if(is_choosed[i] == 0 && current_weight > capacity && value[i] < current_value){ 
                if(flag_1 == false){
                    flag_2 = true;
                    current_value = value[i];
                    current_value_id = i;
                }
                
            }
        }
        // If not enter both for loop --> break
        if(!flag_1 && !flag_2){
            break;
        }

        // Start drop the searching result and update parameter
        is_choosed[current_value_id] = 1;
        current_weight -= weight[current_value_id];
        sum_value -= value[current_value_id];
        drop_count++;
    } 

    // Output the selected item numbers
    for (int i = 0, count = 0; i < item_num; i++) {
        if (is_choosed[i] == 1) {
            continue; // Skip dropped items
        }

        cout << i + 1; // Output item number (index start from 0)

        if (count < (item_num - drop_count) - 1) {
            cout << ",";
        }
        count++;
    }
    // Don't that the output sum_value < 0
    if(sum_value >= 0){
        cout << ";" << sum_value << endl;
    }
    else{
        cout << ";" << 0 << endl;
    }
    return 0;
}
