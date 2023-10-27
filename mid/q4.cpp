#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int city_num;
    cin >> city_num;

    int** distance_map = nullptr;
    distance_map = new int*[city_num];
    for (int i = 0; i < city_num; i++) {
        distance_map[i] = new int[city_num];
        for (int j = 0; j < city_num; j++) {
        cin >> distance_map[i][j];
        }
    }

    int** record_map = nullptr;
    record_map = new int*[city_num];
    for (int i = 0; i < city_num; i++) {
        record_map[i] = new int[city_num];
        for (int j = 0; j < city_num; j++) {
            record_map[i][j] = 0; // not choose yet
        }
    }

    int num_can_be_saved = 0;
    int total_save_time = 0;

    // TODO
    for (int i = 0; i < city_num; i++) {
        for (int j = 0; j < city_num; j++) {
            if (i != j) {
                int max_save = 0;
                int select_i = -1;
                int select_j = -1;
                for (int k = 0; k < city_num; k++) {
                    if (i != k && k != j) {
                        int potential_saving = distance_map[i][j] - (distance_map[i][k] + distance_map[k][j]);
                        // cout << potential_saving <<endl;
                        if (potential_saving > 0 && record_map[i][j] == 0 && potential_saving > max_save) {
                            select_i = i;
                            select_j = j;
                            max_save = potential_saving;
                            // cout << potential_saving <<endl;
                            // cout << i << " " << j << " " << k << endl;
                        }
                    }
                }
                if(select_i != -1 && select_j != -1){
                    total_save_time += max_save;
                    num_can_be_saved++;
                    record_map[select_i][select_j] = 1;
                    record_map[select_j][select_i] = 1;                    
                }
            }
        }
    }


    cout << num_can_be_saved << "," << total_save_time << endl;
    // Deallocate memory
    for (int i = 0; i < city_num; i++) {
        delete[] distance_map[i];
        delete[] record_map[i];
    }
    delete[] distance_map;
    delete[] record_map;

    return 0;
}