CC = gcc
CFLAGS = -O -ggdb
EXECUTABLE = lovecalc
CFILES = main.c util.c calc.c print.c
HFILES = lovecalc.h

all: $(EXECUTABLE)

$(EXECUTABLE): $(CFILES)
	$(CC) $(CFLAGS) $^ -o $@

$(CFILES): $(HFILES)

clean:
	rm -f $(EXECUTABLE)
