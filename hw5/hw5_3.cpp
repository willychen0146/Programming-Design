#include <iostream>
#include <cstring> 
#define MAX_SIZE 10000
using namespace std;

bool is_punctuation(char ch);
void fix_sentence(char* str);

int main(){
    // get input
    char str[MAX_SIZE] = {0};
    cin.getline(str, MAX_SIZE);

    // fix the sentence
    fix_sentence(str);

    // create a pointer to the fixed sentence
    char* current = str;
    // Iterate through the characters in the fixed sentence and print them
    while (*current != '\0'){
        cout << *current; // Output the current character
        current++; // Move to the next character
    }
    return 0;
}

// Function to check if a character is a punctuation mark
bool is_punctuation(char ch){
    // Check if the character is one of the specified punctuation marks and return true if so, otherwise return false
    if (ch == ',' || ch == '.' || ch == '!' || ch == '(' || ch == ')'){
        return true;
    } else {
        return false;
    }
}

// Function to fix a sentence by adding spaces where necessary
void fix_sentence(char* str){
    char* current = str; // Create a pointer to the input string

    char output[MAX_SIZE] = {0}; // create an output character array to store the fixed sentence
    int count = 0; // initialize a count variable to keep track of the output array index

    // iterate through the characters in the input string
    while (*current != '\0'){
        char current_char = *current; // Get the current character
        char next_char = *(current + 1); // Get the next character
        bool is_next_char_punc = is_punctuation(next_char); // check if the next character is punctuation

        output[count++] = current_char; // add the current character to the output array

        // Check the current character for specific cases
        switch (current_char){
            case '.':
            case ',':
            case '!':
                // If the current character is a period, comma, or exclamation mark, check the next character
                // If the next character is not punctuation and not a space, add a space to the output array
                if (!is_next_char_punc && next_char != ' '){
                    output[count++] = ' ';
                }
                break;

            case ')':
                {
                    bool is_next_char_not_end = next_char != '\0';
                    // If the current character is a closing parenthesis and the next character is not the end of the string
                    // and the next character is not a space and not punctuation, add a space to the output array
                    if (is_next_char_not_end && next_char != ' ' && !is_next_char_punc){
                        output[count++] = ' ';
                    }
                }
                break;

            case '(':
                // If the current character is an opening parenthesis and the next character is a space, skip the space
                if (next_char == ' '){
                    current++;
                }
                break;

            case ' ':
                // If the current character is a space and the next character is punctuation (except an opening parenthesis)
                // reduce the count to remove the space
                if (is_next_char_punc && next_char != '('){
                    count--;
                }
                break;

            default:
                // For all other characters, if the current character is not a space and the next character is an opening parenthesis
                // add a space to the output array
                if (current_char != ' ' && next_char == '('){
                    output[count++] = ' ';
                }
                break;
        }

        current++; // move to the next character in the input string
    }

    // copy the fixed sentence from the output array back to the input string and null-terminate it
    strncpy(str, output, count);
    str[count] = '\0';
}