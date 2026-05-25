#include <stdio.h>

void print_bricks(int n);

int get_number(void);

int main(void) {
  int n = get_number();

  print_bricks(n);
}

void print_bricks(int n) {
  // loop through each row
  for (int row = 0; row < n; row++) {
    // loop through and print spaces before the bricks
    for (int spaces = 0; spaces < n - row - 1; spaces++) {
      printf(" ");
    }
    // Loop and print left bricks
    for (int left = 0; left <= row; left++) {
      printf("#");
    }
    // print the spaces in between
    printf("  ");

    // print the right side
    for (int right = 0; right <= row; right++) {
      printf("#");
    }
    // Move to the next row
    printf("\n");
  }
}

int get_number(void) {
  int n;
  int status;

  do {
    printf("Height: ");
    status = scanf("%d", &n);
    if (status != 1) {
      while (getchar() != '\n')
        ;
    }
  } while (status != 1 || (n < 1 || n > 8));
  return n;
}
