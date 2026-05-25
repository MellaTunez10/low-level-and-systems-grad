#include <stdbool.h>
#include <stdio.h>

void print_brand(long n, int length);
long get_number(void);
int get_length(long n);
bool check_luhn(long n);

int main(void) {
  long card = get_number();
  if (!check_luhn(card)) {
    printf("INVALID\n");
    return 0;
  }

  int length = get_length(card);

  print_brand(card, length);
}

void print_brand(long n, int length) {
  // Get the first two digits
  long first_two = n;
  while (first_two > 100) {
    first_two /= 10;
  }
  int first_digit = first_two / 10;

  // The logic tree
  if (length == 15 && (first_two == 34 || first_two == 37)) {
    printf("AMEX\n");
  } else if (length == 16 && (first_two >= 51 && first_two <= 55)) {
    printf("MASTER\n");
  } else if ((length == 13 || length == 16) && first_digit == 4) {
    printf("VISA\n");
  } else {
    printf("INVALID\n");
  }
}

long get_number(void) {
  long n;
  int status;

  do {
    printf("Number: ");
    status = scanf("%ld", &n);
    if (status != 1) {
      while (getchar() != '\n')
        ;
    }
  } while (status != 1);
  return n;
}

int get_length(long n) {
  int count = 0;
  while (n > 0) {
    n /= 10;
    count++;
  }
  return count;
}

bool check_luhn(long n) {
  int sum = 0;
  bool multiply = false;

  while (n > 0) {
    int digit = n % 10;
    if (multiply) {
      int product = digit * 2;
      sum += (product / 10) + (product % 10);
    } else {
      sum += digit;
    }
    multiply = !multiply;
    n /= 10;
  }
  return (sum % 10 == 0);
}
