#include <iostream>
using namespace std;

int what_shape(int*, int*, int*, int*);

int main () {
  int point1[2] = {0};
  cin >> point1[0] >> point1[1];
  int point2[2] = {0};
  cin >> point2[0] >> point2[1];
  int point3[2] = {0};
  cin >> point3[0] >> point3[1];
  int point4[2] = {0};
  cin >> point4[0] >> point4[1];

  int result = what_shape(point1, point2, point3, point4);
  cout << result;
  return 0;
}

int what_shape(int* point1, int* point2, int* point3, int* point4){
  int shape = -1;
  if(point1 - point2 == 0 || point1 - )
  return shape;
}
