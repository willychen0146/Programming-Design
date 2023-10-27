#include <iostream>
#include <algorithm>
using namespace std;

int main () {
  int x_len, y_len, num_station, num_rail;
  cin >> x_len >> y_len >> num_station >> num_rail;
  int x = x_len + 1;
  int y = y_len + 1;
//   cout << x << y <<endl;

  int** people_map = nullptr;
  people_map = new int*[x];
  for (int i = 0; i < x; i++) {
    people_map[i] = new int[y];
    for (int j = 0; j < y; j++) {
      cin >> people_map[i][j];
    }
  }

  int** has_calculate = nullptr;
  has_calculate = new int*[x];
  for (int i = 0; i < x; i++) {
    has_calculate[i] = new int[y];
    for (int j = 0; j < y; j++) {
      has_calculate[i][j] = 0;
    }
  }

  int** rail_map = nullptr;
  rail_map = new int*[num_station];
  for (int i = 0; i < num_station; i++) {
    rail_map[i] = new int[2];
    for (int j = 0; j < 2; j++) {
      cin >> rail_map[i][j];
    }
  }

  int** connect = nullptr;
  connect = new int*[num_rail];
  for (int i = 0; i < num_rail; i++) {
    connect[i] = new int[2];
    for (int j = 0; j < 2; j++) {
      cin >> connect[i][j];
    }
  }
 
  // calculate
  int result = 0;
  int choose_id = -1;
  int choose = -1;
  
  if(num_rail != 0){
    for (int i = 0; i < num_rail; i++) {
      int temp_con1 = connect[i][0];
      int temp_con2 = connect[i][1];
    //   cout << temp_con1 << " " << temp_con2 << endl;
      int choose1x = rail_map[temp_con1 - 1][0];
      int choose1y = rail_map[temp_con1 - 1][1];
      int choose2x = rail_map[temp_con2 - 1][0];
      int choose2y = rail_map[temp_con2 - 1][1];
    //   cout << choose1x << " " << choose1y << " " << choose2x << " " << choose2y << endl;
      if(choose1x == choose2x){
        choose_id = choose1x;
        choose = 0; // x
      }
      else{
        choose_id = choose1y;
        choose = 1; // y
      }
    //   cout << choose_id << " " << choose <<endl;
      for (int j = 0; j < x; j++) {
        for (int k = 0; k < y; k++) {
          if(choose == 0){ // x
        //   cout << "max" << max(choose1y, choose2y) << " " << "min" << min(choose1y, choose2y) << endl;
            if(j == choose_id && (k <= max(choose1y, choose2y)) && (k >= min(choose1y, choose2y)) && has_calculate[j][k] == 0){
              result += people_map[j][k];
              has_calculate[j][k] = 1;
            //   cout << result << endl;
            }
          }
          else{
            // cout << "max" << max(choose1y, choose2y) << " " << "min" << min(choose1y, choose2y) << endl;
            if(k == choose_id && (j <= max(choose1x, choose2x)) && (j >= min(choose1x, choose2x)) && has_calculate[j][k] == 0){ // y
              result += people_map[j][k];
              has_calculate[j][k] = 1;
            //   cout << result << endl;
            }
          }
        }
      }
    }
  }
  cout << result << endl;  
  return 0;
}
