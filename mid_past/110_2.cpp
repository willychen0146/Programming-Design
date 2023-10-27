#include <iostream>
using namespace std;

void find_final(int, int, int*, int*, int [][2]);

int main () {
  int num_station, needed;
  cin >> num_station >> needed;
  int max_car[30] = {0};
  int org_car[30] = {0};
  int record[30] = {0};
  int need_list[150][2] = {0};
  for (int i = 0; i < num_station; i++) {
    cin >> max_car[i];
  }
  for (int i = 0; i < num_station; i++) {
    cin >> org_car[i];
    // cout << org_car[i] << " ";
  }
  // for (int i = 0; i < num_station; i++) {
  //   record[i] = max_car[i] - org_car;
  // }
  for (int i = 0; i < needed; i++) {
    cin >> need_list[i][0] >> need_list[i][1];
  }

  int result[30] = {0};
  find_final(num_station, needed, org_car, max_car, need_list);
  for (int i = 0; i < num_station; i++) {
    if(i == num_station-1)
      cout << org_car[i];
    else 
      cout << org_car[i] << ",";
  }
  cout << endl;
  return 0;
}


  void find_final(int num_station, int needed, int* org_car, int* max_car, int need_list[][2]){
    int start = 0, end = 0;
    for (int i = 0; i < needed; i++) {
      start = need_list[i][0];
      end = need_list[i][1];
      // cout << start << " " <<end << endl;
      if(org_car[start-1] != 0 && org_car[end-1] < max_car[end-1]){
        org_car[start-1]--;
        org_car[end-1]++;
        for(int j = 0; j < num_station; j++){
          // cout << org_car[j] << " ";
        }
      }
      // cout << endl;
    }
  }
