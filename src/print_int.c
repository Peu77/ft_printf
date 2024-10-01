#include "printf.h"
#include "libft.h"
#include <stdlib.h>

const char *print_int(t_flags *flags, va_list *args) {
    const int number = va_arg(*args, int);
    const char *str = ft_itoa(number);

    return str;
}

const char *print_unsigned(t_flags *flags, va_list *args) {
    const unsigned int number = va_arg(*args, unsigned int);
    return ft_itoa_unsigned(number);
}