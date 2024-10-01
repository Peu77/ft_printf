#include "printf.h"
#include <stdlib.h>

const char *print_char(t_flags *flags, va_list *args) {
    const char c = va_arg(*args, int);
    char *str = malloc(2);
    if (!str) {
        return 0;
    }
    str[0] = c;
    str[1] = '\0';
    return str;
}