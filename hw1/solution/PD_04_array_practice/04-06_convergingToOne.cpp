#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    
    while(true)
    {
        if(num % 2 == 1)
            num = num * 3 + 1;
        else
            num /= 2;
            
        if(num != 1)
            cout << num << ",";
        else
        {
            cout << 1;
            break;
        }
    }
    
    return 0;
}
