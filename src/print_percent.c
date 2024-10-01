#include "ft_printf.h"
#include "libft.h"

const char *print_percent(t_flags *flags, va_list *args) {
    (void) flags;
    (void) args;
    return ft_strdup("%");
}