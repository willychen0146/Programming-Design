#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class CurrencyString{
private:
    int num;

public:
    CurrencyString() : num(0) {}
    CurrencyString(int n) : num(n) {}
    string getFormattedStr(bool commaSep, bool minusSign);
    int get_num(){return num;};
};

string CurrencyString::getFormattedStr(bool commaSep, bool minus_sign){
    string str = to_string(this->num);
    string result = "$";
    if(num < 0){
        str.erase(0, 1);
    }
    int len = str.length();

    int start_pos = len % 3;

    if(commaSep == true){
        if (start_pos == 1)
            result = result + str[0] + ",";
        else if (start_pos == 2)
            result = result + str.substr(0, 2) + ",";

        for (int i = start_pos; i < len; i += 3)
            result = result + str.substr(i, 3) + ",";        
    }
    else{
        if (start_pos == 1)
            result = result + str[0] + ".";
        else if (start_pos == 2)
            result = result + str.substr(0, 2) + ".";

        for (int i = start_pos; i < len; i += 3)
            result = result + str.substr(i, 3) + ".";       
    }

    result.erase(result.length() - 1);

    if(num < 0){
        if(minus_sign == true){
            result.insert(0, "-");
        }
        else{
            result.insert(0, "(");
            result.insert(result.length(), ")");
        }
    }

    return result;    
}

int main(){
    int num, which_punc, neg_type;
    bool comma, minus_sign;

    cin >> num >> which_punc >> neg_type;

    CurrencyString money = CurrencyString(num);

    comma = (which_punc == 1);
    minus_sign = (neg_type == 1);

    string result = money.getFormattedStr(comma, minus_sign);
    cout << result << endl;

    return 0;
}
