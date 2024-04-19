#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

#include "color.h"

#define ESC "\x1b"
#define SEPARATOR "["
#define TERMINATOR "m"
#define RESET_VALUE "0"
#define OFF ESC SEPARATOR RESET_VALUE TERMINATOR

#define BGDIFF 10
#define GETBIT(B, P) (((B) >> (P)) & 1)

enum effects {
  _BOLD,      // \x1b[1m
  _DIM,       // \x1b[2m
  _ITALIC,    // \x1b[3m
  _UNDERLINE, // \x1b[4m
  _BLINKING,  // \x1b[5m
  // NONE
  _REVERSE,  // \x1b[7m
  _HIDDEN,   // \x1b[8m
  _CROSSOUT, // \x1b[9m
};

static int apply_color(struct style *s) {
  int written_bytes = 0;
  written_bytes += printf(ESC SEPARATOR "%u" TERMINATOR, s->foreground);
  written_bytes +=
      printf(ESC SEPARATOR "%u" TERMINATOR, s->background + BGDIFF);

  return written_bytes;
}

static int apply_effects(struct style *s) {
  int written_bytes = 0;

  int totalbits = sizeof(s->effects) * CHAR_BIT;
  for (int i = 0; i < totalbits; i++) {
    if (GETBIT(s->effects, i)) {
      switch (i) {
        case _BOLD:
          written_bytes = printf(ESC SEPARATOR "%u" TERMINATOR, _BOLD + 1);
          break;
        case _DIM:
          written_bytes = printf(ESC SEPARATOR "%u" TERMINATOR, _DIM + 1);
          break;
        case _ITALIC:
          written_bytes = printf(ESC SEPARATOR "%u" TERMINATOR, _ITALIC + 1);
          break;
        case _UNDERLINE:
          written_bytes = printf(ESC SEPARATOR "%u" TERMINATOR, _UNDERLINE + 1);
          break;
        case _BLINKING:
          written_bytes = printf(ESC SEPARATOR "%u" TERMINATOR, _BLINKING + 1);
          break;
        case _REVERSE:
          written_bytes = printf(ESC SEPARATOR "%u" TERMINATOR, _REVERSE + 2);
          break;
        case _HIDDEN:
          written_bytes = printf(ESC SEPARATOR "%u" TERMINATOR, _HIDDEN + 2);
          break;
        case _CROSSOUT:
          written_bytes = printf(ESC SEPARATOR "%u" TERMINATOR, _CROSSOUT + 2);
          break;
      }
    }
  }

  return written_bytes;
}

int printfc(struct style *s, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);

  int written_bytes = 0;
  written_bytes += apply_color(s);
  written_bytes += apply_effects(s);
  written_bytes += vprintf(fmt, args);
  written_bytes += printf(OFF);

  va_end(args);
  return written_bytes;
}
