#include <stdio.h>

int get_amount(void);
int cal_amount(int amount, int currency);

int main(void) {
  // Get the amount
  int amount = get_amount();

  int fifty = cal_amount(amount, 50);
  printf("50s: %d", fifty);
  printf("\n");
  amount -= (fifty * 50);

  int twenty = cal_amount(amount, 20);
  printf("20s: %d", twenty);
  printf("\n");
  amount -= (twenty * 20);

  int ten = cal_amount(amount, 10);
  printf("10s: %d", ten);
  printf("\n");

  return 0;
}

int cal_amount(int amount, int currency) {
  // Returns the number of times a bill is subtracted from the amount before
  // amount gets to zero
  int count = 0;
  while (amount >= currency) {
    amount -= currency;
    count++;
  }
  return count;
}

int get_amount(void) {
  int n;
  int status;

  do {
    printf("Enter an amount in multiples of 10: ");
    status = scanf("%d", &n);
    if (status != 1) {
      while (getchar() != '\n')
        ;
    }
  } while (status != 1 || n % 10 != 0);

  return n;
}
