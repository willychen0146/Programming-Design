#include<iostream>
#include<cstring>
#define MAX_NUM 100
#define MAX_SIZE 1000

using namespace std;

int count = 0;

void str_num_to_int_array(char* input_str, int* num_array);
void bubble_sort(int* num_array, int total_num);

int main(){
    int total_num;
    int num_array[MAX_NUM] = {0};
    char input_str[MAX_SIZE] = {0};
    char temp[2] = {0};

    // get input
    cin >> total_num;
    // handle the cin /n issue
    cin.getline(temp, 2);
    cin.getline(input_str, MAX_SIZE - 1);

    // transform the str_num input int_array
    str_num_to_int_array(input_str, num_array);

    // sort the array
    bubble_sort(num_array, total_num);

    // second large number is the index = total_num - 2 (index from 0 to total_num - 1)
    // output the second large number
    cout << num_array[total_num - 2] << endl;

    return 0;
}


void str_num_to_int_array(char* input_str, int* num_array){
    int count = 0;
    int number = -1;
    char* word = strtok(input_str, ",");
    while (word != nullptr) {
        number = atoi(word); // exchange the str with corresponding int
        num_array[count] = number; // put corresponding int into num_array
        word = strtok(nullptr, ","); // erase the pointer to tell the function to move to the next word
        count++;
    }
}

void bubble_sort(int* num_array, int total_num){
    int temp;
    int swapped;

    for (int i = 0; i < total_num - 1; i++) {
        swapped = 0; 
        for (int j = 0; j < total_num - i - 1; j++) {
            if (num_array[j] > num_array[j + 1]) {
                // switch array[j] and array[j+1]
                temp = num_array[j];
                num_array[j] = num_array[j + 1];
                num_array[j + 1] = temp;
                swapped = 1; // switch happen
            }
        }

        // if switch not happen, the sorting is complete
        if (swapped == 0) {
            break;
        }
    }
}