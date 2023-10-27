#include <iostream>
#include <algorithm>
using namespace std;

int main () {
  int x_len, y_len, radius, num_station, num_rail;
  cin >> x_len >> y_len >> radius >> num_station >> num_rail;
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

  int** has_calculate2 = nullptr;
  has_calculate2 = new int*[x];
  for (int i = 0; i < x; i++) {
    has_calculate2[i] = new int[y];
    for (int j = 0; j < y; j++) {
      has_calculate2[i][j] = 0;
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


//   // calculate 2
//   int radius_result = 0;

//   int radius_cenx = -1;
//   int radius_ceny = -1;
//   int radius_0x = -1;
//   int radius_0y = -1;
//   int radius_1x = -1;
//   int radius_1y = -1;
//   int radius_2x = -1;
//   int radius_2y = -1;
//   int radius_3x = -1;
//   int radius_3y = -1;
//   int radius_4x = -1;
//   int radius_4y = -1;
//   int radius_5x = -1;
//   int radius_5y = -1;
//   int radius_6x = -1;
//   int radius_6y = -1;
//   int radius_7x = -1;
//   int radius_7y = -1;
// //   cout << num_rail << endl;

//     for (int i = 0; i < num_station; i++) {
//       radius_cenx = rail_map[i][0];
//       radius_ceny = rail_map[i][1];
//       if(has_calculate2[radius_cenx][radius_ceny] == 0){
//         radius_result += people_map[radius_cenx][radius_ceny];
//         has_calculate2[radius_cenx][radius_ceny] = 1;        
//       }
//     }

//     for (int i = 0; i < num_rail; i++) {
//       radius_cenx = connect[i][0];
//       radius_ceny = connect[i][1];

//       if(radius_cenx - 1 >= 0 && radius_ceny - 1 >= 0){
//         radius_0x = radius_cenx - 1;
//         radius_0y = radius_ceny - 1;
//       }
//       if(radius_0x >= 0 && radius_0y >= 0 && has_calculate2[radius_0x][radius_0y] == 0){
//         radius_result += people_map[radius_0x][radius_0y];
//         has_calculate2[radius_0x][radius_0y] = 1;        
//       }

//       if(radius_ceny - 1 >= 0){
//         radius_1x = radius_cenx;
//         radius_1y = radius_ceny - 1;
//       }
//       if(radius_1x >= 0 && radius_1y >= 0 && has_calculate2[radius_1x][radius_1y] == 0){
//         radius_result += people_map[radius_1x][radius_1y];
//         has_calculate2[radius_1x][radius_1y] = 1;        
//       }

//       if(radius_cenx + 1 < x && radius_ceny - 1 >= 0){
//         radius_2x = radius_cenx + 1;
//         radius_2y = radius_ceny - 1;
//       }
//       if(radius_2x >= 0 && radius_2y >= 0 && has_calculate2[radius_2x][radius_2y] == 0){
//         radius_result += people_map[radius_2x][radius_2y];
//         has_calculate2[radius_2x][radius_2y] = 1;        
//       }

//       if(radius_cenx - 1 >= 0){
//         radius_3x = radius_cenx - 1;
//         radius_3y = radius_ceny;
//       }
//       if(radius_3x >= 0 && radius_3y >= 0 && has_calculate2[radius_3x][radius_3y] == 0){
//         radius_result += people_map[radius_3x][radius_3y];
//         has_calculate2[radius_3x][radius_3y] = 1;        
//       }

//       if(radius_cenx + 1 < x){
//         radius_4x = radius_cenx + 1;
//         radius_4y = radius_ceny;
//       }
//       if(radius_4x >= 0 && radius_4y >= 0 && has_calculate2[radius_4x][radius_4y] == 0){
//         radius_result += people_map[radius_4x][radius_4y];
//         has_calculate2[radius_4x][radius_4y] = 1;        
//       }

//       if(radius_cenx - 1 >= 0 && radius_ceny + 1 < y){
//         radius_5x = radius_cenx - 1;
//         radius_5y = radius_ceny + 1;
//       }
//       if(radius_5x >= 0 && radius_5y >= 0 && has_calculate2[radius_5x][radius_5y] == 0){
//         radius_result += people_map[radius_5x][radius_5y];
//         has_calculate2[radius_5x][radius_5y] = 1;        
//       }

//       if(radius_ceny + 1 < y){
//         radius_6x = radius_cenx;
//         radius_6y = radius_ceny + 1;
//       }
//       if(radius_6x >= 0 && radius_6y >= 0 && has_calculate2[radius_6x][radius_6y] == 0){
//         radius_result += people_map[radius_6x][radius_6y];
//         has_calculate2[radius_6x][radius_6y] = 1;        
//       }

//       if(radius_cenx + 1 < x && radius_ceny + 1 < y){
//         radius_7y = radius_cenx + 1;
//         radius_7y = radius_ceny + 1;
//       }
//       if(radius_7x >= 0 && radius_7y >= 0 && has_calculate2[radius_7x][radius_7y] == 0){
//         radius_result += people_map[radius_7x][radius_7y];
//         has_calculate2[radius_7x][radius_7y] = 1;        
//       }
//     }

// calculate result 2
int result2 = 0;

for (int i = 0; i < num_station; i++) {
  int station_x = rail_map[i][0];
  int station_y = rail_map[i][1];

  if (radius == 0) {
    // If radius is zero, only add the station spot to result2
    if (has_calculate2[station_x][station_y] == 0) {
      result2 += people_map[station_x][station_y];
    //   cout << result2 << endl;
      has_calculate2[station_x][station_y] = 1;
    }
  } else {
    // Calculate result2 within the specified radius
    for (int j = max(0, station_x - radius); j <= min(x - 1, station_x + radius); j++) {
      for (int k = max(0, station_y - radius); k <= min(y - 1, station_y + radius); k++) {
        // Check if the spot is within the radius and has not been calculated yet
        if (has_calculate2[j][k] == 0) {
          result2 += people_map[j][k];
          has_calculate2[j][k] = 1;
        }
      }
    }
  }
}

// end of calculating result2

  cout << result2 << "," << result << endl;  
  return 0;
}
