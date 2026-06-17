#ifndef DATABASE_H
#define DATABASE_H

// Group the database record structure in the contract
typedef struct {
  char key[50];
  char encrypted_value[200];
} DbRecord;

// Declare the function signature so main.c knows it exists.
void encrypt_value(char *input, char *output, int key);

#endif // !DATABASE.H
