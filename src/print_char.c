#include "ft_printf.h"
#include "libft.h"

const char	*print_char(t_flags *flags, va_list *args)
{
	const char c = va_arg(*args, int);
	return (ft_strdup(&c));
}