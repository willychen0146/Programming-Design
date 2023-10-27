#include <iostream>
using namespace std;

int min(int, int); 

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    cout << min(a, b);
    return 0;
}

int min(int a, int b)
{
    return a <= b ? a : b; 
}
