# libcolor

libcolor is meant to be a library that gives an easy-to-use interface for printing different colors and styles on terminal.

Supported:
- 4-bit colors

Not supported yet:
- 8-bit colors
- 24-bit colors (Truecolor)

## Installation
```bash
git clone https://github.com/febits/libcolor
```
```bash
cd libcolor
```
```bash
make
```
```bash
sudo make install
```

## Usage

After the installation, you'll be able to access the `"color.h"` that lives in `/usr/include`. Remember to link your final executable binary with the libcolor using `-lcolor`.

The main header file `color.h` exposes two functions: `printfc` and `fprintfc`
```c
int printfc(struct style s, const char *fmt, ...)
    __attribute__((format(printf, 2, 3)));
```

```c
int fprintfc(FILE *stream, struct style s, const char *fmt, ...)
    __attribute__((format(printf, 3, 4)));
```

The `printfc` and `fprintfc` takes one especial argument: `struct style`
```c
typedef struct style {
  u8 foreground;
  u8 background;
  u8 effects;
} Style;
```

The `fprintfc` also takes the specific `STREAM` which is a `FILE *`.

Basically, all you need is fill up the members of that struct and pass through to `printfc`.

The `foreground` and `background` members support the following `enum` values which are in `color.h`:

Normal ones:
```
BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE.
```

Bright ones:
```
BRIGHT_BLACK, BRIGHT_RED, BRIGHT_GREEN, BRIGHT_YELLOW, 
BRIGHT_BLUE, BRIGHT_MAGENTA, BRIGHT_CYAN, BRIGHT_WHITE.
```

If you want to keep `foreground` or `background` as their default value, use `_DC(type)` macro. It takes the type of color: `FG` or `BG`. In other words, you must pass `_DC(type)` as the values. Notice that you also can specify the effects as default (none) by putting `0`.

```c
enum default_type { FG, BG };
```

```c
struct style s = {_DC(FG), _DC(BG), 0};
```

The field `effects` is a classical bit vector that you can merge the available values with `OR` operator:
- **BOLD**
- DIM
- *ITALIC*
- <u>UNDERLINE</u>
- <blink>BLINKING</blink>
- REVERSE
- HIDDEN
- ~~CROSSOUT~~

![**Example of my terminal**](https://i.imgur.com/Husu49J.png)

Let's suppose that you want a yellow foreground with bold, italic and cross-out:

```c
#include <color.h>

int main() {
    struct style s = {YELLOW, _DC(BG), BOLD | ITALIC | CROSSOUT};

    printfc(s, "POTATO BANANA %s\n", "ORANGE");

    return 0;
}
```

With `fprintfc`:

```c
#include <stdio.h>
#include <stdlib.h>
#include <color.h>

int main() {
    struct style s = {YELLOW, _DC(BG), BOLD | ITALIC | CROSSOUT};
    FILE *f = fopen("/tmp/libcolor.tst", "w");

    fprintfc(f, s, "POTATO BANANA %s\n", "ORANGE");

    return 0;
}
```

You can also use the available macro `STYLE_C`:

```c
#define STYLE_C(f, b, e) ((struct style){(f), (b), (e)})
```

```c
#include <color.h>

int main(void) {
  printfc(STYLE_C(YELLOW, _DC(BG), BOLD | ITALIC | CROSSOUT),
          "POTATO BANANA %s\n", "ORANGE");

  return 0;
}
```

## Samples

You can view a sample by running:
```bash
make samples
make run_samples
```
