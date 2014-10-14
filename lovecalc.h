#ifndef LOVECALC_H
#define LOVECALC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>

#define MAXLEN 100

// Global variables

static int verbose_flag = 0;

// Functions

char *getstr (char*, int, FILE*);
void print_usage(void);
double lovecalc(char [2][MAXLEN]);
void messages(double);
void print_version(void);

#endif
