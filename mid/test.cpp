#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9; // Represents infinity (a very large value)

int main() {
    int city_num;
    cin >> city_num;

    int** distance_map = nullptr;
    distance_map = new int*[city_num];
    for (int i = 0; i < city_num; i++) {
        distance_map[i] = new int[city_num];
        for (int j = 0; j < city_num; j++) {
            cin >> distance_map[i][j];
            // Initialize the distance_map with input values
        }
    }

    // Calculate shortest distances using Floyd-Warshall algorithm
    for (int k = 0; k < city_num; k++) {
        for (int i = 0; i < city_num; i++) {
            for (int j = 0; j < city_num; j++) {
                if (distance_map[i][k] != INF && distance_map[k][j] != INF) {
                    distance_map[i][j] = min(distance_map[i][j], distance_map[i][k] + distance_map[k][j]);
                }
            }
        }
    }

    int num_can_be_saved = 0;
    int total_save_time = 0;

    // Calculate potential savings
    for (int i = 0; i < city_num; i++) {
        for (int j = 0; j < city_num; j++) {
            if (i != j) {
                for (int k = 0; k < city_num; k++) {
                    if (i != k && k != j) {
                        int potential_saving = distance_map[i][j] - (distance_map[i][k] + distance_map[k][j]);
                        if (potential_saving > 0) {
                            total_save_time += potential_saving;
                            num_can_be_saved++;
                        }
                    }
                }
            }
        }
    }

    cout << num_can_be_saved << "," << total_save_time << endl;

    // Deallocate memory
    for (int i = 0; i < city_num; i++) {
        delete[] distance_map[i];
    }
    delete[] distance_map;

    return 0;
}
