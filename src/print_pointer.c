#include "printf.h"

const char *print_pointer(t_flags *flags, va_list *args) {
    (void) flags;
    const unsigned long number = va_arg(*args, unsigned long);
    return ft_itoa_hex(number, 1);
}