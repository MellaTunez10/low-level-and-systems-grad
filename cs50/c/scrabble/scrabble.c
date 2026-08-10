#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_score(char *word);
void get_string(char *buffer, int max_size);

int POINTS[] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};

int main(void) {
  char player1[100], player2[100];

  printf("Player 1: ");
  get_string(player1, 100);

  printf("Player 2: ");
  get_string(player2, 100);

  int score1 = compute_score(player1);
  int score2 = compute_score(player2);

  if (score1 > score2) {
    printf("Player 1 wins!\n");
  } else if (score2 > score1) {
    printf("player 2 wins!\n");
  } else {
    printf("Tie!\n");
  }
  return 0;
}

void get_string(char *buffer, int max_size) {
  if (fgets(buffer, max_size, stdin) != NULL) {
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }
  }
}

int compute_score(char *word) {
  int sum = 0;

  for (int i = 0; word[i] != '\0'; i++) {
    if (isalpha(word[i])) {
      int index = toupper(word[i]) - 'A';
      sum += POINTS[index];
    }
  }
  return sum;
}
