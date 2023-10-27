#include <iostream>
using namespace std;
const int MAX_ITEM_CNT = 100;

// This is the prototype of the function that you should complete
void knapsack(int itemCnt, int capacity, const int weight[], const int value[], const int sol[], int ret[]);
void bubble_sort(int array[], int n);

int main()
{
    int itemCnt = 0, capacity = 0, num_sol = 0, ind_item_count = 0, true_count = 0, max_value = 0; // initiate true solution
    cin >> itemCnt >> capacity >> num_sol; // total_item_num, capacity, num_sol
    
    int weight[MAX_ITEM_CNT] = {0};
    int value[MAX_ITEM_CNT] = {0};
    int sol[MAX_ITEM_CNT] = {0};
    int ret[2] = {0};

    for(int i = 0; i < itemCnt; i++)
        cin >> weight[i];
    for(int i = 0; i < itemCnt; i++)
        cin >> value[i];
    
    for(int i = 0; i < num_sol; i++){
        cin >> ind_item_count;
        for(int j = 0; j < ind_item_count; j++)
            cin >> sol[j];
            //for(int l = 0; l < ind_item_count; l++)
            //    cout << sol[l] << " ";
            bubble_sort(sol, ind_item_count);
            //for(int k = 0; k < ind_item_count; k++)
            //    cout << sol[k] << " ";
            knapsack(ind_item_count, capacity, weight, value, sol, ret);
            //cout << ret[0] << "\n";
            //cout << ret[1] << "\n";
            if(ret[0] == -1){
                true_count += 0;
            }
            else
                true_count += 1;
                if(ret[1] > max_value){
                    max_value = ret[1];
                }
    }

    cout << true_count << "," << max_value;
    
    return 0;
}

// PDOGS will copy and paste your codes here before compilation
// int ind_item_count, int capacity, const int weight[], const int value[], const int sol[], int ret[]
void knapsack(int total_item_num, int capacity, const int item_weight[], const int item_value[], const int sol[], int ret[]){
    int temp_id = 0, temp_weight = 0, temp_value = 0;  
    for(int i = 0; i < total_item_num; i++){
        temp_id = sol[i];
        //cout << temp_id << "\n";       
        temp_weight += item_weight[temp_id - 1];
        temp_value += item_value[temp_id - 1];
    }
    
    if(temp_weight <= capacity){
        ret[0] = temp_weight;
        ret[1] = temp_value;
    }
    else{
        ret[0] = -1;
    }
}

void bubble_sort(int array[], int n) {
    int temp;
    int swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = 0; 
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // switch array[j] and array[j+1]
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1; // switch happen
            }
        }

        // if switch not happen, the sorting is complete
        if (swapped == 0) {
            break;
        }
    }
}