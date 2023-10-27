#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

int main(){
	int count = 0; 
	char sentance[1000 + 1] = {0};
	cin.getline(sentance, 1000);
	sentance[0] = toupper(sentance[0]);
	for(int i = 1; i < strlen(sentance); i++){
		if((sentance[i - 1]) == ' '){
			sentance[i] = toupper(sentance[i]);
		}
		else{
			sentance[i] = tolower(sentance[i]);
		}
	}
	cout << sentance;
	return 0;
}
