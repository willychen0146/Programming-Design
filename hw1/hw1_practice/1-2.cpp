# include <iostream>

using namespace std;

int main(){
	int years;
	cin >> years;
	if((years % 4) == 0 || (years % 400) == 0){
		if((years % 100) != 0){
		cout << "1";
		}
	}
	if((years % 4) != 0 && (years % 400) != 0){
		cout << "0";
	}
	if ((years % 100) == 0){
		cout << "0";
	}
	return 0;
}
