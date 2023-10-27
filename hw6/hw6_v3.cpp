#include <iostream>
using namespace std;

void find_best_choice(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, float** decline_matrix, 
                      float decline_degree0, int* car_num_list, int* max_car_list, int* sum_car_x, int* sum_car_y, int total_car);
void find_best_choice_fast_L(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, float** decline_matrix, 
                      float decline_degree0, int* car_num_list, int* max_car_list, int* sum_car_x, int* sum_car_y, int total_car);
void find_best_choice_fast_R(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, float** decline_matrix, 
                      float decline_degree0, int* car_num_list, int* max_car_list, int* sum_car_x, int* sum_car_y, int total_car);
float score_model(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, 
                  float** decline_matrix, float decline_degree0);                   
float score_model_local(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, 
                  float** decline_matrix, float decline_degree0, int, int); 
float gpt_score_model(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, 
                  float** decline_matrix, float decline_degree0);           

int main(){
    int temp = 0;
    float temp_f = 0.0;
    int total_car = 0;
    // get car type, stations number, 4 degree of demand cannibalization effect radius
    int num_car_type, num_stations;
    float decline_degree0, decline_degree1, decline_degree2, decline_degree3;
    cin >> num_car_type >> num_stations;
    cin >> decline_degree0 >> decline_degree1 >> decline_degree2 >> decline_degree3;
    // cout << num_car_type << " " << num_stations << " " << endl;
    // cout << decline_degree0 << " " << decline_degree1 << " " << decline_degree2 << " " << decline_degree3 << endl;

    // get list of different price of car type
    int* car_price_list = nullptr;
    car_price_list = new int[num_car_type];
    for(int i = 0; i < num_car_type; i++){
        cin >> temp;
        car_price_list[i] = temp;
        // cout << car_price_list[i] << " ";
    }
    // cout << endl;
    // get list of different number of car type
    int* car_num_list = nullptr;
    car_num_list = new int[num_car_type];
    for(int i = 0; i < num_car_type; i++){
        cin >> temp;
        car_num_list[i] = temp;
        total_car += temp;
        // cout << car_num_list[i] << " ";
    }
    // cout << endl;
    // get list of Maximum number of car at different stations
    int* max_car_list = nullptr;
    max_car_list = new int[num_stations];
    for(int i = 0; i < num_stations; i++){
        cin >> temp;
        max_car_list[i] = temp;
        // cout << max_car_list[i] << " ";
    }
    // cout << endl;
    // get 2D-list of Basic Driving Rates matrix
    float** basic_driving_rate = nullptr;
    basic_driving_rate = new float*[num_car_type];
    for(int i = 0; i < num_car_type; i++){
        basic_driving_rate[i] = new float[num_stations];
        for(int j = 0; j < num_stations; j++){
        cin >> temp_f;
        basic_driving_rate[i][j] = temp_f;
        // cout << basic_driving_rate[i][j] << " ";
        }
    }
    // cout << endl;
    // get 2D-list of distance between different stations and each other station (Units = meters)
    int** station_distance = nullptr;
    station_distance = new int*[num_stations];
    for(int i = 0; i < num_stations; i++){
        station_distance[i] = new int[num_stations];
        for(int j = 0; j < num_stations; j++){
        cin >> temp;
        station_distance[i][j] = temp;
        // cout << station_distance[i][j] << " ";
        }
    }
    // cout << endl;
    // Create Result matrix to store the result, initiate it with 0 (L and R)
    int** result_L = nullptr;
    result_L = new int*[num_car_type];
    for(int i = 0; i < num_car_type; i++){
        result_L[i] = new int[num_stations];
        for(int j = 0; j < num_stations; j++){
        result_L[i][j] = 0;
        }
    }   
    int** result_R = nullptr;
    result_R = new int*[num_car_type];
    for(int i = 0; i < num_car_type; i++){
        result_R[i] = new int[num_stations];
        for(int j = 0; j < num_stations; j++){
        result_R[i][j] = 0;
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
    float score_L = 0.0;
    float score_R = 0.0;
    find_best_choice_fast_L(result_L, num_car_type, num_stations, car_price_list, basic_driving_rate, decline_matrix, decline_degree0, car_num_list, max_car_list, sum_car_x, sum_car_y, total_car);
    score_L = gpt_score_model(result_L, num_car_type, num_stations, car_price_list, basic_driving_rate, decline_matrix, decline_degree0);
    find_best_choice_fast_R(result_R, num_car_type, num_stations, car_price_list, basic_driving_rate, decline_matrix, decline_degree0, car_num_list, max_car_list, sum_car_x, sum_car_y, total_car);
    score_R = gpt_score_model(result_R, num_car_type, num_stations, car_price_list, basic_driving_rate, decline_matrix, decline_degree0);

    // cout << "L: " << score_L << endl;
    // cout << "R: " << score_R << endl;

    // output the result
    if(score_L >= score_R){
        for(int i = 0; i < num_car_type; i++){
            for(int j = 0; j < num_stations; j++){
                if(j < num_stations - 1)
                    cout << result_L[i][j] << ",";
                else
                    cout << result_L[i][j];
            }
        cout << endl;
        }
    }
    else{
        for(int i = 0; i < num_car_type; i++){
            for(int j = 0; j < num_stations; j++){
                if(j < num_stations - 1)
                    cout << result_R[i][j] << ",";
                else
                    cout << result_R[i][j];
            }
        cout << endl;
        }
    }
    return 0;
}

/*                  */
/*     function     */
/*                  */


void find_best_choice(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, float** decline_matrix, 
                      float decline_degree0, int* car_num_list, int* max_car_list, int* sum_car_x, int* sum_car_y, int total_car){
    int loop_count = 0;
    while(1){
        // one loop compute one car
        int choosed_car = 0;
        int choosed_station = 0;
        float score = 0.0;
        float temp_score = 0.0;
        int car_sum = 0;
        bool flag = false; // detect what if max_car_list and car_num_list is out of range --> break
        for(int i = 0; i < num_car_type; i++){
            for(int j = 0; j < num_stations; j++){
                list[i][j] += 1;
                score = score_model_local(list, num_car_type, num_stations, car_price_list, basic_driving_rate, decline_matrix, decline_degree0, i, j);
                if(score > temp_score){
                    if((sum_car_x[i] < car_num_list[i]) && (sum_car_y[j] < max_car_list[j]) && car_sum < total_car){
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
        if(flag == false){
            break;
        }
        // adding the car
        // cout << list[choosed_car][choosed_station] << endl;
        list[choosed_car][choosed_station] += 1;
        // cout << list[choosed_car][choosed_station] << endl;
        // cout << choosed_car << " " << choosed_station << endl;
        // cout << choosed_car << endl;
        sum_car_x[choosed_car] += 1;
        sum_car_y[choosed_station] += 1;
        loop_count++;
    }
    // cout << loop_count << endl;
}

void find_best_choice_fast_L(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, float** decline_matrix, 
                      float decline_degree0, int* car_num_list, int* max_car_list, int* sum_car_x, int* sum_car_y, int total_car){
    int loop_count = 0;
    int car_sum_x, car_sum_y;
    float past_score = 0.0;
    int threshold = 80;
    
    for(int i = 0; i < num_car_type; i++){
        for(int j = 0; j < num_stations; j++){
            // one loop compute one car
            while(1){
                float score = 0.0;
                car_sum_x = 0;
                car_sum_y = 0;
                list[i][j] += 1;
                // 計算目前的y軸總量
                for(int k = 0; k <= i; k++){
                    car_sum_y += list[k][j];
                }
                // 計算目前的x軸總量
                for(int l = 0; l <= j; l++){
                    car_sum_x += list[i][l];
                }
                // 計算目前的x軸總量大於某車的最大數 --> break
                if(car_sum_x > car_num_list[i]){
                    list[i][j] -= 1;
                    j = num_stations;
                    break;
                }
                // 計算目前的y軸總量大於某車的最大數 --> break
                if(car_sum_y > max_car_list[j]){
                    list[i][j] -= 1;
                    break;
                }
                // 計算當前總score
                score = score_model_local(list, num_car_type, num_stations, car_price_list, basic_driving_rate, decline_matrix, decline_degree0, i, j);
                // cout<<"score:"<<score<<endl;
                if(score - past_score <= 0){
                    list[i][j] -= 1;
                    break;
                }
                else{
                    past_score = score;
                }
            }
        }
    }
    // cout << loop_count << endl;
}

void find_best_choice_fast_R(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, float** decline_matrix, 
                      float decline_degree0, int* car_num_list, int* max_car_list, int* sum_car_x, int* sum_car_y, int total_car){
    int loop_count = 0;
    float past_score = 0.0;
    
    for(int i = num_car_type - 1; i >= 0; i--){
        for(int j = num_stations - 1; j >= 0; j--){
            // one loop computes one car
            while(1){
                float score = 0.0;
                list[i][j] += 1;
                // Calculate current y-axis total
                int car_sum_y = 0;
                for(int k = num_car_type - 1; k >= i; k--){
                    car_sum_y += list[k][j];
                }
                // Calculate current x-axis total
                int car_sum_x = 0;
                for(int l = num_stations - 1; l >= j; l--){
                    car_sum_x += list[i][l];
                }
                // Check if the current x-axis total is greater than the maximum for this car type
                if(car_sum_x > car_num_list[i]){
                    list[i][j] -= 1;
                    j = -1;
                    break;
                }
                // Check if the current y-axis total is greater than the maximum for this station
                if(car_sum_y > max_car_list[j]){
                    list[i][j] -= 1;
                    break;
                }
                // Calculate the current score
                score = score_model_local(list, num_car_type, num_stations, car_price_list, basic_driving_rate, decline_matrix, decline_degree0, i, j);
                if(score - past_score <= 0){
                    list[i][j] -= 1;
                    break;
                }
                else{
                    past_score = score;
                }
            }
        }
    }
    // cout << loop_count << endl;
}

float score_model(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, 
                  float** decline_matrix, float decline_degree0){
    float score_model = 0.0;
    // compute for score in this situation (one situation)
    for(int i = 0; i < num_car_type; i++){
        for(int j = 0; j < num_stations; j++){
            for(int k = 0; k < num_stations; k++){
                score_model += 24 * car_price_list[i] * (basic_driving_rate[i][j] - decline_matrix[j][k] * list[i][j]) * list[i][j]; // main model
                // score_model += 24 * car_price_list[i] * decline_degree0 * list[i][j];
                // float temp = basic_driving_rate[i][j] - decline_matrix[j][k] * list[i][j]; // gpt
                // score_model += 24 * car_price_list[i] * temp * list[i][j]; // gpt
            }
            score_model += 24 * car_price_list[i] * decline_degree0 * list[i][j]; // gpt
            score_model -= 24 * list[i][j] * car_price_list[i] * 0.8;
        }
    }
    // cout << score_model <<endl;
    return score_model;
}

float score_model_local(int** list, int num_car_type, int num_stations, int* car_price_list, float** basic_driving_rate, 
                  float** decline_matrix, float decline_degree0, int pos_y, int pos_x){
    // 先傳入跑到的y跟x位置
    float score_model = 0.0;
    // 設定參數
    int temp_i;
    int temp_j;
    int max_y, min_y;
    int max_x, min_x;
    int block_size = 4;
    max_y = pos_y + block_size;
    min_y = pos_y - block_size;
    max_x = pos_x + block_size;
    min_x = pos_x - block_size;
    // 如果被block加到超出範圍 --> 設成最大值
    if(max_y > num_car_type)
        max_y = num_car_type;
    // 如果被block減到變負 --> 設成0
    if(min_y < 0)
        min_y = 0;
    // 如果被block加到超出範圍 --> 設成最大值
    if(max_x > num_stations)
        max_x = num_stations;
    // 如果被block減到變負 --> 設成0
    if(min_x < 0)
        min_x = 0;
    // cout<<min_y<<" "<<max_y<<" "<<min_x<<" "<<max_x<<endl;
    // 開始計算局部 (範圍由block決定) 的分數
    for(int i = min_y; i < max_y; i++){
        for(int j = min_x; j < max_x; j++){
            for(int k = min_x; k < max_x; k++){
                score_model += 24 * car_price_list[i] * (basic_driving_rate[i][j] - decline_matrix[j][k] * list[i][j]) * list[i][j]; // main model
                // score_model += 24 * car_price_list[i] * decline_degree0 * list[i][j];
                // score_model -= 24 * list[i][j] * car_price_list[i] * 0.8;
            }
            score_model += 24 * car_price_list[i] * decline_degree0 * list[i][j];
            score_model -= 24 * list[i][j] * car_price_list[i] * 0.8;
        }
        // score_model += 24 * car_price_list[i] * decline_degree0 * list[i][j]; // plus self decline and the end every i loop
    }
    // cout << score_model <<endl;

    return score_model;
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
