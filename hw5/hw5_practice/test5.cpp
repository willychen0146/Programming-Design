#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

int main(){
	char sentance[1000 + 1];
	char store[100][50] ={{0}};
	cin.getline(sentance, 1000 + 1);
	int count = 0;
	while(true){
		store[count] = strtok(sentance, ' ');
		count++;
		if(strtok(sentance, ' ') == nullptr){
			break;
		}
	}
	return 0;
}
