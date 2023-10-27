# include <iostream>

using namespace std;

int main(){
	// get input 
	int num_station, started_people, limitation, temp;
	int error_1 = 0, error_2 = 0;
	cin >> num_station >> started_people >> limitation;
	
	// create 2d array
	int array_num = 50;
	int up_down_array[2][array_num] = {{0}};
	int error_array[2][array_num] = {{0}};

	// store up and down people into 2d array
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < num_station - 1; j++){
			cin >> temp;
			up_down_array[i][j] = temp;
		}
	}
/*	for(int i = 0; i < 2; i++){
		for(int j = 0; j < num_station - 1; j++){
			cout << up_down_array[i][j] << "\n\n";
		}
	}
*/
	// compute error array
	int temp_people = started_people;
	for(int i = 0; i < num_station - 1; i++){
		temp_people -= up_down_array[1][i];
		if(temp_people < 0){
			error_array[0][i] = 1;
		}
		else{
			error_array[0][i] = 0;
		}	
		temp_people += up_down_array[0][i];
		if(temp_people > limitation){
			error_array[1][i] = 1;
		}
		else{
			error_array[1][i] = 0;
		}	
		//cout << temp_people << "\n";
	}
/*	for(int i = 0; i < 2; i++){
		for(int j = 0; j < num_station - 1; j++){
			cout << error_array[i][j];
			cout << endl;
		}
	}
*/

	
	// check condition (error_1 = location / error_2 = error type)
	for(int i = 0; i < num_station - 1; i++){
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
		cout << 0;	
	}
	if(error_1 > 0){
		if(error_2 == 1){
			cout << error_1  << "," << "N";
		}
		if(error_2 == 2){
			cout << error_1 << "," << "C";
		}
		if(error_2 == 3){
			cout << error_1 << "," << "B";
		}
	}

	return 0;
}
