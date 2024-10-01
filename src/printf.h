#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>

typedef struct s_flags {
    size_t width;
    int precision;
    int zero;
    int minus;
    int space;
    int dot;
    int plus;
    int hashtag;
} t_flags;

typedef struct s_printer {
    char type;

    const char *(*print)(t_flags *, va_list *);
} t_printer;

int ft_printf(const char *format, ...);

// print functions

const char *print_char(t_flags *flags, va_list *args);

const char *print_string(t_flags *flags, va_list *args);

const char *print_pointer(t_flags *flags, va_list *args);

const char *print_int(t_flags *flags, va_list *args);

const char *print_unsigned(t_flags *flags, va_list *args);

const char *print_hex(t_flags *flags, va_list *args);

const char *print_hex_upper(t_flags *flags, va_list *args);

const char *print_percent(t_flags *flags, va_list *args);

// utils

size_t ft_putstr(const char *str);

const char *ft_itoa_unsigned(unsigned int number);

int parse_flags(const char *format, t_flags *flags);

char *ft_itoa_hex(long long number, int has_prefix);

#endif