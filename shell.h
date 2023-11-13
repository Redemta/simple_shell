#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define BUFSIZE 1024

extern char **environ;

/* my_printf.c */
int my_printf(const char *format, ...);

/* display_prompt.c */
void display_prompt(void);
void display_error(char *err_message, int loop_count, char **argv);

/* parse_input.c */
char **parse_input(char *input);

/* my_string.c */
char *my_strcpy(char *dest, const char *source);
char *my_strcat(char *dest, char *source);
char *my_strdup(char *str);
char *my_strchr(char *str, char c);
int my_strncmp(const char *str1, const char *str2, size_t n);

/* more_string.c */
int my_strcmp(char *str1, char *str2);
char *my_strtok(char *str, const char *del);
int my_char_in_string(char ch, const char *str);

/* more_func.c */
int my_isalpha(int c);
void my_arrayrev(char arr[], int length);
int my_intlen(unsigned int num);
char *my_itoa(unsigned int num);

/* _readinput.c */
char *_readInput();
void _hashtag(char *input);

/* more_char.c */
char *my_strncpy(char *dest, const char *src, int n);
size_t my_strlen(const char *str);
int my_atoi(const char *str);
void my_puts(const char *str);

/* memory_functions.c */
void *my_realloc(void *ptr, unsigned int size_old, unsigned int size_new);
void *my_memcpy(void *dest, const void *src, unsigned int num);
void my_free_array(char **cmd, char *line);
void *my_memset(void *ptr, int val, unsigned int num);
void *my_malloc(unsigned int size);

/* env_func.c */
void create_env_array(char **env);
char *my_getenv_value(const char *name);

#endif
