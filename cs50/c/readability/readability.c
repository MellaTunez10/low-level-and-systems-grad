#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int letters;
  int words;
  int sentences;
} Count;

void get_text(char *buffer, int max_size);
Count count_text(char *text);

int main(void) {
  char text[1000];

  // Prompt the user for some text
  printf("Text: ");
  get_text(text, 1000);

  // Count the number of letters, words and sentences in the text
  Count result = count_text(text);

  // Compute the Coleman-Liau index
  float L = ((float)result.letters / result.words) * 100;
  float S = ((float)result.sentences / result.words) * 100;

  int index = round(0.0588 * L - 0.296 * S - 15.8);

  // Print the grade level
  if (index < 1) {
    printf("Before Grade 1\n");
  } else if (index >= 16) {
    printf("Grade 16+\n");
  } else {
    printf("Grade %d\n", index);
  }
  return 0;
}

Count count_text(char *text) {
  Count result = {0, 0, 0};
  int in_word = 0;

  for (int i = 0; text[i] != '\0'; i++) {
    // 1. If it's a letter, count it and mark that we are inside a word
    if (isalpha(text[i])) {
      result.letters++;
      if (in_word == 0) {
        in_word = 1;
        result.words++;
      }
    }
    // 2. If it's a space, we are no longer inside a word
    else if (isspace(text[i])) {
      in_word = 0;
    }
    // 3. If it's a sentence closer, count it.
    // Note: Characters like numbers or internal punctuation (quotes, hyphens)
    // will safely drop through here and still be counted as part of a word if
    // needed!
    else {
      if (in_word == 0) {
        in_word = 1;
        result.words++;
      }
      if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
        result.sentences++;
      }
    }
  }
  return result;
}

void get_text(char *buffer, int max_size) {

  if (fgets(buffer, max_size, stdin) != NULL) {
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }
  }
}
