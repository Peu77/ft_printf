#include <unistd.h>
#include "libft.h"

size_t ft_putstr(const char *str) {
    size_t len;

    if (!str)
        return write(1, "(null)", 6);

    len = ft_strlen(str);
    return write(1, str, len);
}

static int ft_numlen_unsigned(unsigned int n) {
    int len;

    len = 0;
    while (n) {
        n /= 10;
        len++;
    }
    return (len);
}

static void itoa_recursive_unsigned(char *str, unsigned int n, int start) {
    if (n == 0) {
        return;
    }
    itoa_recursive_unsigned(str, n / 10, start - 1);
    str[start] = n % 10 + '0';
}


const char *ft_itoa_unsigned(unsigned int number) {
    char *str;
    int num_len;

    if (number == 0) {
        return (ft_strdup("0"));
    }

    num_len = ft_numlen_unsigned(number);
    str = ft_calloc(num_len + 1, sizeof(char));
    if (!str)
        return (NULL);
    itoa_recursive_unsigned(str, number, num_len - 1);
    return (str);
}