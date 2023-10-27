#include <iostream>
#define MAX_N 30
#define ELEMENT 4
using namespace std;

int earned_money(int object_array[][ELEMENT], int);

int main(){
    int type_num, threshold, result, temp;
    cin >> type_num >> threshold;
    // int import_num, wanted_buy, import_money, sell_money;
    int object_array[MAX_N][ELEMENT] = {{0}};
    for(int i = 0; i < type_num; i++){
        for(int j = 0; j < ELEMENT; j++){
            cin >> temp;
            object_array[i][j] = temp;
        }
    }
    result = earned_money(object_array, type_num);

    if(result >= threshold)
        cout << result << ",great" << endl;
    else
        cout << result << ",sad" << endl;
    return 0;
}

int earned_money(int object_array[][ELEMENT], int type_num){
    int earned = 0, min = 0;
    for(int i = 0; i < type_num; i++){
        if(object_array[i][0] >= object_array[i][1]){
            min = object_array[i][1];
        }
        else{
            min = object_array[i][0];
        }
        earned += (object_array[i][3]*min) - (object_array[i][0]*object_array[i][2]);
        // cout << earned <<endl;
    }

    return earned;
}