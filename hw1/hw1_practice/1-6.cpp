# include <iostream>

using namespace std;

int main(){
	int input;
	cin >> input;
	
	while(true){
		if(input % 2 == 0){
			input /= 2;
			cout << input << ",";
		}
		if(input % 2 != 0 && input != 1){
			input = input * 3 + 1;
			cout << input << ",";
	 	}
		if(input == 1){
		cout << 1;
		break;
		}
	}	

	return 0;
}
