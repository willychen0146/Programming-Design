#include <iostream>
using namespace std;

int main()
{
    int gender = 0, age = 0;
    cin >> gender >> age;
    
    if((gender == 1 && age >= 18) || (gender == 0 && age >= 16))
        cout << "Yes";
    else
        cout << "No"; 
    
    return 0;
}
