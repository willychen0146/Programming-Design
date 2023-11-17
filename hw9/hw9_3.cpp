#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

// function
void all_to_lower(string& str);
int dic_word_counting(string target, string dic[], int dic_count);

int main(){
    // initialize word count and dictionary count
    int word_count = -1;
    int dic_count = 0;
    
    // get target path and dictionary path and open them as object
    string target_path = "";
    cin >> target_path;
    string dic_path = "";
    cin >> dic_path;
    ifstream target_file(target_path);
    ifstream dic_file(dic_path);
    string target = "";

    // check if files are successfully opened
    if (target_file && dic_file){
        // get target text and make target text all to lower
        getline(target_file, target);
        all_to_lower(target);

        // get dictionary in piece and make dictionary words all to lower
        dic_file >> dic_count;
        string* dic = new string[dic_count];
        for (int i = 0; i < dic_count; i++){
            dic_file >> dic[i];
            all_to_lower(dic[i]);
        }

        // count occurrences of dictionary words in target text
        word_count = dic_word_counting(target, dic, dic_count);

        // release memory allocated for dictionary
        delete[] dic;
    }

    // close the 2 files
    target_file.close();
    dic_file.close();

    // output the result
    cout << word_count << endl;
    return 0;
}

// function: convert all characters in a string to lowercase
void all_to_lower(string& str){
    for (int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
}

// function: count occurrences of dictionary words in target text
int dic_word_counting(string target, string dic[], int dic_count){
    // initiate count and location
    int count = 0;
    size_t position = 0;

    // search the number of times a dictionary word appears in the target text
    for (int i = 0; i < dic_count; i++){
        // start searching for one dictionary word
        position = target.find(dic[i], position);
        // search util the text is end
        while (position != string::npos){
            // if found, record the start and end location
            int start_pos = position;
            int end_pos = position + dic[i].length() - 1;
            // Check if the substring is surrounded by punctuation or space, not by other english word
            if ((start_pos == 0 || ispunct(target[start_pos - 1]) || isspace(target[start_pos - 1])) &&
                (end_pos == target.length() - 1 || ispunct(target[end_pos + 1]) || isspace(target[end_pos + 1]))){
                count++;
            }
            // make the search position to the next position in the target text (next character)
            position = target.find(dic[i], position + 1);
        }
        // reset the position to 0 if this round's seaching is end
        position = 0;
    }

    return count;
}
