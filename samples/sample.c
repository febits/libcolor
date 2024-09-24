#include <stdio.h>
#include <stdlib.h>

#include "color.h"

#define MSG "Hello, I'm Felipe!\n"

int main(void) {
  printf("\nNormal Default Colors:\n");
  printfc(STYLE(BLACK, 0, 0), MSG);
  printfc(STYLE(RED, 0, 0), MSG);
  printfc(STYLE(GREEN, 0, 0), MSG);
  printfc(STYLE(YELLOW, 0, 0), MSG);
  printfc(STYLE(BLUE, 0, 0), MSG);
  printfc(STYLE(MAGENTA, 0, 0), MSG);
  printfc(STYLE(CYAN, 0, 0), MSG);
  printfc(STYLE(WHITE, 0, 0), MSG);

  printf("\nNormal Bright Colors:\n");
  printfc(STYLE(BRIGHT_BLACK, 0, 0), MSG);
  printfc(STYLE(BRIGHT_RED, 0, 0), MSG);
  printfc(STYLE(BRIGHT_GREEN, 0, 0), MSG);
  printfc(STYLE(BRIGHT_YELLOW, 0, 0), MSG);
  printfc(STYLE(BRIGHT_BLUE, 0, 0), MSG);
  printfc(STYLE(BRIGHT_MAGENTA, 0, 0), MSG);
  printfc(STYLE(BRIGHT_CYAN, 0, 0), MSG);
  printfc(STYLE(BRIGHT_WHITE, 0, 0), MSG);

  printf("\nNormal Default Colors (Background):\n");
  printfc(STYLE(0, BLACK, 0), MSG OFF);
  printfc(STYLE(0, RED, 0), MSG OFF);
  printfc(STYLE(0, GREEN, 0), MSG);
  printfc(STYLE(0, YELLOW, 0), MSG);
  printfc(STYLE(0, BLUE, 0), MSG);
  printfc(STYLE(0, MAGENTA, 0), MSG);
  printfc(STYLE(0, CYAN, 0), MSG);
  printfc(STYLE(0, WHITE, 0), MSG);

  printf("\nNormal Bright Colors (Background):\n");
  printfc(STYLE(0, BRIGHT_BLACK, 0), MSG);
  printfc(STYLE(0, BRIGHT_RED, 0), MSG);
  printfc(STYLE(0, BRIGHT_GREEN, 0), MSG);
  printfc(STYLE(0, BRIGHT_YELLOW, 0), MSG);
  printfc(STYLE(0, BRIGHT_BLUE, 0), MSG);
  printfc(STYLE(0, BRIGHT_MAGENTA, 0), MSG);
  printfc(STYLE(0, BRIGHT_CYAN, 0), MSG);
  printfc(STYLE(0, BRIGHT_WHITE, 0), MSG);

  printf("\nText Effects:\n");
  printfc(STYLE(0, 0, BOLD), "BOLD: " MSG);
  printfc(STYLE(0, 0, DIM), "DIM: " MSG);
  printfc(STYLE(0, 0, ITALIC), "ITALIC: " MSG);
  printfc(STYLE(0, 0, UNDERLINE), "UNDERLINE: " MSG);
  printfc(STYLE(0, 0, BLINKING), "BLINKING: " MSG);
  printfc(STYLE(0, 0, REVERSE), "REVERSE: " MSG);
  printfc(STYLE(0, 0, HIDDEN), "HIDDEN: " MSG);
  printfc(STYLE(0, 0, CROSSOUT), "CROSSOUT: " MSG);

  FILE *f = fopen("/tmp/libcolor.tst", "w");
  fprintfc(f, STYLE(YELLOW, BLACK, BOLD | UNDERLINE), "Testing on STREAM...\n");

  fprintfc(f, STYLE(BLUE, WHITE, CROSSOUT | ITALIC),
           "Testing on STREAM 2...\n");
  fprintfc(f, STYLE(MAGENTA, CYAN, BLINKING | BOLD),
           "Testing on STREAM 3...");

  return EXIT_SUCCESS;
}
