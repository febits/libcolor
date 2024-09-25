# libcolor

libcolor is designed to be a library that gives an easy-to-use interface for printing different colors and styles.

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

## Samples and testing
```bash
make samples
```
```bash
make tests
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
  uint8_t foreground;
  uint8_t background;
  uint8_t effects;
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

The field `effects` is a classical bit vector that you can merge the available values with `OR` operator:
- **BOLD**
- DIM
- *ITALIC*
- <u>UNDERLINE</u>
- <blink>BLINKING</blink>
- REVERSE
- HIDDEN
- ~~CROSSOUT~~

Let's suppose that you want a yellow foreground with bold, italic and cross-out:

```c
#define STYLE(f, b, e) ((struct style){(f), (b), (e)})
```

```c
#include <color.h>

int main(void) {
  printfc(STYLE(YELLOW, 0, BOLD | ITALIC | CROSSOUT),
          "POTATO BANANA %s\n", "ORANGE");

  return 0;
}
```

> [!NOTE]
> Default values for the foreground, background, or effects must be set to `0`.
