CC = gcc
CFLAGS = -O -ggdb
EXE = lovecalc
CFILES = *.c
HFILES = lovecalc.h

$(EXE): $(CFILES) $(HFILES)
	@$(CC) $(CFLAGS) $(CFILES) -o $@
	@echo "$(EXE) created."

clean:
	@rm -f $(EXE)
	@echo "Cleaned."
