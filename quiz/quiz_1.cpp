#include <iostream>
using namespace std;

int earned_money(int, int, int, int);

int main(){
    int import_num, import_money, sell_money, wanted_buy, result;
    cin >> import_num >> wanted_buy >> import_money >> sell_money;
    result = earned_money(import_num, wanted_buy, import_money, sell_money);
    cout << result << endl;
    return 0;
}

int earned_money(int import_num, int wanted_buy, int import_money, int sell_money){
    int earned = 0, min = 0;
    if(import_num >= wanted_buy){
        min = wanted_buy;
    }
    else{
        min = import_num;
    }

    earned = (sell_money*min) - (import_money*import_num);
    return earned;
}