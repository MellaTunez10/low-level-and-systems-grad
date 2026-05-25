#include <stdio.h>

int get_number(void);

int main(void) {
  int number;
  // Ask the user for a number between 1 and 8
  number = get_number();

  for (int row = 1; row <= number; row++) {
    for (int col = 1; col <= number; col++) {
      if ((row == 1 || row == number) || (col == 1 || col == number)) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int get_number(void) {
  int n;
  int status;

  do {
    printf("Enter a number: ");
    status = scanf("%d", &n);
    if (status != 1) {
      while (getchar() != '\n')
        ;
    }
  } while (status != 1 || (n < 1 || n > 8));
  return n;
}
