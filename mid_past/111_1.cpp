#include <iostream>
using namespace std;

int sec_neg_pos(int, int*);

int main(){
  // get input
  int total_num, position = 0;
  cin >> total_num;
  int* num_array = nullptr;
  num_array = new int[total_num];
  for(int i = 0; i < total_num; i++){
    cin >> num_array[i];
  }
  
  position = sec_neg_pos(total_num, num_array);
  cout << position << endl;
  return 0;
}

int sec_neg_pos(int total_num, int* num_array){
  int position = 0, count = 0;
  for (int i = 0; i < total_num; i++) {
    if(num_array[i] < 0){
      position = i + 1;
      count++;
      if(count == 2){
        break;
      }
    }
  }

  return position;
}
