#include <iostream>
using namespace std;

void bubble_sort(int* num_array, int total_num);
float evaluation(int **, int, int, int*, float **, float **);

int main(){
    int temp = 0;
    float temp_f = 0.0;
    // get car type, stations number, 4 degree of demand cannibalization effect radius
    int n, m;
    float decline_degree0, decline_degree1, decline_degree2, decline_degree3;
    cin >> n >> m;
    cin >> decline_degree0 >> decline_degree1 >> decline_degree2 >> decline_degree3;

    int* car_price_list = nullptr;
    car_price_list = new int[n];
    for(int i = 0; i < n; i++){
        cin >> temp;
        car_price_list[i] = temp;
        // cout << car_price_list[i] << " ";
    }
    // cout << endl;
    // get list of different number of car type
    int* car_num_list = nullptr;
    car_num_list = new int[n];
    for(int i = 0; i < n; i++){
        cin >> temp;
        car_num_list[i] = temp;
        // cout << car_num_list[i] << " ";
    }
    // cout << endl;
    // get list of Maximum number of car at different stations
    int* max_car_list = nullptr;
    max_car_list = new int[m];
    for(int i = 0; i < m; i++){
        cin >> temp;
        max_car_list[i] = temp;
        // cout << max_car_list[i] << " ";
    }
    // cout << endl;
    // get 2D-list of Basic Driving Rates matrix
    float** basic_driving_rate = nullptr;
    basic_driving_rate = new float*[n];
    for(int i = 0; i < n; i++){
        basic_driving_rate[i] = new float[m];
        for(int j = 0; j < m; j++){
        cin >> temp_f;
        basic_driving_rate[i][j] = temp_f;
        // cout << basic_driving_rate[i][j] << " ";
        }
    }
    // cout << endl;
    // get 2D-list of distance between different stations and each other station (Units = meters)
    int** station_distance = nullptr;
    station_distance = new int*[m];
    for(int i = 0; i < m; i++){
        station_distance[i] = new int[m];
        for(int j = 0; j < m; j++){
        cin >> temp;
        station_distance[i][j] = temp;
        // cout << station_distance[i][j] << " ";
        }
    }
    // cout << endl;
    // Create Result matrix to store the result, initiate it with 0
    int** result = nullptr;
    result = new int*[n];
    for(int i = 0; i < n; i++){
        result[i] = new int[m];
        for(int j = 0; j < m; j++){
            result[i][j] = 0;
        }
    }    

    // Start Computing
    float **new_driving_rate;
    new_driving_rate = new float*[m];
    for(int i=0;i<m;i++){
        new_driving_rate[i] = new float[m];
        for(int j=0;j<m;j++){

            if(station_distance[i][j] < 1){
                new_driving_rate[i][j] = decline_degree0;
            }
            else if(station_distance[i][j] >= 1 && station_distance[i][j] < 301){
                new_driving_rate[i][j] = decline_degree1;
            }
            else if(station_distance[i][j] >= 301 && station_distance[i][j] < 501){
                new_driving_rate[i][j] = decline_degree2;
            }
            else if(station_distance[i][j] >= 501 && station_distance[i][j] < 1001){
                new_driving_rate[i][j] = decline_degree3;
            }
            else{
                new_driving_rate[i][j] = 0.0;
            }
        }
    }

    // cout<<"Q"<<endl;
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<m;j++){
            // cout<<new_driving_rate[i][j]<<" ";
    //     }
    // }
    // cout<<endl;

    // output the result

    float **price_diff = nullptr;
    price_diff = new float*[n];
    for(int i = 0; i < n; i++){
        price_diff[i] = new float[m];
        for(int j = 0; j < m; j++){
        price_diff[i][j] = 0.0;
        }
    }    
    
    float price_raw;
    int max_idx, max_idy;
    int max;
    int sum_x,sum_y;
    bool flag;

    int count = 0;
    int max_loop = 0;

    for(int i = 0; i < m; i++){
        max_loop += max_car_list[i];
    }

    while(1){

        price_raw = evaluation(result, n, m, car_price_list, basic_driving_rate, new_driving_rate);
        // cout<<"raw:"<<price_raw<<endl;

        flag = false;
        max = -1;
        max_idx = -1;
        max_idy = -1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                sum_x = 0;
                for(int k=0;k<m;k++){
                    sum_x += result[i][k];
                }
                sum_y = 0;
                for(int k=0;k<n;k++){
                    sum_y += result[k][j];
                }
                if((sum_x + 1 > car_num_list[j]) || (sum_y + 1 > max_car_list[i])){
                    price_diff[i][j] = 0.0;
                    continue;
                }


                result[i][j] += 1;
                price_diff[i][j] = evaluation(result, n, m, car_price_list, basic_driving_rate, new_driving_rate) - price_raw;



                if(price_diff[i][j] > 0){
                    flag = true;
                }
                result[i][j] -= 1;


                if(price_diff[i][j] >= max){
                    max = price_diff[i][j];
                    max_idy = i;
                    max_idx = j;
                }
            }
        }

        if(flag == false){
            break;
        }
        if(max_idy >= 0 && max_idx >= 0){
            result[max_idy][max_idx]++;
        }
        else{
            break;
        }

        // cout<<"price_diff"<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(j < m-1)
        //             cout<<price_diff[i][j]<<",";
        //         else
        //             cout<<price_diff[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<"result"<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(j < m-1)
        //             cout<<result[i][j]<<",";
        //         else
        //             cout<<result[i][j];
        //     }
        //     cout<<endl;
        // }
        
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j < m-1)
                cout<<result[i][j]<<",";
            else
                cout<<result[i][j];

        }
        cout<<endl;
    }

    return 0;
}


/*                  */
/*     function     */
/*                  */
float evaluation(int **list, int n, int m, int *car_price_list, float **basic_driving_rate, float **new_driving_rate){
    int score = 0;
    float r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            r = basic_driving_rate[i][j] + 0.1;
            for(int k=0;k<n;k++){
                for(int l=0;l<m;l++){
                    r -= new_driving_rate[k][j] * list[k][l];
                }
            }
            
            score += list[i][j] * car_price_list[j] * r;
        }
    }
    return score;
}



// void bubble_sort(int* num_array, int total_num){
//     int temp;
//     int swapped;

//     for (int i = 0; i < total_num - 1; i++) {
//         swapped = 0; 
//         for (int j = 0; j < total_num - i - 1; j++) {
//             if (num_array[j] > num_array[j + 1]) {
//                 // switch array[j] and array[j+1]
//                 temp = num_array[j];
//                 num_array[j] = num_array[j + 1];
//                 num_array[j + 1] = temp;
//                 swapped = 1; // switch happen
//             }
//         }

//         // if switch not happen, the sorting is complete
//         if (swapped == 0) {
//             break;
//         }
//     }
// }