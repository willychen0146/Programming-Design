#include <iostream>

using namespace std;

int min(int a, int b);

int main(){
	int a, b;
	cin >> a >> b;	
	cout << min(a, b) << "\n";		

	return 0;
}


int min(int a, int b){
	if(a > b){
		return b;
	}
	else {
		return a;
	}
}
