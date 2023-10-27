#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main () {
  int x_len, y_len, radius, num_station, num_rail;
  cin >> x_len >> y_len >> radius >> num_station >> num_rail;
  
  vector<vector<int>> people_map(x_len, vector<int>(y_len));
  vector<vector<bool>> has_calculate(x_len, vector<bool>(y_len, false));
  
  vector<pair<int, int>> rail_map(num_station);
  for (int i = 0; i < num_station; i++) {
    cin >> rail_map[i].first >> rail_map[i].second;
    rail_map[i].first--;  // Adjust to 0-based indexing
    rail_map[i].second--;
  }

  vector<pair<int, int>> connect(num_rail);
  for (int i = 0; i < num_rail; i++) {
    cin >> connect[i].first >> connect[i].second;
    connect[i].first--;  // Adjust to 0-based indexing
    connect[i].second--;
  }

  int result = 0;
  int radius_result = 0;

  // Calculate result based on rail connections
  for (int i = 0; i < num_rail; i++) {
    int x1 = rail_map[connect[i].first].first;
    int y1 = rail_map[connect[i].first].second;
    int x2 = rail_map[connect[i].second].first;
    int y2 = rail_map[connect[i].second].second;

    if (x1 == x2) {  // Same column
      int minY = min(y1, y2);
      int maxY = max(y1, y2);
      for (int y = minY; y <= maxY; y++) {
        if (!has_calculate[x1][y]) {
          result += people_map[x1][y];
          has_calculate[x1][y] = true;
        }
      }
    } else {  // Same row
      int minX = min(x1, x2);
      int maxX = max(x1, x2);
      for (int x = minX; x <= maxX; x++) {
        if (!has_calculate[x][y1]) {
          result += people_map[x][y1];
          has_calculate[x][y1] = true;
        }
      }
    }
  }

  // Calculate radius_result
  for (int i = 0; i < num_station; i++) {
    int x0 = rail_map[i].first;
    int y0 = rail_map[i].second;

    for (int x = max(0, x0 - radius); x <= min(x_len - 1, x0 + radius); x++) {
      for (int y = max(0, y0 - radius); y <= min(y_len - 1, y0 + radius); y++) {
        if (sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0)) <= radius) {
          if (!has_calculate[x][y]) {
            radius_result += people_map[x][y];
            has_calculate[x][y] = true;
          }
        }
      }
    }
  }

  cout << radius_result << "," << result << endl;

  return 0;
}