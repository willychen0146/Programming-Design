#include <iostream>

using namespace std;

int high_grade_count(int a, int b, int grade_list[]);

int main(){
	int total_num, threshold, temp;
	cin >> total_num >> threshold;
	int grade_list[total_num] = {0};
	cout << high_grade_count(total_num, threshold, grade_list) << "\n";
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

