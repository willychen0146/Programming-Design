#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void naiveRN(int rn[], int n); 
void smartRN(int rn[], int n); 

int main()
{
  srand(time(nullptr));
  int n = 0;
  cin >> n; // only n <= RAND_MAX is okay (why?)
  int* rn = new int[n];
  for(int i = 0; i < n; i++)
    rn[i] = 0;

  // to illustrate the difference in efficiency, 
  // try n = 30000
  smartRN(rn, n);
  cout << "Smart algorithm completed\n";
  naiveRN(rn, n); 
  cout << "Naive algorithm completed\n";
  
/*  
  // to see the random numbers
  for(int i = 0; i < n; i++)
  {
    if(i % 1 == 0)
      cout << rn[i] << " ";
  }
*/  
  delete [] rn;
   
  return 0;
}

void naiveRN(int rn[], int n)
{
  int success = 0;
  while(success < n)
  {
    int r = rand() % n + 1; // Be careful! Only n <= RAND_MAX is okay
    bool exist = false;
    for(int j = 0; j < success; j++)
    {
      if(r == rn[j])
      {
        exist = true;
        break;
      }
    }
    if(exist == false)
    {
      if(success % 100 == 0)     // just to take a look 
        cout << success << " ";  // not required by the algorithm 
      rn[success] = r;
      success++; 
    }
  }
}

void smartRN(int rn[], int n)
{
  for(int i = 0; i < n; i++)
    rn[i] = i + 1;
  
  for(int i = 0; i < n; i++)
  {
    int r = rand() % n; // what if n > RAND_MAX?  
    int temp = rn[r];   // conceptually: r = (r / RAND_MAX) * n!  
    rn[r] = rn[i];      // don't forget casting between int and float/double 
    rn[i] = temp;
  }
}


