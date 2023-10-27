#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a = 0, b = 0; 
    cin >> a >> b;
    
    cout << a + b << "\n";
    cout << setprecision(10) << a + b << "\n" << a - b << "\n";
    
    if(a + b == 0.3)
        cout << "Yes!!\n";
    else
        cout << "No~~~~\n";
    
    return 0;
}
