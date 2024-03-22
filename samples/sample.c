#include <stdio.h>
#include <stdlib.h>

#include "color.h"

int main() {

  struct style s = {0};

  printfc(s, "Hello, my name is Felipe!\n");

  return EXIT_SUCCESS;
}
