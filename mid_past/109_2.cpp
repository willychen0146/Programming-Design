#include <iostream>
using namespace std;

int best_num(int, int, int*);

int main () {
  int hospital, raduis;
  cin >> hospital >> raduis;
  int* resident = nullptr;
  resident = new int[hospital];
  for (int i = 0; i < hospital; i++) {
    cin >> resident[i];
  }

  int result = best_num(hospital, raduis, resident);
  cout << result << endl;
  return 0;
}

int best_num(int hospital, int radius, int* resident){
  int result = -1;
  for (int i = 0; i < hospital; i++) {
    int temp = resident[i];
    int j = i - 1;
    int k = i + 1;
    while(i - j <= radius && j >= 0){ 
      temp += resident[j];
      j--;
    }
    while(k - i <= radius && k < hospital){ 
      temp += resident[k];
      k++;
    }
    if(temp > result)
      result = temp;
  }
  return result;
}
