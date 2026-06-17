#include "database.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: ./hive-db set [key] [value] [cipher_key]\n");
    return 1;
  }

  if (strcmp(argv[1], "set") != 0) {
    printf("Error: Unknown command 's'. Use 'set'.\n");
    return 1;
  }

  for (int i = 0; i < (int)strlen(argv[4]); i++) {
    if (!isdigit(argv[4][i])) {
      printf("Error: Cipher key must be a pure integer.\n");
      return 1;
    }
  }

  DbRecord record;
  strncpy(record.key, argv[2], sizeof(record.key) - 1);
  int shift_key = atoi(argv[4]);

  // Call the function compiled out of database.c
  encrypt_value(argv[3], record.encrypted_value, shift_key);
  printf("\n--- HIVE-DB IN-MEMORY PARSE ---\n");
  printf("RECORD KEY     : %s\n", record.key);
  printf("RAW VALUE      : %s\n", argv[3]);
  printf("CIPHER RESULT  : %s\n", record.encrypted_value);
  printf("----------------------------------------\n");

  return 0;
}
