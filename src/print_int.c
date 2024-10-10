#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static size_t	calculate_len(long number, t_flags *flags)
{
	size_t	len;

	len = ft_numlen_long(number);
	if (flags->plus || flags->space || number < 0)
		len++;

	
}

const char	*print_int(t_flags *flags, va_list *args)
{
	const int	number = va_arg(*args, int);
	const char	*str = ft_itoa(number);

	return (str);
}

const char	*print_unsigned(t_flags *flags, va_list *args)
{
	const unsigned int	number = va_arg(*args, unsigned int);

	return (ft_itoa_unsigned(number));
}
