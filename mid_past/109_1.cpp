#include <iostream>
using namespace std;

void insertionSort(int*, int);

int main() {
  int array[3] = {0};
  for (int i = 0; i < 3; i++) {
    cin >> array[i];
  }
  insertionSort(array, 3);
  cout << array[1] << endl;
  return 0;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}
