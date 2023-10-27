#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
#include <chrono>
#endif

using namespace std;

float diff_score(vector<vector<int>> &list, int num_car_type, int num_stations,
              int *car_price_list, float **basic_driving_rate,
              float **decline_matrix, vector<float> &station_declines,
              int chosen_i, int chosen_j, float current_max_score) {
  // 本車
  float diff =
      24 * car_price_list[chosen_i] *
      (basic_driving_rate[chosen_i][chosen_j] - station_declines[chosen_j]) * 1;

  // 跟本車有關的車站造成的影響
  for (int j = 0; j < num_stations; j++) {
    float &decline = decline_matrix[chosen_j][j];
    if (decline == 0.0) {
      continue;
    }
    for (int i = 0; i < num_car_type; i++) {
      if (list[i][j] == 0) {
        continue;
      }
      // auto before = 24 * car_price_list[i] *
      //               (basic_driving_rate[i][j] - station_declines[j]) *
      //               list[i][j];
      // auto after = 24 * car_price_list[i] *
      //              (basic_driving_rate[i][j] - station_declines[j] -
      //               decline_matrix[chosen_j][j]) *
      //              list[i][j];
      // diff += after - before;
      diff -= 24 * car_price_list[i] * list[i][j] * decline;
      if (diff < 0 || diff < current_max_score) {
        return 0;
      }
    }
    // 更新decline
    station_declines[j] += decline;
  }

  return diff;
}

float score(vector<vector<int>> &list, int num_car_type, int num_stations,
            int *car_price_list, float **basic_driving_rate,
            float **decline_matrix) {

  int *tot_car_per_st = new int[num_stations]{};
  float *station_declines = new float[num_stations]{};

  for (int j = 0; j < num_stations; j++) {
    for (int i = 0; i < num_car_type; i++) {
      tot_car_per_st[j] += list[i][j];
    }
  }

  for (int j = 0; j < num_stations; j++) {
    for (int k = 0; k < num_stations; k++) {
      station_declines[j] += decline_matrix[j][k] * tot_car_per_st[k];
    }
    station_declines[j] -= decline_matrix[j][j];
  }

  float tot_score = 0.0;
  for (int i = 0; i < num_car_type; i++) {
    for (int j = 0; j < num_stations; j++) {
      tot_score += 24 * car_price_list[i] *
                   (basic_driving_rate[i][j] - station_declines[j]) *
                   list[i][j];
    }
  }

  delete[] tot_car_per_st;
  delete[] station_declines;

  return tot_score;
}

vector<vector<int>>
find_best_choice_greedy(int num_car_type, int num_stations, int *car_price_list,
                        float **basic_driving_rate, float **decline_matrix,
                        int *car_num_list, int *max_car_list) {

  vector<vector<int>> list(num_car_type, vector<int>(num_stations));
  vector<float> station_declines(num_stations);

  float tot_score = 0.0;
  int chosen_car;
  int chosen_station;
  vector<float> _station_declines;
  vector<float> __station_declines;

  bool found;
  float max_score;
  while (1) {
    found = false; // 是否下決策flag (allocate car on list[i][j])
    max_score = 0.0;
    for (int i = 0; i < num_car_type; i++) {
      // 確保車型數量足夠
      if (car_num_list[i] > 0) {
        for (int j = 0; j < num_stations; j++) {
          // 確保場站車位足夠
          if (max_car_list[j] > 0) {
            _station_declines = station_declines;
            float s = diff_score(list, num_car_type, num_stations, car_price_list,
                              basic_driving_rate, decline_matrix,
                              station_declines, i, j, max_score);

            if (s > max_score) {
              max_score = s;
              chosen_car = i;
              chosen_station = j;
              found = true;
              __station_declines = station_declines;
            }
            station_declines = _station_declines;
          }
        }
      }
    }

    if (found) {
      list[chosen_car][chosen_station] += 1;
      max_car_list[chosen_station] -= 1;
      car_num_list[chosen_car] -= 1;
      station_declines = __station_declines;

      tot_score += max_score;
    } else {
      break;
    }
  }
#ifdef ENABLE_DEBUG
  cout << "tot: " << tot_score << endl;
  cout << "tru: "
       << score(list, num_car_type, num_stations, car_price_list,
                basic_driving_rate, decline_matrix)
       << endl;
  // vector<vector<int>> l = {{5, 2, 3}, {1, 2, 2}};
  // 範例
  vector<vector<int>> l = {{5, 3, 1}, {1, 3, 1}};
  cout << score(l, num_car_type, num_stations, car_price_list,
                basic_driving_rate, decline_matrix)
       << endl;
#endif

  return list;
}

int main() {
#ifdef ENABLE_DEBUG
  // Start the timer
  auto start = chrono::high_resolution_clock::now();
#endif

  int temp = 0;
  float temp_f = 0.0;

  // 車型種類數量
  int num_car_type;
  // 場站數量
  int num_stations;
  float decline_degree0, decline_degree1, decline_degree2, decline_degree3;
  cin >> num_car_type;
  cin >> num_stations;
  cin >> decline_degree0 >> decline_degree1 >> decline_degree2 >>
      decline_degree3;

  // 各車型費用
  int *car_price_list = nullptr;
  car_price_list = new int[num_car_type];
  for (int i = 0; i < num_car_type; i++) {
    cin >> car_price_list[i];
  }

  // 各車型總數
  int *car_num_list = nullptr;
  car_num_list = new int[num_car_type];
  for (int i = 0; i < num_car_type; i++) {
    cin >> car_num_list[i];
  }

  // 各場站車格上限
  int *max_car_list = nullptr;
  max_car_list = new int[num_stations];
  for (int i = 0; i < num_stations; i++) {
    cin >> max_car_list[i];
  }

  // 各車型於各場站的預期稼動率
  float **basic_driving_rate = nullptr;
  basic_driving_rate = new float *[num_car_type];
  for (int i = 0; i < num_car_type; i++) {
    basic_driving_rate[i] = new float[num_stations];
    for (int j = 0; j < num_stations; j++) {
      cin >> basic_driving_rate[i][j];
    }
  }

  // (Units = meters)
  // 場站間距離
  int **station_distance = nullptr;
  station_distance = new int *[num_stations];
  for (int i = 0; i < num_stations; i++) {
    station_distance[i] = new int[num_stations];
    for (int j = 0; j < num_stations; j++) {
      cin >> station_distance[i][j];
    }
  }

  // turn distance into decline_matrix
  float **decline_matrix = nullptr;
  decline_matrix = new float *[num_stations];
  for (int i = 0; i < num_stations; i++) {
    decline_matrix[i] = new float[num_stations];
    for (int j = 0; j < num_stations; j++) {

      auto d = station_distance[i][j];
      if (d < 1) {
        decline_matrix[i][j] = decline_degree0;
      } else if (d >= 1 && d < 301) {
        decline_matrix[i][j] = decline_degree1;
      } else if (d >= 301 && d < 501) {
        decline_matrix[i][j] = decline_degree2;
      } else if (d >= 501 && d < 1001) {
        decline_matrix[i][j] = decline_degree3;
      } else {
        decline_matrix[i][j] = 0.0;
      }
    }
  }

  vector<vector<int>> result;

  // if (num_stations < 200) {
  if (0) {
    // if (1) {
    // result = find_best_choice_greedy_slow(
    //     num_car_type, num_stations, car_price_list, basic_driving_rate,
    //     decline_matrix, car_num_list, max_car_list);
  } else {
    result = find_best_choice_greedy(num_car_type, num_stations, car_price_list,
                                     basic_driving_rate, decline_matrix,
                                     car_num_list, max_car_list);
  }

  // output the result
  for (int i = 0; i < num_car_type; i++) {
    for (int j = 0; j < num_stations; j++) {
      if (j < num_stations - 1)
        cout << result[i][j] << ",";
      else
        cout << result[i][j];
    }
    cout << endl;
  }

#ifdef ENABLE_DEBUG
  // Stop the timer
  auto stop = chrono::high_resolution_clock::now();

  // Calculate the duration
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

  cerr << "Time taken by function: " << duration.count() << " microseconds"
       << endl;
#endif

  return 0;
}