#include<iostream>

using namespace std;


int main(){
	int space = 0;
	cout << &space;
	for(int i = 0; i < 10; i++){
		int new_space = 0;
		cout << &new_space;
	}
	return 0;
}


/*
int main(){
	int a = 0, b = 0;
	cin >> a;
	cout << a;
	int* pt = &a;
	cin >> b;
	*pt = b;
	cout << a;
	return 0;
}
*/
/*
int maxPtr(int* a, int* b){
	return *a > *b ? a : b;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << *maxPtr(&a, &b);
	return 0;
}
*/


