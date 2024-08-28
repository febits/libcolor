#include <stdio.h>
#include <stdlib.h>

#include "color.h"

#define MSG "\tHello, I'm Felipe!\n"

int main(void) {
  printf(OFF "\nNormal Default Colors:\n");
  printfc(STYLE_C(BLACK, _DC(BG), 0), MSG);
  printfc(STYLE_C(RED, _DC(BG), 0), MSG);
  printfc(STYLE_C(GREEN, _DC(BG), 0), MSG);
  printfc(STYLE_C(YELLOW, _DC(BG), 0), MSG);
  printfc(STYLE_C(BLUE, _DC(BG), 0), MSG);
  printfc(STYLE_C(MAGENTA, _DC(BG), 0), MSG);
  printfc(STYLE_C(CYAN, _DC(BG), 0), MSG);
  printfc(STYLE_C(WHITE, _DC(BG), 0), MSG);

  printf(OFF "\nNormal Bright Colors:\n");
  printfc(STYLE_C(BRIGHT_BLACK, _DC(BG), 0), MSG);
  printfc(STYLE_C(BRIGHT_RED, _DC(BG), 0), MSG);
  printfc(STYLE_C(BRIGHT_GREEN, _DC(BG), 0), MSG);
  printfc(STYLE_C(BRIGHT_YELLOW, _DC(BG), 0), MSG);
  printfc(STYLE_C(BRIGHT_BLUE, _DC(BG), 0), MSG);
  printfc(STYLE_C(BRIGHT_MAGENTA, _DC(BG), 0), MSG);
  printfc(STYLE_C(BRIGHT_CYAN, _DC(BG), 0), MSG);
  printfc(STYLE_C(BRIGHT_WHITE, _DC(BG), 0), MSG);

  printf(OFF "\nNormal Default Colors (Background):\n");
  printfc(STYLE_C(_DC(FG), BLACK, 0), MSG);
  printfc(STYLE_C(_DC(FG), RED, 0), MSG);
  printfc(STYLE_C(_DC(FG), GREEN, 0), MSG);
  printfc(STYLE_C(_DC(FG), YELLOW, 0), MSG);
  printfc(STYLE_C(_DC(FG), BLUE, 0), MSG);
  printfc(STYLE_C(_DC(FG), MAGENTA, 0), MSG);
  printfc(STYLE_C(_DC(FG), CYAN, 0), MSG);
  printfc(STYLE_C(_DC(FG), WHITE, 0), MSG);

  printf(OFF "\nNormal Bright Colors (Background):\n");
  printfc(STYLE_C(_DC(FG), BRIGHT_BLACK, 0), MSG);
  printfc(STYLE_C(_DC(FG), BRIGHT_RED, 0), MSG);
  printfc(STYLE_C(_DC(FG), BRIGHT_GREEN, 0), MSG);
  printfc(STYLE_C(_DC(FG), BRIGHT_YELLOW, 0), MSG);
  printfc(STYLE_C(_DC(FG), BRIGHT_BLUE, 0), MSG);
  printfc(STYLE_C(_DC(FG), BRIGHT_MAGENTA, 0), MSG);
  printfc(STYLE_C(_DC(FG), BRIGHT_CYAN, 0), MSG);
  printfc(STYLE_C(_DC(FG), BRIGHT_WHITE, 0), MSG);

  printf(OFF "\nText Effects:\n");
  printfc(STYLE_C(_DC(FG), _DC(BG), BOLD), "\tBOLD\t" MSG);
  printfc(STYLE_C(_DC(FG), _DC(BG), DIM), "\tDIM\t" MSG);
  printfc(STYLE_C(_DC(FG), _DC(BG), ITALIC), "\tITALIC\t" MSG);
  printfc(STYLE_C(_DC(FG), _DC(BG), UNDERLINE), "\tUNDERLINE\t" MSG);
  printfc(STYLE_C(_DC(FG), _DC(BG), BLINKING), "\tBLINKING\t" MSG);
  printfc(STYLE_C(_DC(FG), _DC(BG), REVERSE), "\tREVERSE\t" MSG);
  printfc(STYLE_C(_DC(FG), _DC(BG), HIDDEN), "\tHIDDEN\t" MSG);
  printfc(STYLE_C(_DC(FG), _DC(BG), CROSSOUT), "\tCROSSOUT\t" MSG);

  FILE *f = fopen("/tmp/libcolor.tst", "w");
  fprintfc(f, STYLE_C(YELLOW, BLACK, BOLD | UNDERLINE),
           "Testing on STREAM...\n");
  fprintfc(f, STYLE_C(BLUE, WHITE, CROSSOUT | ITALIC),
           "Testing on STREAM 2...");

  return EXIT_SUCCESS;
}
