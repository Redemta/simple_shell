#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define BUFSIZE 1024
/* my_printf.c */
int my_printf(const char *format, ...);

/* display_prompt.c */
void display_prompt(void);
void display_error(char *err_message, int loop_count, char **argv);

/* parse_input.c */
char **parse_input(char *input);

#endif
