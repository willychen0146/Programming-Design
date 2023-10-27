#include <iostream>

using namespace std;

int main(){
	int age, gender;
	cin >> gender;
	cin >> age;
	if(age >= 18 && gender == 1){
		cout << "Yes";
	}
	else if(age < 18 && gender == 1){
		cout << "No";
	}	
	if(age >= 16 && gender == 0){
		cout << "Yes";
	}	
	else if(age < 16 && gender == 0){
		cout << "No";
	}	
	return 0;
}
