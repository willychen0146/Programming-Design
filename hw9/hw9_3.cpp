#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

void all_to_lower(string &str);
int dic_word_counting(string target, string dic[], int dic_count);

int main(){
    // initiate the count
    int word_count = -1;
    int dic_count = 0;
    
    // get target path and dictionary path and open it as object
    string target_path = "";
    cin >> target_path;
    string dic_path = "";
    cin >> dic_path;
    ifstream target_file(target_path);
    ifstream dic_file(dic_path);
    string target = "";

    if (target_file && dic_file){
        // get target text
        getline(target_file, target);
        all_to_lower(target);
        // cout << target << endl;

        // get dictionary in piece
        dic_file >> dic_count;
        string* dic = new string[dic_count];
        for (int i = 0; i < dic_count; i++){
            dic_file >> dic[i];
            all_to_lower(dic[i]);
            // cout << dic[i] << endl;
        }

        word_count = dic_word_counting(target, dic, dic_count);

        delete[] dic;
    }

    // close the 2 files
    target_file.close();
    dic_file.close();

    // output the result
    cout << word_count << endl;
    return 0;
}

void all_to_lower(string &str){
    for (int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
}

bool is_valid_word_char(char c) {
    // Customize this function based on your requirements.
    // For example, you might want to consider letters and numbers as valid characters.
    return isalnum(c) || c == '_'; 
}

int dic_word_counting(string target, string dic[], int dic_count){
    int count = 0;
    size_t position = 0;

    for (int i = 0; i < dic_count; i++){
        position = target.find(dic[i], position);
        while (position != string::npos) {
            int start_pos = position;
            int end_pos = position + dic[i].length() - 1;
            // Check if the substring is surrounded by punctuation or whitespace
            if ((start_pos == 0 || ispunct(target[start_pos - 1]) || isspace(target[start_pos - 1])) &&
                (end_pos == target.length() - 1 || ispunct(target[end_pos + 1]) || isspace(target[end_pos + 1]))) {
                count++;
                // cout << dic[i] << endl;
                // cout << "Substring found at position: " << position << " to " << position + dic[i].length() - 1 << endl;
            }
            position = target.find(dic[i], position + 1);
        }
        position = 0;
    }

    return count;
}
