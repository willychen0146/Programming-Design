#include <iostream>
#define MAX_NUM 1000
#define MAX_ITEM 10001
using namespace std;

int identical(int, int, int); // 111
int up_or_down(int num, int* array); // 111
int plus_or_what(int x, int y); // 110
void last_money(int, int, int*, int*, int*); // 110
int identical_109(int, int, int); // 109
int find_min(int*, int); // 109
void identical_108(int, int, int, int&, int&); // 108
void insertionSort(int*, int); //108

// int main(){
//     int x, y, z, result = 0;
//     cin >> x >> y >> z;
//     result = identical(x, y, z);
//     cout << result << endl;
//     return 0;
// }

// int main(){
//     int num, temp;
//     int array[MAX_NUM] = {0};
//     cin >> num;
//     for(int i = 0; i < num; i++){
//         cin >> temp;
//         array[i] = temp;
//     }
//     temp = up_or_down(num, array);
//     cout << temp << endl;
// }

// int main(){
//     int x, y, result;
//     cin >> x >> y;
//     result = plus_or_what(x, y);
//     cout << result << endl;
//     return 0;
// }

// int main(){
//     int num_item, money, temp, result_money;
//     cin >> num_item >> money;
//     int how_much_list[MAX_ITEM] = {0};
//     int wanted_list[MAX_ITEM] = {0};
//     int result[MAX_ITEM] = {0};
//     for(int i = 0; i < num_item; i++){
//         cin >> temp;
//         how_much_list[i] = temp;
//     }
//     for(int i = 0; i < num_item; i++){
//         cin >> temp;
//         wanted_list[i] = temp;
//     }
//     for(int i = 0; i < num_item; i++){
//         result[i] = 0;
//         // cout << wanted_list[i] << endl;
//     }
//     last_money(num_item, money, how_much_list, wanted_list, result);

//     for(int i = 0; i < num_item; i++){
//         if(i == num_item - 1)
//             cout << result[i];
//         else
//             cout << result[i] << ",";
//     }
//     cout << endl;
//     return 0;
// }

// int main(){
//     int x, y, z, result = 0;
//     cin >> x >> y >> z;
//     result = identical_109(x, y, z);
//     cout << result << endl;
//     return 0;
// }

// int main(){
//     int dim_1, dim_2, temp, result = 0;
//     cin >> dim_1 >> dim_2;
//     int vector_1[MAX_NUM] = {0};
//     int vector_2[MAX_NUM] = {0};
//     for(int i = 0; i < dim_1; i++){
//         cin >> temp;
//         vector_1[i] = temp;
//     }
//     for(int i = 0; i < dim_2; i++){
//         cin >> temp;
//         vector_2[i] = temp;
//     }

//     if(dim_1 > dim_2){
//         result = find_min(vector_2, dim_2);
//     }
//     else if(dim_2 > dim_1){
//         result = find_min(vector_1, dim_1);
//     }
//     else{
//         for(int i = 0; i < dim_2; i++){
//             result += vector_1[i] * vector_2[i];
//         }
//     }
//     cout << result << endl;
//     return 0;
// }

// int main(){
//     int x, y, z, result = 0, result_2 = 0;
//     cin >> x >> y >> z;
//     identical_108(x, y, z, result, result_2);
//     cout << result << " " << result_2 << endl;
//     return 0;
// }

int main(){
    int n, k, temp, result = 0;
    cin >> n >> k;
    int array[MAX_NUM] = {0};
    for(int i = 0; i < n; i++){
        cin >> temp;
        array[i] = temp;
    }
    insertionSort(array, n);
    if(n >= k)
        result = array[n-k];
    if(n < k)
        result = -1;
    cout << result << endl;
    return 0;
}

int identical(int x, int y, int z){
    int result = 0;
    if(x == y && y == z){
        result = 1;
    }
    else if(x != y && y != z && x != z){
        result = 2;
    }
    else if(x == y && y != z || x == z && y != z || y == z && x != z){
        result = 3;
    }
    else{
        result = 0;
    }
    return result;
}

int up_or_down(int num, int* array){
    int result;
    int flag[MAX_NUM] = {0};
    int flag_sum = 0;
    int flag_degrade = 0;
    int turn_point = 0;
    for(int i = 0; i < num - 1; i++){
        if(array[i + 1] > array[i]){
            flag[i] = 1;
            flag_sum++;
        }
        else if(array[i + 1] < array[i]){
            flag[i] = -1;
            flag_degrade++;
        }
        // cout << flag[i] << " ";
    }

    for(int i = 0; i < num - 2; i++){
        if(flag[i] > 0 && flag[i + 1] < 0 || flag[i] < 0 && flag[i + 1] > 0){
            turn_point++;
        }
    }

    if(turn_point == 0){
        if(flag_sum > 0 && flag_degrade == 0){
            result = 1;
        }
        else if(flag_degrade > 0 && flag_sum == 0){
            result = 2;
        }
    }
    else if(turn_point == 1){
        if(flag[0] >= 0){
            result = 3;
        }
        else{
            result = 4;
        }
    }
    else{
        result = 4;
    }
    // cout << turn_point<< endl;

    return result;
}

int plus_or_what(int x, int y){
    int result = 0;
    if(x == y){
        if(x < 0 && y < 0)
            result = x * y;
        if(x >= 0 && y >= 0)
            result = x + y;
    }
    else{
        result = x - y;
    }
    return result;
}

void last_money(int num_item, int money, int* how_much_list, int* wanted_list, int* result){
    for(int i = 0; i < num_item; i++){
        if((money - how_much_list[i]) >= 0 && wanted_list[i] == 1){
            money -= how_much_list[i];
            result[i] = money;
        }
        else if(how_much_list[i] <= (money / 2) && wanted_list[i] == 0){
            money -= how_much_list[i];
            result[i] = money;
        }
        else{
            result[i] = money;
        }
    }
}

int identical_109(int x, int y, int z){
    int result = 0;
    if(x == y && y == z){
        result = 1;
    }
    else if(x != y && y != z && x != z){
        result = 3;
    }
    else if(x == y && y != z || x == z && y != z || y == z && x != z){
        result = 2;
    }
    else{
        result = 0;
    }
    return result;
}

int find_min(int* array, int len){
    int min = 0;
    min = array[0];
    for(int i = 1; i < len; i++){
        if(array[i] < min)
            min = array[i];
    }
    return min;
}

void identical_108(int x, int y, int z, int& result, int& result_2){
    if(x == y && y == z){
        result = 1;
        result_2 = x;
    }
    else if(x != y && y != z && x != z){
        result = 3;
        result_2 = x + y + z;
    }
    else if(x == y && y != z || x == z && y != z || y == z && x != z){
        result = 2;
        if(x == y){
            result_2 = x;
        }
        else{
            result_2 = z;
        }
    }
    else{
        result = 0;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}
