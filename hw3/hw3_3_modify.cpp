#include <iostream>
#define MAX_NUM 100
using namespace std;

// 函數原型
int findNextItem(int item_num, int capacity, int current_weight, int* weight, int* value, int* is_choosed);

int main() {
    int item_num, capacity;
    cin >> item_num >> capacity;

    int weight[MAX_NUM] = {0};
    int value[MAX_NUM] = {0};
    int is_choosed[MAX_NUM] = {0};
    int result[MAX_NUM] = {0};

    for(int i = 0; i < item_num; i++)
        cin >> weight[i];
    for(int i = 0; i < item_num; i++)
        cin >> value[i];

    int current_weight = 0;
    int count = 0;
    int sum_value = 0;

    // 使用函數來執行Greedy算法
    while (true) {
        int nextItem = findNextItem(item_num, capacity, current_weight, weight, value, is_choosed);
        
        if (nextItem == -1) {
            break;
        }
        
        is_choosed[nextItem] = 1;
        current_weight += weight[nextItem];
        result[count++] = nextItem + 1;
        sum_value += value[nextItem];
    }

    for(int i = 0; i < count; i++) {
        if(i == count - 1) {
            cout << result[i];
        } else {
            cout << result[i] << ",";
        }
    }
    cout << ";" << sum_value << endl;

    return 0;
}

// 函數定義：找到下一個要放入背包的物品
int findNextItem(int item_num, int capacity, int current_weight, int* weight, int* value, int* is_choosed) {
    int max_value = 0;
    int max_value_id = -1;
    bool flag = false;

    for (int i = 0; i < item_num; i++) {
        if (value[i] > max_value && (current_weight + weight[i]) <= capacity && is_choosed[i] == 0) {
            flag = true;
            max_value = value[i];
            max_value_id = i;
        }
    }

    if (!flag) {
        return -1; // 沒有可選擇的物品了
    }

    return max_value_id;
}
