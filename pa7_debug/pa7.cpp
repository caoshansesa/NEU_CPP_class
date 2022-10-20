#include <stdio.h>
#include <stdlib.h>

#include <cstdio>

#define MAX_LETTERS 26

void initialize_alphabet(char *input_array) {
  char current_letter = 'a';
  for (int i = 0; i < MAX_LETTERS; i++) {
    *input_array++ = current_letter;
    current_letter++;
  }
}

bool print_direction = true;
void reverse_print_alpha(char *input_array) {
  printf("\nReverse alpha...\n");
  int init_aleady = 0;
  if (init_aleady == 0) {
    initialize_alphabet(input_array);
    init_aleady = 1;
  }
  if (print_direction == true) {
    for (int i = MAX_LETTERS + 1; i >= 0; --i) {
      printf("%c ", *(input_array + MAX_LETTERS - i));
    }
    printf("\n");

    print_direction = !print_direction;
  } else {
    for (int i = 0; i <= MAX_LETTERS; i++) {
      printf("%c ", *(input_array + MAX_LETTERS - i));
    }
    printf("\n");
    print_direction = !print_direction;
  }
  return;
}

int main(void) {
  int i = 0;
  char *alphabet = (char *)malloc(MAX_LETTERS);
  while (i++ < 5) {
    reverse_print_alpha(alphabet);
  }
  free(alphabet);
}
