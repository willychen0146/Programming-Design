#include <iostream>
#include <cctype>
#include <cstring>
#define MAX_KEYWORD 101
#define TEXT_STRING 1001

using namespace std;

void all_to_lower(char text_string[])
{
    for(int i = 0; i < strlen(text_string); i++)
    {
        text_string[i] = tolower(text_string[i]);
    }
}

int search_count(char keyword[], char text_string[])
{
    char* character_pointer = text_string;
    all_to_lower(keyword);
    all_to_lower(text_string);

    int count = 0;
    while ((character_pointer = strstr(character_pointer, keyword)) != nullptr)
    {
        count++;
        character_pointer++;
    }
    return count;
}

int main()
{
    char keyword[MAX_KEYWORD] = {0};
    char text_string[TEXT_STRING] = {0};

    cin.getline(keyword, MAX_KEYWORD);
    cin.getline(text_string, TEXT_STRING);
    cout << search_count(keyword, text_string);
    return 0;
}
