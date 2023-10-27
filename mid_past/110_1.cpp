#include <iostream>
using namespace std;

int main () {
  int x, y, z, mid = 0;
  cin >> x >> y >>z;
  if(x>=y && y>= z || z>=y && y>= x)
    mid = y;
  else if(y>=x && x>= z || z>=x && x>= y)
    mid = x;
  else {
    mid = z;
  }
  cout << mid <<endl;
  return 0;
}
