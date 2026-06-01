#include <ctype.h>
#include <stdio.h>
#include <string.h>

void get_word(char *buffer, int max_size);
int compute_score(char *word);

int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void) {
  // Prompt the players for words
  char player1[100], player2[100];

  // Player 1
  printf("Player 1: ");
  get_word(player1, 100);
  // Player 2
  printf("Player 2: ");
  get_word(player2, 100);

  int score1 = compute_score(player1);
  int score2 = compute_score(player2);

  if (score1 > score2) {
    printf("Player 1 wins!");
  } else if (score2 > score1) {
    printf("Player 2 wins!");
  } else {
    printf("Tie!");
  }
  printf("\n");

  return 0;
}

int compute_score(char *word) {
  int score = 0;
  // Loop through the word
  for (int i = 0; word[i] != '\0'; i++) {
    // If character is an alphabet
    if (isalpha(word[i])) {
      int index = toupper(word[i]) - 'A';
      score += POINTS[index];
    }
  }
  return score;
}

void get_word(char *buffer, int max_size) {

  // Read the line safely from standard input
  if (fgets(buffer, max_size, stdin) != NULL) {

    // Clear the newline at the end of the string
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }
  }
}
