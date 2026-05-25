#include <stdio.h>

int calculate_currency(int change, int currency);
int get_change(void);

int main(void) {
  int total_count = 0;
  int change = get_change();

  int quaters = calculate_currency(change, 25);
  total_count += quaters;
  change -= (quaters * 25);

  int dimes = calculate_currency(change, 10);
  total_count += dimes;
  change -= (dimes * 10);

  int nickels = calculate_currency(change, 5);
  total_count += nickels;
  change -= (nickels * 5);

  total_count += change;

  printf("%i", total_count);
  printf("\n");
}

int calculate_currency(int change, int currency) {

  int count = 0;

  while (change >= currency) {
    change -= currency;
    count++;
  }
  return count;
}

int get_change(void) {
  int n;
  int status;

  do {
    printf("Change owed: ");
    status = scanf("%d", &n);
    if (status != 1) {
      while (getchar() != '\n')
        ;
    }
  } while (status != 1 || n < 1);

  return n;
}
