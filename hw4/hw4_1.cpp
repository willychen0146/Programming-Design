#include <iostream>
using namespace std;

// This is the prototype of the function to be completed
void checkCorrectness(int stationNum, int initPass, int maxPass, const int** passenger, int& wrongStationID, int& wrongType);

int main(){
    int stationNum = 0, initPass = 0, maxPass = 0;
    int** passenger = new int*[2];

    int wrongStationID = 0;
    int wrongType = 0;

    cin >> stationNum >> initPass >> maxPass;
    passenger[0] = new int[stationNum - 1];
    passenger[1] = new int[stationNum - 1];

    for(int i = 0; i < stationNum - 1; i++){
        cin >> passenger[0][i];
    }
    for(int i = 0; i < stationNum - 1; i++){
        cin >> passenger[1][i];
    }
    
    checkCorrectness(stationNum, initPass, maxPass, const_cast<const int**>(passenger), wrongStationID, wrongType);

    if(wrongStationID == 0){
        cout << wrongStationID;
    }
    else{
        if(wrongType == 1){
            cout << wrongStationID << ",N";
        }
        else if(wrongType == 2){
            cout << wrongStationID << ",C";
        }
        else if(wrongType == 3){
            cout << wrongStationID << ",B";
        }
    }
    
    delete[] passenger[0];
    delete[] passenger[1];
    passenger[0] = passenger[1] = nullptr;
    delete[] passenger;
    passenger = nullptr;
    
    return 0;
}

// Your codes will be copied and pasted here
void checkCorrectness(int num_station, int started_people, int limitation_passenger, const int** passenger, int& wrong_stationID, int& wrong_type){
	// get input
	int error_1 = 0, error_2 = 0;
	
	// create 2d error array
	const int array_num = 30;
	int error_array[2][array_num] = {{0}};

	// compute error array
    int temp_people = started_people;

	for(int i = 0; i < num_station + 1; i++){
		temp_people -= passenger[1][i];
        // cout << temp_people << "\n";
		if(temp_people < 0){
			error_array[0][i] = 1;
		}
		else{
			error_array[0][i] = 0;
		}	
		temp_people += passenger[0][i];
        // cout << temp_people << "\n";
		if(temp_people > limitation_passenger){
			error_array[1][i] = 1;
		}
		else{
			error_array[1][i] = 0;
		}	
	}

	// check condition (error_1 = location / error_2 = error type)
	for(int i = 0; i < num_station  + 1; i++){
		if(error_array[0][i] == 1 || error_array[1][i] == 1){ // get error location
			error_1 = i + 1;
			if(error_array[0][i] == 1 && error_array[1][i] == 0){ // only one error with N
				error_2 = 1;
			}	
			else if(error_array[0][i] == 0 && error_array[1][i] == 1){ // only one error with C
				error_2 = 2;
			}
			else if(error_array[0][i] == 1 && error_array[1][i] == 1){ // two error with B
				error_2 = 3;
			}
			else{
				error_2 = 0;
			}
			break;
		}
		else{
			error_1 = 0;
		}
	}
	
	// final check and output result
	if(error_1 == 0 && error_2 ==0){
		wrong_stationID = 0;	
	}
	if(error_1 > 0){
        wrong_stationID = error_1;
		if(error_2 == 1){
			wrong_type = 1;
		}
		if(error_2 == 2){
			wrong_type = 2;
		}
		if(error_2 == 3){
			wrong_type = 3;
		}
	}
}