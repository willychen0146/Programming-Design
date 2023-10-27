#include <iostream>
using namespace std;

int min(int, int); 
int gcd(int, int);
int gcdDivision(int, int);

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    cout << gcdDivision(a, b);
    return 0;
}

int min(int a, int b)
{
    return a <= b ? a : b; 
}

int gcd(int a, int b)
{
    int smaller = min(a, b);
    int bigger = a;
    if(smaller == a)
        bigger = b;
    
    for(int i = 1; i <= smaller; i++)
    {
        if(smaller % i == 0)
        {
            int maybeGcd = smaller / i;
            if(bigger % maybeGcd == 0)
                return maybeGcd;
        }
    }
}

int gcdDivision(int a, int b)
{
	int gcd = 1;
	while(true)
	{
		int smaller = min(a, b);
		
		bool findDivisor = false;
		// see if any number in 2, 3, 4, ... divides a and b
		for(int possibleDivisor = 2; possibleDivisor <= smaller; possibleDivisor++)
		{
			// if a divisor is found
			if(a % possibleDivisor == 0 && b % possibleDivisor == 0)
			{
				// multiply gcd by possibleDivisor
				gcd *= possibleDivisor;
				// replacement
				a = a / possibleDivisor;
				b = b / possibleDivisor; 
				// set the flag
				findDivisor = true;
			}
		}
		if(findDivisor == false)
			return gcd;
	}
}




















