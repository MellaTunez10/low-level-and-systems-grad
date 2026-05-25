#include <stdio.h>

void print_bricks(int n);
int get_number(void);

int main(void) {
  int height;
  // Prompt the user for the pyramid's height
  height = get_number();
  // Print a pyramid of that height
  print_bricks(height);
  return 0;
}

void print_bricks(int n) {
  for (int row = 0; row < n; row++) {
    for (int spaces = 0; spaces < n - row - 1; spaces++) {
      printf(" ");
    }
    for (int bricks = 0; bricks <= row; bricks++) {
      printf("#");
    }
    printf("\n");
  }
}

int get_number(void) {
  int n;
  int status;

  do {
    printf("height: ");
    status = scanf("%d", &n);
    if (status != 1) {
      while (getchar() != '\n')
        ;
    }
  } while (status != 1 || (n < 1 || n > 8));
  return n;
}
