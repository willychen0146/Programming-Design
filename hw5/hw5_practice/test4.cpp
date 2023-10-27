#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

int main(){
	int sentance_num;
	cin >> sentance_num;
	char sentance[51] = {0};
	char** sentance_compute = new char*[sentance_num];
	cin >> sentance;
	for(int i = 0; i < sentance_num; i++){
		sentance_compute[i] = new char[51];
		cin >> sentance_compute[i];
	}

	// to lower case
	for(int i = 0; i < strlen(sentance); i++){
		sentance[i] = tolower(sentance[i]);
	}
	// compute
	int flag= 0;
	for(int i = 0; i < sentance_num; i++){
		if(strstr(sentance, sentance_compute[i]) != nullptr){
			cout << 1;
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		cout << 0;
	}
	return 0;
}
