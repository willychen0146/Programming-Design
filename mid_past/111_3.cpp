#include <iostream>
using namespace std;

int find_overlap(int, int** time_array, int** num_array);
void time_to_num(int, int** time_array, int** num_array);

int main(){
  // get input
  int total_num, overlap = 0;
  cin >> total_num;
  int** time_array = nullptr;
  time_array = new int*[total_num];
  for (int i = 0; i < total_num; i++) {
    time_array[i] = new int[4];
      for(int j = 0; j < 4; j++){
        cin >> time_array[i][j];
      }
  }
  int** num_array = nullptr;
  num_array = new int*[total_num];
  for (int i = 0; i < total_num; i++) {
    num_array[i] = new int[2];
      for(int j = 0; j < 2; j++){
        num_array[i][j] = 0;
      }
  }

  time_to_num(total_num, time_array, num_array);
  overlap = find_overlap(total_num, time_array, num_array);
  cout << overlap << endl;
  return 0;
}

int find_overlap(int total_num, int** time_array, int** num_array){
  int overlap = 0, loop = 0;
  for (int i = 0; i < total_num-1; i++) {
    for(int j = i+1; j < total_num; j++){
      //  if(num_array[i][0] < num_array[j][0] && num_array[i][1] > num_array[j][0] || 
      //     num_array[i][0] < num_array[j][1] && num_array[i][1] > num_array[j][1]){
       if (num_array[i][0] < num_array[j][1] && num_array[i][1] > num_array[j][0]){
        //  cout << i << " " << j << endl;
         overlap++;
       }
    }
  }
  return overlap;
}

void time_to_num(int total_num, int** time_array, int** num_array){
  for (int i = 0; i < total_num; i++) {
    num_array[i][0] = time_array[i][0]*60 + time_array[i][1];
    num_array[i][1] = time_array[i][2]*60 + time_array[i][3];
    // cout << num_array[i][0] << " " << num_array[i][1] <<endl;
  }
}
