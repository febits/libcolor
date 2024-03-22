#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

#include "color.h"

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
