#include <stdbool.h>
#include <stdio.h>

int NUMBERS[] = {3, 1, 7, 4, 0, 2, 5, 9, 8, 6};

void bubble(int *arr, int max_size);

int main(void) { bubble(NUMBERS, 10); }

void bubble(int *arr, int max_size) {

  bool swapped;

  for (int i = 0; i < max_size - 1; i++) {
    swapped = false;

    for (int j = 0; j < max_size - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }

  for (int i = 0; i < max_size; i++) {
    printf("%d ", arr[i]);
  }
}
