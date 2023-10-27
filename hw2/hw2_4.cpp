#include <iostream>
using namespace std;
const int MAX_STATION_NUM = 20;

// This is the prototype of the function you need to complete.
// 這是你需要完成的函數的 prototype
void checkCorrectness(int stationNum, int initPass, int maxPass, const int passenger[][20], int ret[]);

int main(){
    int stationNum = 0, initPass = 0, maxPass = 0;
    int passenger[2][MAX_STATION_NUM] = {0};
    int ret[2] = {0};
    cin >> stationNum >> initPass >> maxPass;
    // Please note that in the two loops below,
    // the boarding and alighting counts for the first stop are placed in the array's first element rather than the zeroth element.
    // The same applies to the subsequent stops.
    // 請注意在下面的兩個迴圈中，
    // 第一站的上下車人數放在陣列的第一個而非第零個元素。
    // 其他依此類推
    for(int i = 1; i < stationNum; i++){
        cin >> passenger[0][i];
    }
    for(int i = 1; i < stationNum; i++){
        cin >> passenger[1][i];
    }
    
    checkCorrectness(stationNum, initPass, maxPass, passenger, ret);

    if(ret[0] == 0){
        cout << ret[0];
    }
    else{
        if(ret[1] == 1){
            cout << ret[0] << ",N";
        }
        else if(ret[1] == 2){
            cout << ret[0] << ",C";
        }
        else if(ret[1] == 3){
            cout << ret[0] << ",B";
        }
    }
    
    return 0;
}

// After you upload the function you've written, PDOGS will paste the code you uploaded HERE and then compile it.
// 你上傳你寫的函數後，PDOGS 會把你上傳的程式碼貼在這裡，然後編譯

void checkCorrectness(int num_station, int started_people, int limitation, const int passenger[][MAX_STATION_NUM], int ret[]){ // int stationNum, int initPass, int maxPass, const int passenger[][MAX_STATION_NUM], int ret[]
	// get input 
	int temp;
	int error_1 = 0, error_2 = 0;
	
	// create 2d array
	int array_num = 50;
	//int up_down_array[2][array_num] = {{0}};
	int error_array[2][array_num] = {{0}};

	// compute error array
	int temp_people = started_people;
	for(int i = 1; i < num_station; i++){
		temp_people -= passenger[1][i];
		if(temp_people < 0){
			error_array[0][i] = 1;
		}
		else{
			error_array[0][i] = 0;
		}	
		temp_people += passenger[0][i];
		if(temp_people > limitation){
			error_array[1][i] = 1;
		}
		else{
			error_array[1][i] = 0;
		}	
	}

	// check condition (error_1 = location / error_2 = error type)
	for(int i = 1; i < num_station; i++){
		if(error_array[0][i] == 1 || error_array[1][i] == 1){ // get error location
			error_1 = i;
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
		ret[0] = 0;	
	}
	if(error_1 > 0){
		// error N
		if(error_2 == 1){
			ret[0] = error_1;
			ret[1] = 1;
		}
		// error C
		if(error_2 == 2){
			ret[0] = error_1;
			ret[1] = 2;
		}
		// error B
		if(error_2 == 3){
			ret[0] = error_1;
			ret[1] = 3;
		}
	}
}
