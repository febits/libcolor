#include <stdio.h>
#include <stdlib.h>

#include "color.h"

#define MSG "\tHello, I'm Felipe!\n"

int main(void) {
  struct style s = {DEFAULT(FG), DEFAULT(BG), 0};

  printf(OFF "\nNormal Default Colors:\n");
  s.foreground = BLACK;
  printfc(&s, MSG);
  s.foreground = RED;
  printfc(&s, MSG);
  s.foreground = GREEN;
  printfc(&s, MSG);
  s.foreground = YELLOW;
  printfc(&s, MSG);
  s.foreground = BLUE;
  printfc(&s, MSG);
  s.foreground = MAGENTA;
  printfc(&s, MSG);
  s.foreground = CYAN;
  printfc(&s, MSG);
  s.foreground = WHITE;
  printfc(&s, MSG);

  printf(OFF "\nNormal Bright Colors:\n");

  s.foreground = BRIGHT_BLACK;
  printfc(&s, MSG);
  s.foreground = BRIGHT_RED;
  printfc(&s, MSG);
  s.foreground = BRIGHT_GREEN;
  printfc(&s, MSG);
  s.foreground = BRIGHT_YELLOW;
  printfc(&s, MSG);
  s.foreground = BRIGHT_BLUE;
  printfc(&s, MSG);
  s.foreground = BRIGHT_MAGENTA;
  printfc(&s, MSG);
  s.foreground = BRIGHT_CYAN;
  printfc(&s, MSG);
  s.foreground = BRIGHT_WHITE;
  printfc(&s, MSG);

  s.foreground = DEFAULT(FG);
  printf(OFF "\nNormal Default Colors (Background):\n");

  s.background = BLACK;
  printfc(&s, MSG);
  s.background = RED;
  printfc(&s, MSG);
  s.background = GREEN;
  printfc(&s, MSG);
  s.background = YELLOW;
  printfc(&s, MSG);
  s.background = BLUE;
  printfc(&s, MSG);
  s.background = MAGENTA;
  printfc(&s, MSG);
  s.background = CYAN;
  printfc(&s, MSG);
  s.background = WHITE;
  printfc(&s, MSG);

  printf(OFF "\nNormal Bright Colors (Background):\n");

  s.background = BRIGHT_BLACK;
  printfc(&s, MSG);
  s.background = BRIGHT_RED;
  printfc(&s, MSG);
  s.background = BRIGHT_GREEN;
  printfc(&s, MSG);
  s.background = BRIGHT_YELLOW;
  printfc(&s, MSG);
  s.background = BRIGHT_BLUE;
  printfc(&s, MSG);
  s.background = BRIGHT_MAGENTA;
  printfc(&s, MSG);
  s.background = BRIGHT_CYAN;
  printfc(&s, MSG);
  s.background = BRIGHT_WHITE;
  printfc(&s, MSG);

  s.background = DEFAULT(BG);

  printf(OFF "\nText Effects:\n");

  s.effects = BOLD;
  printfc(&s, MSG);
  s.effects = DIM;
  printfc(&s, MSG);
  s.effects = ITALIC;
  printfc(&s, MSG);
  s.effects = UNDERLINE;
  printfc(&s, MSG);
  s.effects = BLINKING;
  printfc(&s, MSG);
  s.effects = REVERSE;
  printfc(&s, MSG);
  s.effects = HIDDEN;
  printfc(&s, MSG);
  s.effects = CROSSOUT;
  printfc(&s, MSG);

  s.foreground = BRIGHT_YELLOW;
  s.background = DEFAULT(BG);
  s.effects = BOLD | ITALIC;

  printf(OFF "\nSome examples:\n");
  printfc(&s, MSG);

  s.foreground = MAGENTA;
  s.effects = CROSSOUT | BLINKING;

  printfc(&s, MSG);

  s.foreground = BRIGHT_GREEN;
  s.effects = DIM | UNDERLINE | CROSSOUT;

  printfc(&s, MSG);

  s.foreground = CYAN;
  s.effects = HIDDEN;

  printfc(&s, MSG);

  s.foreground = BLUE;
  s.background = BRIGHT_BLACK;
  s.effects = REVERSE;

  printfc(&s, MSG);

  s.foreground = YELLOW;
  s.background = BRIGHT_BLACK;
  s.effects = ITALIC | UNDERLINE;

  printfc(&s, MSG);

  s.foreground = BRIGHT_WHITE;
  s.effects = DIM;

  printfc(&s, MSG);

  s.foreground = BRIGHT_GREEN;
  s.effects = BOLD;

  printfc(&s, MSG);

  s.foreground = BRIGHT_BLUE;
  s.background = BLACK;
  s.effects = BOLD | ITALIC;

  printfc(&s, MSG);

  s.foreground = BRIGHT_RED;
  s.effects = BOLD | UNDERLINE;

  printfc(&s, MSG);

  s.foreground = BLACK;
  s.background = BRIGHT_WHITE;
  s.effects = BOLD | REVERSE;

  printfc(&s, MSG);

  return EXIT_SUCCESS;
}
