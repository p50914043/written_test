#include <iostream>
using namespace std;

// 选择排序（Selection Sort）: 每轮找出最小的元素，放到已排序序列的末尾。
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

int main() {
  int arr[] = {1, 3, 2, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  selectionSort(arr, n);
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << std::endl;
  }
  return 1;
}