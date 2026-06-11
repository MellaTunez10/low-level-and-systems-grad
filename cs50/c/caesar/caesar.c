#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_plaintext(char *buffer, int max_size);

int main(int argc, char *argv[]) {
  char text[1000];
  // Make sure program was run with just one command line argument
  if (argc != 2) {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  for (int i = 0; i < (int)strlen(argv[1]); i++) {
    if (!isdigit(argv[1][i])) {
      printf("Usage: ./caesar key\n");
      return 1;
    }
  }
  int key = atoi(argv[1]);
  printf("Plaintext: ");
  get_plaintext(text, 1000);

  for (int i = 0; text[i] != '\0'; i++) {
    if (isupper(text[i])) {
      char cipher_text = ((text[i] - 'A' + key) % 26) + 'A';
      printf("%c", cipher_text);
    } else if (islower(text[i])) {
      char cipher_text = ((text[i] - 'a' + key) % 26) + 'a';
      printf("%c", cipher_text);
    } else {
      printf("%c", text[i]);
    }
  }
  printf("\n");

  return 0;
}

void get_plaintext(char *buffer, int max_size) {
  if (fgets(buffer, max_size, stdin) != NULL) {
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }
  }
}
