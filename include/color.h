#ifndef COLOR_H
#define COLOR_H

#include <stdarg.h>
#include <stdint.h>

typedef struct style {
  uint8_t foreground;
  uint8_t background;
  uint8_t effects;
} Style;

int printfc(struct style s, const char *fmt, ...)
    __attribute__((format(printf, 2, 3)));

#endif
