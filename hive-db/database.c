#include "database.h"
#include <ctype.h>

// The actual engine logic for encryption
void encrypt_value(char *input, char *output, int key) {
  int i;

  for (i = 0; input[i] != '\0'; i++) {
    if (isupper(input[i])) {
      output[i] = ((input[i] - 'A' + key) % 26) + 'A';
    } else if (islower(input[i])) {
      output[i] = ((input[i] - 'a' + key) % 26) + 'a';
    } else {
      output[i] = input[i];
    }
  }
  output[i] = '\0';
}
