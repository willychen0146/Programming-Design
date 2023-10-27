#include<iostream>
#include<cctype>
#include<cstring>
#define MAX_KEYWORD 101
#define TEXT_STRING 1001

using namespace std;

void all_to_lower(char text_string[]);
int search_count(char keyword[], char text_string[]);

int main(){
    // get input
    char keyword[MAX_KEYWORD] = {0}; // key word I want to search
    char text_string[TEXT_STRING] = {0}; // target
    cin.getline(keyword, MAX_KEYWORD);
    // handle cin /n issue
    cin.getline(text_string, TEXT_STRING);
    // cout << key_word << endl;
    // cout << text_string << endl;

    // output result
    cout << search_count(keyword, text_string);
    return 0;
}

void all_to_lower(char text_string[]){
    for(int i = 0; i < strlen(text_string); i++){
    text_string[i] = tolower(text_string[i]);
    }  
}

int search_count(char keyword[], char text_string[]){
    char* character_pointer = text_string; // point to text_string first word
    // let the word all be lower
    all_to_lower(keyword);
    all_to_lower(text_string);
    // cout << "lower: " << key_word << endl;
    // cout << "lower: " << text_string << endl;

    // Find the number of times key_word appears in text_string
    int count = 0;
    while ((character_pointer = strstr(character_pointer, keyword)) != nullptr){
        count++;
        character_pointer++; // Move to the next character in the text_string
    }
    return count;
}