#include "ft_printf.h"
#include "libft.h"

static int parse_number(const char *format, int *i) {
    int number = 0;
    while (ft_isdigit(format[*i])) {
        number = number * 10 + format[*i] - '0';
        (*i)++;
    }
    return number;
}

static int is_flag(const char c) {
    return c == '#' || c == '0' || c == '-' || c == ' ' || c == '+';
}

int parse_flags(const char *format, t_flags *flags) {
    int i = 0;
    int width;

    while (is_flag(format[i])) {
        if (format[i] == '#')
            flags->hashtag = 1;
        if (format[i] == '0')
            flags->zero = 1;
        if (format[i] == '-')
            flags->minus = 1;
        if (format[i] == ' ')
            flags->space = 1;
        if (format[i] == '+')
            flags->plus = 1;
        i++;
    }
    width = parse_number(format, &i);
    if (width)
        flags->width = width;
    if (format[i] == '.') {
        flags->dot = 1;
        i++;
        flags->precision = parse_number(format, &i);
    }
    return i;
}