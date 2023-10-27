#include <iostream> // not finish

using namespace std;

int binary_search(array[], input, lower_bound, upper_bound);

int main(){
	int array_num, input, output;
	int MAX_NUM = 10;
	cin << array_num << input;

	int array[MAX_NUM] = {0};
	for(int i = 0; i < array_num; i++){
		cin array[i];
	}

	output = binary_serach(array, input, 0, array_num)
	
	cout >> output;

	return 0;
}

bool binary_search(array[], input, lower_bound, upper_bound){
	int mid;
	mid = (lower_bound + upper_bound) / 2;
	if(input == array[mid]){
		return false;
	}
	else if(input < array[mid]){
		return binary_search(array[], input, lower_bound, mid);
	}
	else if(input > array[mid]){
		return binary_search(array[], input, mid, upper_bound);
	}
	else{
		return false;
	}
}
