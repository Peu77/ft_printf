#include "ft_printf.h"
#include <stdlib.h>

const char	*print_hex(t_flags *flags, va_list *args)
{
	const unsigned int	number = va_arg(*args, unsigned int);

	return (ft_itoa_hex(number, flags->hashtag));
}

const char	*print_hex_upper(t_flags *flags, va_list *args)
{
	const unsigned int	number = va_arg(*args, unsigned int);
	char				*str;
	size_t				i;

	str = ft_itoa_hex(number, flags->hashtag);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
