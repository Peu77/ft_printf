#include "printf.h"
#include "libft.h"

const char *print_string(t_flags *flags, va_list *args) {
    return ft_strdup(va_arg(*args, char *));
}