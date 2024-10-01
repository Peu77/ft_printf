#include <unistd.h>
#include <stdlib.h>

static size_t ft_hexlen(unsigned long long number, int has_prefix) {
    size_t len = 0;
    while (number) {
        number /= 16;
        len++;
    }
    if (has_prefix)
        return len + 2;
    return len;
}

char *ft_itoa_hex(unsigned long long number, int has_prefix) {
    const char *hex = "0123456789abcdef";
    const size_t len = ft_hexlen(number, has_prefix);
    char *str;
    size_t i;

    str = (char *) malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';
    if (has_prefix) {
        str[0] = '0';
        str[1] = 'x';
    }

    i = len - 1;
    while (number) {
        str[i] = hex[number % 16];
        number /= 16;
        i--;
    }
    return str;
}