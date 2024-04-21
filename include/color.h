#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>
#include <stdio.h>

#define ESC "\x1b"
#define SEPARATOR "["
#define TERMINATOR "m"
#define RESET_VALUE "0"
#define OFF ESC SEPARATOR RESET_VALUE TERMINATOR

#define FGDEFAULT 39
#define BGDEFAULT 49

#define DEFAULT(type) ((type) == FG ? FGDEFAULT : BGDEFAULT)

#define BOLD (1 << 0)
#define DIM (1 << 1)
#define ITALIC (1 << 2)
#define UNDERLINE (1 << 3)
#define BLINKING (1 << 4)
#define REVERSE (1 << 5)
#define HIDDEN (1 << 6)
#define CROSSOUT (1 << 7)

enum default_type { FG, BG };

enum colors {
  BLACK = 30,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE,
  BRIGHT_BLACK = 90,
  BRIGHT_RED,
  BRIGHT_GREEN,
  BRIGHT_YELLOW,
  BRIGHT_BLUE,
  BRIGHT_MAGENTA,
  BRIGHT_CYAN,
  BRIGHT_WHITE
};

typedef struct style {
  uint8_t foreground;
  uint8_t background;
  uint8_t effects;
} Style;

int printfc(struct style *s, const char *fmt, ...)
    __attribute__((format(printf, 2, 3)));

int fprintfc(FILE *stream, struct style *s, const char *fmt, ...)
    __attribute__((format(printf, 3, 4)));

#endif
