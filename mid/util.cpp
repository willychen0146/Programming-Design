#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

// n = 要排序數量
void bubble_sort(int array[], int n);
void bubble_sort(int array[], int n) {
    int temp;
    int swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = 0; 
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // switch array[j] and array[j+1]
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1; // switch happen
            }
        }

        // if switch not happen, the sorting is complete
        if (swapped == 0) {
            break;
        }
    }
}
// binary_search
bool binary_search(int array[], int input, int lower_bound, int upper_bound);
bool binary_search(int array[], int input, int lower_bound, int upper_bound) {
    if (lower_bound > upper_bound) {
        return false; // Element not found
    }

    int mid = (lower_bound + upper_bound) / 2;

    if (input == array[mid]) {
        return true; // Element found
    } else if (input < array[mid]) {
        return binary_search(array, input, lower_bound, mid - 1);
    } else {
        return binary_search(array, input, mid + 1, upper_bound);
    }
}
// remove_punctuation
void remove_punctuation(char text_string[]) {
    int j = 0;

    for (int i = 0; text_string[i] != '\0'; i++) {
        if (isalnum(text_string[i]) || text_string[i] == ' ') {
            text_string[j++] = text_string[i];
        }
    }
    text_string[j] = '\0';  // Null-terminate the new string.
}
// 字串轉小寫
void all_to_lower(char text_string[]){
    for(int i = 0; i < strlen(text_string); i++){
        text_string[i] = tolower(text_string[i]);
    }
}
// 找某些字句出現多少次
int search_count(char keyword[], char text_string[]) {
    if (keyword == nullptr || text_string == nullptr) {
        return -1; // Indicate an error (e.g., by returning -1)
    }
    all_to_lower(keyword);
    all_to_lower(text_string);
    char* character_pointer = text_string;
    int count = 0;
    while ((character_pointer = strstr(character_pointer, keyword)) != nullptr) {
        count++;
        character_pointer++;
    }
    return count;
}
// 看是不是標點符號
bool is_punctuation(char ch) {
    if (ch == ',' || ch == '.' || ch == '!' || ch == '(' || ch == ')') {
        return true;
    } else {
        return false;
    }
}
// 轉英文字串變數字
int en_string_to_num(const char* word);
int en_string_to_num(const char* word) {
    if (strcmp(word, "zero") == 0){
        return 0;
    }
    if (strcmp(word, "one") == 0){
        return 1;
    } 
    if (strcmp(word, "two") == 0){
        return 2;
    } 
    if (strcmp(word, "three") == 0){
        return 3;
    } 
    if (strcmp(word, "four") == 0){
        return 4;
    } 
    if (strcmp(word, "five") == 0){
        return 5;
    } 
    if (strcmp(word, "six") == 0){
        return 6;
    } 
    if (strcmp(word, "seven") == 0){
        return 7;
    } 
    if (strcmp(word, "eight") == 0){
        return 8;
    } 
    if (strcmp(word, "nine") == 0){
        return 9;
    } 
    
    return -1; // If the word is invalid, return -1
}
// ??
void str_num_to_int_array(char* input_str, int* num_array);
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
// insertion sort
void insertionSort(int*, int);
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}
// 找出第二個出現的負數位置
int sec_neg_pos(int, int*);
int sec_neg_pos(int total_num, int* num_array){
  int position = 0, count = 0;
  for (int i = 0; i < total_num; i++) {
    if(num_array[i] < 0){
      position = i + 1;
      count++;
      if(count == 2){
        break;
      }
    }
  }
  return position;
}
// 找出指定第幾個出現的負數位置
int find_chosen_pos(int, int*, int);
int find_chosen_pos(int total_num, int* num_array, int chosen){
  int position = -1, count = 0, loop_count = 0;
  for (int i = 0; i < total_num; i++) {
    if(num_array[i] < 0){
      position = i;
      count++;
      if(count == chosen){
        break;
      }
    }
  }
  if(position == -1)
    return -1;
  else
    return position;
}
// 看數字重疊次數
int find_overlap(int, int** time_array, int** num_array);
int find_overlap(int total_num, int** time_array, int** num_array){
  int overlap = 0, loop = 0;
  for (int i = 0; i < total_num-1; i++) {
    for(int j = i+1; j < total_num; j++){
       if (num_array[i][0] < num_array[j][1] && num_array[i][1] > num_array[j][0]){
         overlap++;
       }
    }
  }
  return overlap;
}
// 小時+分鐘轉分鐘
void time_to_num(int, int** time_array, int** num_array);
void time_to_num(int total_num, int** time_array, int** num_array){
    for (int i = 0; i < total_num; i++) {
        num_array[i][0] = time_array[i][0]*60 + time_array[i][1];
        num_array[i][1] = time_array[i][2]*60 + time_array[i][3];
    }
}

int main () {
  int x, y, z, mid = 0;
  cin >> x >> y >>z;
  if(x>=y && y>= z || z>=y && y>= x)
    mid = y;
  else if(y>=x && x>= z || z>=x && x>= y)
    mid = x;
  else {
    mid = z;
  }
  cout << mid <<endl;
  return 0;
}
// 看3個數字的相同關係
int identical(int, int, int);
int identical(int x, int y, int z){
    int result = 0;
    if(x == y && y == z){
        result = 1;
    }
    else if(x != y && y != z && x != z){
        result = 2;
    }
    else if(x == y && y != z || x == z && y != z || y == z && x != z){
        result = 3;
    }
    else{
        result = 0;
    }
    return result;
}
// 比較沒用
int plus_or_what(int x, int y);
int plus_or_what(int x, int y){
    int result = 0;
    if(x == y){
        if(x < 0 && y < 0)
            result = x * y;
        if(x >= 0 && y >= 0)
            result = x + y;
    }
    else{
        result = x - y;
    }
    return result;
}
// 找1個array中最小的值
int find_min(int*, int);
int find_min(int* array, int len){
    int min = 0;
    min = array[0];
    for(int i = 1; i < len; i++){
        if(array[i] < min)
            min = array[i];
    }
    return min;
}
