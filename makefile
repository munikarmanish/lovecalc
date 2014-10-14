CC = gcc
CFLAGS = -O -ggdb
EXE = lovecalc
CFILES = *.c
HFILES = lovecalc.h

$(EXE): $(CFILES)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(EXE) created."

$(CFILES): $(HFILES)

clean:
	@rm -f $(EXE)
	@echo "Cleaned."
