#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

char *get_word(char *buffer, int max_size);
int compute_score(char *word);

int main(void) {
  char text1[100], text2[100];
  printf("Player 1: ");
  char *player1 = get_word(text1, 100);
  printf("Player 2: ");
  char *player2 = get_word(text2, 100);

  int score1 = compute_score(player1);
  int score2 = compute_score(player2);

  if (score1 > score2) {
    printf("Player 1 wins!\n");
  } else if (score2 > score1) {
    printf("Player 2 wins!\n");
  } else {
    printf("Tie!\n");
  }

  return 0;
}

char *get_word(char *buffer, int max_size) {

  if (fgets(buffer, max_size, stdin) == NULL) {
    return NULL; // return if it fails
  }

  int len = strlen(buffer);
  // replace the literal newline with '\0'
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
  }

  // return the memory address of the filled cup
  return buffer;
}

int compute_score(char *word) {
  int score = 0;

  for (int i = 0; word[i] != '\0'; i++) {
    if (isalpha(word[i])) {
      int index = toupper(word[i]) - 'A';
      score += POINTS[index];
    }
  }

  return score;
}
