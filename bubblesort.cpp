#include <iostream>
using namespace std;
void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}
void bubbleSort(int a[], int n) { // the standard version
  for (; n > 0; --n) // N iterations
    for (int i = 0; i < n - 1; ++i) // except the last, O(N)
      if (a[i] > a[i + 1]) // not in non-decreasing order
        swap(a[i], a[i + 1]); // swap in O(1)
}
int main() {
  int a[4] = {1, 5, 9, 6};
  int n = sizeof(a)/ sizeof(int);
  bubbleSort(a, n);
  for(int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
