#include <iostream>
#include <chrono>
using namespace std;

void find_best_choice(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, float** decline_matrix, 
                      float decline_degree0, int* car_num_list, int* max_car_list, int* sum_car_x, int* sum_car_y, int total_car);
float score_model(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, 
                  float** decline_matrix, float decline_degree0);                      
void gpt_find_best_choice(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, float** decline_matrix, 
                      float decline_degree0, int* car_num_list, int* max_car_list, int* sum_car_x, int* sum_car_y, int total_car);
float gpt_score_model(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, 
                  float** decline_matrix, float decline_degree0);      


int main(){
    // Start the timer
    // auto start = chrono::high_resolution_clock::now();

    int temp = 0;
    float temp_f = 0.0;
    int total_car = 0;
    // get car type, stations number, 4 degree of demand cannibalization effect radius
    int num_car_type, num_stations;
    float decline_degree0, decline_degree1, decline_degree2, decline_degree3;
    cin >> num_car_type >> num_stations;
    cin >> decline_degree0 >> decline_degree1 >> decline_degree2 >> decline_degree3;

    // get list of different price of car type
    int* car_price_list = nullptr;
    car_price_list = new int[num_car_type];
    for(int i = 0; i < num_car_type; i++){
        cin >> temp;
        car_price_list[i] = temp;
    }

    // get list of different number of car type
    int* car_num_list = nullptr;
    car_num_list = new int[num_car_type];
    for(int i = 0; i < num_car_type; i++){
        cin >> temp;
        car_num_list[i] = temp;
        total_car += temp;
    }

    // get list of Maximum number of car at different stations
    int* max_car_list = nullptr;
    max_car_list = new int[num_stations];
    for(int i = 0; i < num_stations; i++){
        cin >> temp;
        max_car_list[i] = temp;
    }

    // get 2D-list of Basic Driving Rates matrix
    float** basic_driving_rate = nullptr;
    basic_driving_rate = new float*[num_car_type];
    for(int i = 0; i < num_car_type; i++){
        basic_driving_rate[i] = new float[num_stations];
        for(int j = 0; j < num_stations; j++){
        cin >> temp_f;
        basic_driving_rate[i][j] = temp_f;
        }
    }

    // get 2D-list of distance between different stations and each other station (Units = meters)
    int** station_distance = nullptr;
    station_distance = new int*[num_stations];
    for(int i = 0; i < num_stations; i++){
        station_distance[i] = new int[num_stations];
        for(int j = 0; j < num_stations; j++){
        cin >> temp;
        station_distance[i][j] = temp;
        }
    }

    // Create Result matrix to store the result, initiate it with 0
    int** result = nullptr;
    result = new int*[num_car_type];
    for(int i = 0; i < num_car_type; i++){
        result[i] = new int[num_stations];
        for(int j = 0; j < num_stations; j++){
        result[i][j] = 0;
        }
    }    

    // turn distance into decline_matrix
    float** decline_matrix = nullptr;
    decline_matrix = new float*[num_stations];
    for(int i = 0; i < num_stations; i++){
        decline_matrix[i] = new float[num_stations];
        for(int j = 0; j < num_stations; j++){

            if(station_distance[i][j] < 1){
                decline_matrix[i][j] = decline_degree0;
            }
            else if(station_distance[i][j] >= 1 && station_distance[i][j] < 301){
                decline_matrix[i][j] = decline_degree1;
            }
            else if(station_distance[i][j] >= 301 && station_distance[i][j] < 501){
                decline_matrix[i][j] = decline_degree2;
            }
            else if(station_distance[i][j] >= 501 && station_distance[i][j] < 1001){
                decline_matrix[i][j] = decline_degree3;
            }
            else{
                decline_matrix[i][j] = 0.0;
            }
        }
    }    

    // compute sum car in every row and colunm
    int* sum_car_x = nullptr;
    sum_car_x = new int[num_car_type];
    for(int i = 0; i < num_car_type; i++){
        sum_car_x[i] = 0;
    }

    int* sum_car_y = nullptr;
    sum_car_y = new int[num_stations];
    for(int i = 0; i < num_stations; i++){
        sum_car_y[i] = 0;
    }

    // Start Computing Greedy algorithm
    gpt_find_best_choice(result, num_car_type, num_stations, car_price_list, basic_driving_rate, decline_matrix, decline_degree0, car_num_list, max_car_list, sum_car_x, sum_car_y, total_car);

    // output the result
    for(int i = 0; i < num_car_type; i++){
        for(int j = 0; j < num_stations; j++){
            if(j < num_stations - 1)
                cout << result[i][j] << ",";
            else
                cout << result[i][j];
        }
    cout << endl;
    }

    // // Stop the timer
    // auto stop = chrono::high_resolution_clock::now();

    // // Calculate the duration
    // auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}

/*                  */
/*     function     */
/*                  */

void find_best_choice(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, float** decline_matrix, 
                      float decline_degree0, int* car_num_list, int* max_car_list, int* sum_car_x, int* sum_car_y, int total_car){
    int loop_count = 0;
    while(total_car > 0){
        // one loop compute one car, if found --> add one car into result
        int choosed_car = 0;
        int choosed_station = 0;
        float score = 0.0;
        float temp_score = 0.0;
        bool flag = false; // detect what if max_car_list and car_num_list is out of range --> break
        
        // find best target car
        for(int i = 0; i < num_car_type; i++){
            for(int j = 0; j < num_stations; j++){
                list[i][j] += 1;
                score = score_model(list, num_car_type, num_stations, car_price_list, basic_driving_rate, decline_matrix, decline_degree0);
                if(score > temp_score){
                    if((sum_car_x[i] < car_num_list[i]) && (sum_car_y[j] < max_car_list[j])){
                        // temp_score = score;
                        choosed_car = i;
                        choosed_station = j;
                        flag = true;
                    }
                list[i][j] -= 1;
                    if((sum_car_x[i] >= car_num_list[i]) && (sum_car_y[j] < max_car_list[j])){
                        continue;
                    }
                    if((sum_car_x[i] < car_num_list[i]) && (sum_car_y[j] >= max_car_list[j])){
                        continue;
                    }                    
                }
            }
        }
        // if not found or out of range --> break
        if(!flag){
            break;
        }
        // adding the car, increase the sum, loop count + 1
        // cout << list[choosed_car][choosed_station] << endl;
        list[choosed_car][choosed_station] += 1;
        // cout << list[choosed_car][choosed_station] << endl;
        // cout << choosed_car << " " << choosed_station << endl;
        // cout << choosed_car << endl;
        sum_car_x[choosed_car] += 1;
        sum_car_y[choosed_station] += 1;
        total_car--;
        loop_count++;
    }
    // cout << loop_count << endl;
}

float score_model(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, 
                  float** decline_matrix, float decline_degree0){
    float score_model = 0.0;
    int temp_i;
    int temp_j;
    // compute for score in this situation (one situation)
    for(int i = 0; i < num_car_type; i++){
        for(int j = 0; j < num_stations; j++){
            for(int k = 0; k < num_stations; k++){
                // score_model += 24 * car_price_list[i] * (basic_driving_rate[i][j] - decline_matrix[j][k] * list[i][j]) * list[i][j]; // main model
                // score_model += 24 * car_price_list[i] * decline_degree0 * list[i][j];
                float temp = basic_driving_rate[i][j] - decline_matrix[j][k] * list[i][j]; // gpt
                score_model += 24 * car_price_list[i] * temp * list[i][j]; // gpt
            }
            score_model += 24 * car_price_list[i] * decline_degree0 * list[i][j]; // gpt
        }
        // score_model += 24 * car_price_list[i] * decline_degree0 * list[i][j]; // plus self decline and the end every i loop
    }
    // cout << score_model <<endl;
    // return score
    return score_model;
}

void gpt_find_best_choice(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, float** decline_matrix, 
                      float decline_degree0, int* car_num_list, int* max_car_list, int* sum_car_x, int* sum_car_y, int total_car) {
    int loop_count = 0;
    bool placed = true;
    float past_score = 0.0;

    while (total_car > 0 && placed) {
        placed = false; // Flag to track if a car was placed in this iteration.

        for (int i = 0; i < num_car_type; i++) {
            if (sum_car_x[i] > car_num_list[i]) {
                continue; // If the max cars of this type are reached, skip.
            }

            for (int j = 0; j < num_stations; j++) {
                if (sum_car_y[j] > max_car_list[j]) {
                    continue; // If the max cars at this station are reached, skip.
                }

                // Check if adding a car temporarily exceeds any upper limit.
                if (sum_car_x[i] >= car_num_list[i] || sum_car_y[j] >= max_car_list[j]) {
                    continue; // Skip this placement if it exceeds the upper limit on either axis.
                }

                list[i][j] += 1; // Place a car temporarily.

                float score = gpt_score_model(list, num_car_type, num_stations, car_price_list, basic_driving_rate, decline_matrix, decline_degree0);

                if (score - past_score > 0) { // Only increase if the score improved.
                    sum_car_x[i] += 1;
                    sum_car_y[j] += 1;
                    total_car--;
                    past_score = score;
                    loop_count++;
                    placed = true;
                } else {
                    list[i][j] -= 1; // Revert the placement.
                }
            }
        }
    }
}

float gpt_score_model(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, 
                  float** decline_matrix, float decline_degree0){
    float score_model = 0.0;

    for(int i = 0; i < num_car_type; i++){
        for(int j = 0; j < num_stations; j++){
            float base_crop_ij = basic_driving_rate[i][j] * list[i][j]; // Calculate the base crop for this location
            float crop_impact = 0.0;

            for(int k = 0; k < num_stations; k++){
                crop_impact += decline_matrix[j][k] * list[i][k]; // Sum up the crop impact from other locations
            }

            // Calculate the score contribution for this location (ij)
            float score_contribution_ij = 24 * car_price_list[i] * (base_crop_ij - crop_impact) * list[i][j];
            score_model += score_contribution_ij;
        }
    }

    // Add the decline_degree0 term for each location
    for(int j = 0; j < num_stations; j++){
        for(int i = 0; i < num_car_type; i++){
            score_model += 24 * car_price_list[i] * decline_degree0 * list[i][j];
        }
    }

    // Subtract 0.8 times the product of car count and car price for each location
    // for(int i = 0; i < num_car_type; i++){
    //     for(int j = 0; j < num_stations; j++){
    //         score_model -= 24 * list[i][j] * car_price_list[i] * 0.8;
    //     }
    // }

    return score_model;
}