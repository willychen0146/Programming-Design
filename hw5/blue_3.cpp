#include <iostream>
#include <cstring>
#define MAX_SIZE 10000
using namespace std;

bool is_punctuation(char ch) {
    if (ch == ',' || ch == '.' || ch == '!' || ch == '(' || ch == ')') {
        return true;
    } else {
        return false;
    }
}

void fix_sentence(char *str) {
    char *current = str;

    char output[MAX_SIZE] {0};
    int count = 0;

    while (*current != '\0') {
        char current_char = *current;
        char next_char = *(current + 1);
        bool is_next_char_punc = is_punctuation(next_char);

        output[count++] = current_char;

        switch (current_char) {
            case '.':
            case ',':
            case '!':
                if (!is_next_char_punc && next_char != ' ') {
                    output[count++] = ' ';
                }
                break;

            case ')':
                {
                    bool is_next_char_not_end = next_char != '\0';
                    if (is_next_char_not_end && next_char != ' ' && !is_next_char_punc) {
                        output[count++] = ' ';
                    }
                }
                break;

            case '(':
                if (next_char == ' ') {
                    current++;
                }
                break;

            case ' ':
                if (is_next_char_punc && next_char != '(') {
                    count--;
                }
                break;

            default:
                if (current_char != ' ' && next_char == '(') {
                    output[count++] = ' ';
                }
                break;
        }

        current++;
    }


    strncpy(str, output, count);
    str[count] = '\0';
}

int main() {
    char str[MAX_SIZE] = {0};
    cin.getline(str, MAX_SIZE);
    fix_sentence(str);

    char *current = str;
    while (*current != '\0') {
        cout << *current;
        current++;
    }
    return 0;
}