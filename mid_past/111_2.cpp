#include <iostream>
using namespace std;

int find_chosen_pos(int, int*, int);

int main(){
  // get input
  int total_num, chosen = 0, position = 0;
  cin >> total_num >> chosen;
  int* num_array = nullptr;
  num_array = new int[total_num];
  for(int i = 0; i < total_num; i++){
    cin >> num_array[i];
  }
  
  position = find_chosen_pos(total_num, num_array, chosen);
  if(position == -1)
    cout << 0;
  else
    cout << position + 1 << "," << num_array[position] << endl;
  return 0;
}

int find_chosen_pos(int total_num, int* num_array, int chosen){
  int position = -1, count = 0, loop_count = 0;
  for (int i = 0; i < total_num; i++) {
    if(num_array[i] < 0){
      position = i;
      count++;
      // if(loop_count == total_num && count != chosen){

      // }
      if(count == chosen){
        break;
      }
    }
    // loop_count++;
  }
  // cout << position << endl;
  if(position == -1)
    return -1;
  else
    return position;
}
