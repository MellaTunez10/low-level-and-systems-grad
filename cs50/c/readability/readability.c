#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void get_text(char *buffer, int max_size);
int count_letters(char *text);
int count_words(char *text);
int count_sentences(char *text);

int main(void) {
  char text[1000];

  printf("Text: ");
  get_text(text, 1000);

  int letters = count_letters(text);
  int words = count_words(text);
  int sentences = count_sentences(text);

  float L = ((float)letters / words) * 100;
  float S = ((float)sentences / words) * 100;

  int result = round(0.0588 * L - 0.296 * S - 15.8);

  if (result < 1) {
    printf("Before Grade 1\n");
  } else if (result >= 16) {
    printf("Grade 16+\n");
  } else {
    printf("Grade %i\n", result);
  }
  return 0;
}

int count_letters(char *text) {
  int count = 0;
  for (int i = 0; text[i] != '\0'; i++) {
    if (isalpha(text[i])) {
      count++;
    }
  }
  return count;
}

int count_words(char *text) {
  if (strlen(text) == 0) {
    return 0;
  }
  int count = 1;

  for (int i = 0; text[i] != '\0'; i++) {
    if (isspace(text[i])) {
      count++;
    }
  }
  return count;
}

int count_sentences(char *text) {
  int count = 0;

  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
      count++;
    }
  }
  return count;
}

void get_text(char *buffer, int max_size) {

  if (fgets(buffer, max_size, stdin) != NULL) {
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }
  }
}
