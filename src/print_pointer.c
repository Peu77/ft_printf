#include "ft_printf.h"
#include "libft.h"

const char *print_pointer(t_flags *flags, va_list *args) {
    (void) flags;
    const unsigned long number = va_arg(*args, unsigned long);

    if (number == 0)
        return ft_strdup("(nil)");
    return ft_itoa_hex(number, 1);
}