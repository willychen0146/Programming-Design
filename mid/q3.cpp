#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 150
using namespace std;

int maxProfit(int type_num, int extra_import, int* import_num, int* need_num, 
              int* import_cost, int* sell_price) {

    int max_money = 0;
    int temp = 0;
    int extra = 0;
    for (int i = 0; i < type_num; i++) {
        // Calculate profit without extra imports
        int current_profit = (sell_price[i] * min(import_num[i], need_num[i])) - (import_cost[i] * import_num[i]);
        
        // Calculate profit with extra imports
        for (int j = 1; j <= extra_import; j++) {
            int temp_profit = (sell_price[i] * min(import_num[i] + j, need_num[i])) - (import_cost[i] * (import_num[i] + j));
            temp = max(current_profit, temp_profit) - current_profit;
            if(temp > extra){
                extra = temp;
            }
        }
        // cout << current_profit << endl;
        max_money += current_profit;
    }
    max_money += extra; 

    return max_money;
}

int main() {
    int type_num, extra_import;
    cin >> type_num >> extra_import;
    int import_num[MAX] = {0};
    int need_num[MAX] = {0};
    int import_cost[MAX] = {0};
    int sell_price[MAX] = {0};    

    for (int i = 0; i < type_num; i++) {
        cin >> import_num[i] >> need_num[i] >> import_cost[i] >> sell_price[i];
    }

    int result = maxProfit(type_num, extra_import, import_num, need_num, import_cost, sell_price);
    cout << result << endl;

    return 0;
}
