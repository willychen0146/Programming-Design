# include <iostream>

using namespace std;

const int MAX_STATION_NUM = 20;

// Prototype function declare
int checkCorrectness(int num_station, int started_people, int limitation,  const int get_in_pass[], const int get_out_pass[]);

int main(){
    int num_station = 0, started_people = 0, limitation = 0, busNum = 0;
	int type1 = 0, type2 = 0, type3 = 0; // Declare and reset error type count
    int get_in_pass[MAX_STATION_NUM] = {0};
    int get_out_pass[MAX_STATION_NUM] = {0};

    cin >> num_station >> busNum >> limitation;
	
	// Start to compute different bus error (busNum)
	for(int i = 0; i < busNum; i++){
		cin >> started_people;
		for(int j = 1; j < num_station; j++){
			cin >> get_in_pass[j];
		}
		for(int k = 1; k < num_station; k++){
			cin >> get_out_pass[k];
		}

		// Function computing and return type of error (3 = B / 2 = C / 1 = N)
		int ret = checkCorrectness(num_station, started_people, limitation, get_in_pass, get_out_pass);
		if(ret == 3){
			type3++; // B
		}
		if(ret == 2){
			type2++; // C
		}
		if(ret == 1){
			type1++; // N
		}
	}

	cout << type1 << "," << type2 << "," << type3 << "\n";
    return 0;
}

// My function
int checkCorrectness(int num_station, int started_people, int limitation, const int get_in_pass[], const int get_out_pass[]){ 
	// Reset error type count
	int temp_people = 0, error_1 = 0, error_2 = 0;
	
	// Create 2d error array
	int array_num = 50;
	int error_array[2][array_num] = {{0}};

	// Compute error array
	temp_people = started_people;
	for(int i = 1; i < num_station; i++){
		temp_people -= get_out_pass[i];
		if(temp_people < 0){
			error_array[0][i] = 1;
		}
		else{
			error_array[0][i] = 0;
		}	
		temp_people += get_in_pass[i];
		if(temp_people > limitation){
			error_array[1][i] = 1;
		}
		else{
			error_array[1][i] = 0;
		}	
	}

	// Check condition (error_1 = error station / error_2 = error type)
	for(int i = 1; i < num_station; i++){
		if(error_array[0][i] == 1 || error_array[1][i] == 1){ 
			// Get error station
			error_1 = i; 
			if(error_array[0][i] == 1 && error_array[1][i] == 0){ // Only one error with N type
				error_2 = 1;
			}	
			else if(error_array[0][i] == 0 && error_array[1][i] == 1){ // Only one error with C type
				error_2 = 2;
			}
			else if(error_array[0][i] == 1 && error_array[1][i] == 1){ // Two error with B type
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
	
	// Final check and output result (Error station and error type, if doesn't appear any error --> return 0)
	if(error_1 == 0 && error_2 ==0){
		return 0;	
	}
	if(error_1 > 0){
		if(error_2 == 1){
			return 1; // Error N type
		}
		if(error_2 == 2){
			return 2; // Error C type
		}
		if(error_2 == 3){
			return 3; // Error B type
		}
	}

	// Add a default return statement for cases not handled above
    return -1; // In this case return -1 to indicate an error or invalid case
}
