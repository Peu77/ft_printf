#include "printf.h"
#include "libft.h"

const char *print_string(t_flags *flags, va_list *args) {
    char *str = va_arg(*args, char *);

    if (!str) {
        if (flags->dot && flags->precision < 6)
            return ft_strdup("");
        return ft_strdup("(null)");
    }
    if (flags->dot && flags->precision < ft_strlen(str))
        return ft_substr(str, 0, flags->precision);
    return ft_strdup(str);
}