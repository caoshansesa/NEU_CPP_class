#include <stdio.h>

#include <cstdio>

#define MAX_LETTERS 26

char alphabet[MAX_LETTERS];

void initialize_alphabet(char *input_array) {
  char current_letter = 'a';
  for (int i = 0; i < MAX_LETTERS; i++) {
    input_array[i] = current_letter;
    current_letter++;
  }
}

void reverse_print_alpha(char *input_array) {
  printf("\nReverse alpha...\n");
  initialize_alphabet(input_array);
  for (int i = MAX_LETTERS +1; i > 0; --i) {
    printf("%c ", input_array[i-1]);
  }

  printf("\n");
  return;
}

int main(void) {
  int i = 0;
  while (i++ < 5) {
    reverse_print_alpha(alphabet);
  }
}
