#include <iostream>
#include <algorithm>
using namespace std;

int main () {
  int total_wood, total_time, ex_wood, low_wood, ex_time, low_time, ex_price, low_price;
  cin >> total_wood >> total_time >> ex_wood >> low_wood >> ex_time >> low_time >> ex_price >> low_price;
  
  // find best sell strategy
  int temp_ex, temp_low;
  int temp_wood, temp_time;
  temp_ex = min((total_wood / ex_wood), (total_time / ex_time));
  temp_wood = (total_wood - temp_ex*ex_wood);
  temp_time = (total_time - temp_ex*ex_time);
  temp_low = min((temp_wood / low_wood), (temp_time / low_time));

  int final_price = temp_ex*ex_price + temp_low*low_price;

//   while(temp_ex >= 0){
//     temp_ex--;
//     temp_low++;
//     int temp_price = temp_ex*ex_price + temp_low*low_price;
//     if(temp_price > final_price){
//       final_price = temp_price;
//     }
//     if(temp_ex == 0){
//       break;
//     }
//   }

// gpt
  while (temp_ex >= 0) {
    int temp_price = temp_ex * ex_price + temp_low * low_price;
    if (temp_price > final_price) {
      final_price = temp_price;
    }
    temp_ex--;
    temp_wood = (total_wood - temp_ex * ex_wood);
    temp_time = (total_time - temp_ex * ex_time);
    temp_low = min((temp_wood / low_wood), (temp_time / low_time));
  }

  cout << final_price << endl;
  return 0;
}
