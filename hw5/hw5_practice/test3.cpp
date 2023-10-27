#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

int main(){
	int count = 0; 
	char sentance_1[1000 + 1] = {0};
	char sentance_2[1000 + 1] = {0};
	cin.getline(sentance_1, 1000);
	cin.getline(sentance_2, 1000);
	for(int i = 0; i < strlen(sentance_1); i++){
		sentance_1[i] = tolower(sentance_1[i]);
	}
	for(int i = 0; i < strlen(sentance_2); i++){
		sentance_2[i] = tolower(sentance_2[i]);
	}
	if(strstr(sentance_1, sentance_2)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
