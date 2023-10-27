#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

int main(){
	int count = 0; 
	int temp = 0;
	char sentance[1000 + 1] = {0};
	cin.getline(sentance, 1000);
	for(int i = 0; i < strlen(sentance); i++){
		if(ispunct(sentance[i]) != 0){
			count++;
		}
	}
	cout << count;
	return 0;
}
