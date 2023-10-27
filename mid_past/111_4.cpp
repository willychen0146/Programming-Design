#include <iostream>
using namespace std;
// not fully correct
int find_shortest_hos(int, int, int**, int**);

int main () {
  int city_num, hos_num, threshold; // hos = hospital 
  cin >> city_num >> hos_num >> threshold;

  // city matrix
  int** city_matrix = nullptr;
  city_matrix = new int*[city_num];
  for (int i = 0; i < city_num; i++) {
    city_matrix[i] = new int[city_num];
    for (int j = 0; j < city_num; j++) {
      cin >> city_matrix[i][j];
    }
  }

  // hospital location
  int* hos_loc = nullptr;
  hos_loc = new int[hos_num];
  for (int i = 0; i < hos_num; i++) {
    cin >> hos_loc[i];
  }
  int** hos_matrix = nullptr;
  hos_matrix = new int*[city_num];
  for (int i = 0; i < city_num; i++) {
    hos_matrix[i] = new int[city_num];
    for (int j = 0; j < city_num; j++) {
      hos_matrix[i][j] = 0;
      for (int k = 0; k < hos_num; k++) {
        if(hos_loc[k]-1 == i && hos_loc[k]-1 == j)
          hos_matrix[i][j] = 1;
      }
    }
  }

  // find sum of shortest distance and is lovely city
  int distance = 0, lovely_num = 0, temp = 0;
  for (int i = 0; i < city_num; i++) {
    temp = find_shortest_hos(i, city_num, city_matrix, hos_matrix);
    // cout << temp << " ";
    distance += temp;
    if(temp <= threshold){
      lovely_num ++;
    }
  }
  // cout << endl;

  // result
  cout << distance << "," << lovely_num << endl;
  return 0;
}

int find_shortest_hos(int target, int city_num, int** city_matrix, int** hos_matrix){
  int min = 1001;
  for (int i = 0; i < city_num; i++) {
    if(hos_matrix[target][target] == 1){
      min = 0;
      break;
    }
    if(city_matrix[target][i] != 0 && hos_matrix[i][i] == 1){
      if(city_matrix[target][i] <= min)
      min = city_matrix[target][i];
    }
  }
  return min;
}

