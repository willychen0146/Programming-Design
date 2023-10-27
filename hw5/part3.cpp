#include<iostream>
#include<cstring>
#define MAX_SIZE 10000
using namespace std;

void find_gramma_error(char* input_str, int* space, int& count);
void fix_gramma_error(char* input_str, int* space, int count);

int main(){
    int count = 0; // initiate the while count
    char input_str[MAX_SIZE] = {0};
    cin.getline(input_str,MAX_SIZE);
    // create the array to record what change has to be done
    int space[MAX_SIZE] = {0}; // 0: do nothing, 1: delete space, 2: add space
    // cout << "input:" << input_str << " end" << endl;

    find_gramma_error(input_str, space, count);
    // cout << "space: ";
    // for(int i = 0; i < count; i++){
    //     cout << space[i] << " " << input_str[i] << endl;
    // }
    // cout << endl;
    // cout << count << endl;

    fix_gramma_error(input_str, space, count);
    // cout << input_str << endl;
    return 0;
}

void fix_gramma_error(char* input_str, int* space, int count){
    for(int i = 0; i < count*2; i++){
        if(space[i] == 1){
            continue;
        }
        else if(space[i] == 2){
            cout << input_str[i] << " ";
        }
        else if(space[i] == 0){
            cout << input_str[i];
        }
        else if(space[i] == -1){
            // cout << input_str[i] << " ";
            cout << input_str[i];
            break;
        }
    }
    // cout << endl;
}

void find_gramma_error(char* input_str, int* space, int& count){
    char* current = input_str;
    while(*current != '\0'){
        // cout << count << *current << endl;
        if(*current == '.' || *current == ',' || *current == '!'){
            if(*(current - 1) == ' '){
                space[count - 1] = 1;
            }
            if(*(current + 1) != ' ' && count < MAX_SIZE - 1){
                space[count] = 2;
            }
        }
        else if(*current == '('){
            // cout << "(" << *current << *(current-1) << endl;
            if(*(current - 1) != ' '){
                space[count - 1] = 2;
            }
            if(*(current + 1) == ' ' && count < MAX_SIZE - 1){
                space[count + 1] = 1;
            }
        }
        else if(*current == ')'){
            if(*(current - 1) == ' '){
                space[count - 1] = 1;
            }
            if(*(current + 1) == ' ' && count < MAX_SIZE - 2){
                if(*(current + 2) ==  '.' || *(current + 2) == ',' || *(current + 2) == '!'){
                    space[count] = 2;
                }
            }
        }
        else if (*current == ' '){
            // Handle extra spaces between words
            if (*(current + 1) == ' ' || *(current + 1) ==  '.' || *(current + 1) == ',' || *(current + 1) == '!'){
                space[count] = 1; // Delete extra space
            }
        }
        current++;
        count++;
    }
    // return space;
    space[count-1] = -1;
}