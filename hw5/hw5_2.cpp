#include <iostream>
#include <cctype>
#include <cstring>
#define MAX_TEXT_STRING 100

using namespace std;

int en_string_to_num(const char* word);

int main(){
    // get input
    int number;
    char text_string[MAX_TEXT_STRING] = {0};
    cin.getline(text_string, MAX_TEXT_STRING - 1);

    // split the text_string using ","
    // when strtok cannot find more delimiters, it returns nullptr, which means there are no more substrings to process
    char* word = strtok(text_string, ",");  // return search result(word's pointer) or nullptr
    // if found
    while (word != nullptr) {
        number = en_string_to_num(word);
        if (number != -1) {
            cout << number;
        }
        word = strtok(nullptr, ","); // erase the pointer to tell the function to move to the next word
        // if next word exist --> cout ","
        if (word != nullptr) {
            cout << ",";
        }
    }

    cout << endl;
    return 0;
}

// convert english words to corresponding numbers
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
