#include <setjmp.h>
#include <stdio.h>
#include <cmocka.h>
#include <stdlib.h>

#include "color.h"

#define LIBCOLOR_TEST_FILE "/tmp/libcolor.test"
#define FOREGROUND_BUFSIZE 25
#define BACKGROUND_BUFSIZE 25
#define EFFECTS_BUFSIZE 33

static int cmocka_setup(void **state) {
  FILE *f = fopen(LIBCOLOR_TEST_FILE, "w+");

  if (f == NULL) {
    return -1;
  }

  *state = f;
  return 0;
}

static int cmocka_teardown(void **state) {
  FILE *f = *state;
  fclose(f);
  return 0;
}

static void test_foreground_color(void **state) {
  char buf[FOREGROUND_BUFSIZE + 1] = {0};
  FILE *f = *state;

  int written_bytes = fprintfc(f, STYLE(RED, 0, 0), "TESTING");

  fseek(f, 0, SEEK_SET);
  fread(buf, sizeof(char), 25, f);
  assert_string_equal(buf, "\x1b[0m\x1b[31m\x1b[49mTESTING\x1b[0m");
  assert_int_equal(written_bytes, FOREGROUND_BUFSIZE);
}

static void test_background_color(void **state) {
  char buf[BACKGROUND_BUFSIZE + 1] = {0};
  FILE *f = *state;

  int written_bytes = fprintfc(f, STYLE(0, MAGENTA, 0), "TESTING");

  fseek(f, 0, SEEK_SET);
  fread(buf, sizeof(char), 25, f);
  assert_string_equal(buf, "\x1b[0m\x1b[39m\x1b[45mTESTING\x1b[0m");
  assert_int_equal(written_bytes, BACKGROUND_BUFSIZE);
}

static void test_effects(void **state) {
  char buf[EFFECTS_BUFSIZE + 1] = {0};
  FILE *f = *state;

  int written_bytes = fprintfc(f, STYLE(0, 0, ITALIC | BOLD), "TESTING");

  fseek(f, 0, SEEK_SET);
  fread(buf, sizeof(char), 33, f);
  assert_string_equal(buf,
                      "\x1b[0m\x1b[39m\x1b[49m\x1b[1m\x1b[3mTESTING\x1b[0m");
  assert_int_equal(written_bytes, EFFECTS_BUFSIZE);
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test_setup_teardown(test_foreground_color, cmocka_setup,
                                      cmocka_teardown),
      cmocka_unit_test_setup_teardown(test_background_color, cmocka_setup,
                                      cmocka_teardown),
      cmocka_unit_test_setup_teardown(test_effects, cmocka_setup,
                                      cmocka_teardown)};

  return cmocka_run_group_tests_name("Libcolor Tests", tests, NULL, NULL);
}
