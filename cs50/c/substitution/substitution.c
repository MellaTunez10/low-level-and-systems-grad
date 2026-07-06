#include <ctype.h>
#include <stdio.h>
#include <string.h>

void get_plaintext(char *buffer, int max_size);

int main(int argc, char *argv[]) {
  char text[1000];

  if (argc != 2) {
    printf("Usage: ./substitution key");
    return 1;
  }
  for (int i = 0; i < (int)strlen(argv[1]); i++) {
    if (!isalpha(argv[1]) || strlen(argv[1]) > 26) {
      printf("Usage: ./substitution key");
      return 1;
    }
  }
  printf("Plaintext: ");
  get_plaintext(text, 1000);
}

void get_plaintext(char *buffer, int max_size) {
  if (fgets(buffer, max_size, stdin) != NULL) {
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }
  }
}
