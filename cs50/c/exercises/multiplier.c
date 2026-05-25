#include <stdio.h>

int get_number(void);
int multiply_even(int n);

int main(void) {
  int number;
  int sum_of_even;

  number = get_number();
  sum_of_even = multiply_even(number);

  printf("The sum of the even numbers is %d", sum_of_even);
  printf("\n");
}

int multiply_even(int n) {
  int sum = 0;
  int current;
  while (n > 0) {
    current = n % 10;
    if (current % 2 == 0) {
      sum += current;
    }
    n /= 10;
  }
  return sum;
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
  } while (status != 1);
  return n;
}
