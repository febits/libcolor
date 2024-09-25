CC=gcc
CFLAGS=-Wall -Wextra -pedantic -I./include/
LDFLAGS=-L./build/ -lcolor

BUILDDIR=build
INSTALLDIR=/usr/lib
LIBNAME=libcolor.so
LIBHEADER=color.h

SRC=$(wildcard src/*.c)
LIB=$(BUILDDIR)/$(LIBNAME)

SRC_SAMPLE=$(wildcard samples/*.c)
BIN_SAMPLE=$(BUILDDIR)/sample

SRC_TEST=$(wildcard tests/*.c)
BIN_TEST=$(BUILDDIR)/test_libcolor

.PHONY: default tests samples install uninstall clean

default: always $(LIB) $(BIN_SAMPLE) $(BIN_TEST)

$(LIB): $(SRC)
	$(CC) $(CFLAGS) -shared -fPIC $^ -o $@

$(BIN_SAMPLE): $(SRC_SAMPLE)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BIN_TEST): $(SRC_TEST)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) -lcmocka

samples:
	LD_LIBRARY_PATH=$(BUILDDIR) $(BIN_SAMPLE)

tests:
	LD_LIBRARY_PATH=$(BUILDDIR) $(BIN_TEST)

always:
	mkdir -p $(BUILDDIR)

install: $(LIB)
	cp $(LIB) $(INSTALLDIR)
	cp include/$(LIBHEADER) /usr/include

uninstall:
	rm $(INSTALLDIR)/$(LIBNAME)
	rm /usr/include/$(LIBHEADER)

clean:
	rm -rf $(BUILDDIR)
