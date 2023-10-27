#include <iostream>
#include <algorithm>
using namespace std;

int main () {
  int type_num, total_wood, total_time;
  cin >> type_num >> total_wood >> total_time;

  int* cos_wood_list = nullptr;
  cos_wood_list = new int[type_num];
  for(int i = 0; i < type_num; i++){
    cin >> cos_wood_list[i];
  }

  int* cos_time_list = nullptr;
  cos_time_list = new int[type_num];
  for(int i = 0; i < type_num; i++){
    cin >> cos_time_list[i];
  }

  int* price_list = nullptr;
  price_list = new int[type_num];
  for(int i = 0; i < type_num; i++){
    cin >> price_list[i];
  }

  // find best sell strategy
  // set id 0 to be the first choice (id 0 wood is most expensive)
  int first_choice, temp_choice, temp_wood, temp_time;
  int final_price = 0;
  first_choice = min((total_wood / cos_wood_list[0]), (total_time / cos_time_list[0]));
  temp_wood = (total_wood - first_choice * cos_wood_list[0]);
  temp_time = (total_time - first_choice * cos_time_list[0]);
  final_price += first_choice * price_list[0];

  for(int i = 1; i < type_num; i++){
    if(temp_wood > 0 && temp_time > 0){
      int temp_choice = min((temp_wood / cos_wood_list[i]), (temp_time / cos_time_list[i]));
      final_price += temp_choice * price_list[i];
      temp_wood = (temp_wood - temp_choice * cos_wood_list[i]);
      temp_time = (temp_time - temp_choice * cos_time_list[i]);
    }
    else{
      break;
    }
  }
//   cout << final_price << endl;

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
  first_choice = min((total_wood / cos_wood_list[0]), (total_time / cos_time_list[0]));
  while (first_choice >= 0) {
    // calculate temp price
    int temp_price = 0;
    temp_wood = (total_wood - first_choice * cos_wood_list[0]);
    temp_time = (total_time - first_choice * cos_time_list[0]);
    temp_price += first_choice * price_list[0];

    for(int i = 1; i < type_num; i++){
      if(temp_wood > 0 && temp_time > 0){
          int temp_choice = min((temp_wood / cos_wood_list[i]), (temp_time / cos_time_list[i]));
          temp_price += temp_choice * price_list[i];
          temp_wood = (temp_wood - temp_choice * cos_wood_list[i]);
          temp_time = (temp_time - temp_choice * cos_time_list[i]);
      }
      else{
        break;
      }
    }

    if (temp_price > final_price) {
      final_price = temp_price;
    }
    first_choice--;
  }
  cout << final_price << endl;
  return 0;
}
