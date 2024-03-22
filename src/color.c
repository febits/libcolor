#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#include "color.h"

int printfc(struct style s, const char *fmt, ...) {
  return printf("\x1b[35mTesting\n");
}
