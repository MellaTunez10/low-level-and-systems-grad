#include <stdio.h>

int NUMBERS[] = {10, 4, 2, 8, 9, 6, 7, 3, 5, 1, 0};

void selection(int *arr, int size);

int main(void) {
  selection(NUMBERS, 11);
  return 0;
}

void selection(int *arr, int size) {

  for (int i = 0; i < size - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
  }
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
