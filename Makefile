CC=gcc
CFLAGS=-Wall -Wextra -pedantic
LDFLAGS=-L./build/ -lcolor
CINCLUDE=-I./include/
CFLAGS+=$(CINCLUDE)

BASENAME=color
BUILDDIR=build
INSTALLDIR=/usr/lib

SRC=src/$(BASENAME).c
LIBNAME=lib$(BASENAME).so
LIB=$(BUILDDIR)/$(LIBNAME)

SAMPLE=samples/sample

.PHONY: default samples run_samples install uninstall clean

default: $(LIB)

$(LIB): $(SRC)
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -shared -fPIC $< -o $@

$(SAMPLE): $(SAMPLE).c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

samples: $(SAMPLE)

run_samples:
	LD_LIBRARY_PATH=$(BUILDDIR) $(SAMPLE)

install: $(LIB)
	cp $(LIB) $(INSTALLDIR)
	cp include/color.h /usr/include

uninstall:
	rm $(INSTALLDIR)/$(LIBNAME)
	rm /usr/include/color.h

clean:
	rm -rf $(BUILDDIR) $(SAMPLE)
