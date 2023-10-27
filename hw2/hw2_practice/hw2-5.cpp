#include <iostream>

using namespace std;

int high_grade_count(int a, int b, int grade_list[]);
int row_of_high_grade(int a, int b, int c, int grade_list[][50]);

int main(){
	int total_row, total_num, threshold, temp;
	cin >> total_row >> total_num >> threshold;
	int grade_list[2][50] = {0};
	cout << row_of_high_grade(total_row, total_num, threshold, grade_list) << "\n";
	return 0;
}


int gcd(int a, int b){
	while(a != 0 && b != 0){
		if(a > b){
			a %= b;
		}	
		else {
			b %= a;
		}	
	}
	if(a == 0){
		return b;
	}
	else{
		return a;
	}
}

int high_grade_count(int total_num, int threshold, int grade_list[]){
	int count = 0;
	int temp;
	for(int i = 0; i < total_num; i++){
		cin >> temp;
		grade_list[i] = temp;
	}
	for(int i = 0; i < total_num; i++){
		if(grade_list[i] > threshold){
			count += 1;
		}
	}
	return count;
}

int row_of_high_grade(int total_row, int total_num, int threshold, int grade_list[][50]){
	int count = 0;
	int temp;
	for(int i = 0; i < total_row; i++){
		for(int j = 0; j < total_num; j++){
			cin >> temp;
			grade_list[i][j] = temp;
		}	
	}

	temp = 0;
	for(int i = 0; i < total_row; i++){
		for(int j = 0; j < total_num; j++){
			if(grade_list[i][j] > threshold && grade_list > temp){
				temp = grade_list[i][j];
				count = i;
			} 	
		}
	}
	return count;
}
