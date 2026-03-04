#include <iostream>

void insert_sort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

int main() {
  int a[] = {3, 2, 1, 4, 5};
  int n = sizeof(a) / sizeof(a[0]);
  insert_sort(a, n);
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}