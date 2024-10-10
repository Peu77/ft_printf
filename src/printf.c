#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static const t_printer	printers[] = {{'d', &print_int}, {'i', &print_int},
		{'u', &print_unsigned}, {'x', &print_hex}, {'X', &print_hex_upper},
		{'c', &print_char}, {'s', &print_string}, {'p', &print_pointer}, {'%',
		&print_percent}, {0, 0}};

static const t_printer	*get_printer(char type)
{
	int	i;

	i = 0;
	while (printers[i].type)
	{
		if (printers[i].type == type)
			return (&printers[i]);
		i++;
	}
	return (NULL);
}

static int	is_numeric_conversion(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X'
		|| c == 'p');
}

static size_t	print_spaces(t_flags *flags, const int spaces,
		const char conversion)
{
	int		i;
	size_t	len;
	char	c;

	i = 0;
	len = 0;
	c = ' ';
	if (flags->zero && !flags->minus && !flags->dot
		&& is_numeric_conversion(conversion))
		c = '0';
	while (i < spaces)
	{
		len += write(1, &c, 1);
		i++;
	}
	return (len);
}

static size_t	apply_width_and_write(t_flags *flags, const char *str,
		size_t str_len, const char conversion)
{
	const int	spaces = flags->width - str_len;
	size_t		len;

	len = 0;
	if (str_len <= 0)
		return (print_spaces(flags, spaces, conversion));
	;
	if (flags->minus)
	{
		len += write(1, str, str_len);
		len += print_spaces(flags, spaces, conversion);
	}
	else
	{
		len += print_spaces(flags, spaces, conversion);
		len += write(1, str, str_len);
	}
	return (len);
}

static char	*append_plus_if_needed(t_flags *flags, char *str,
		const char conversion)
{
	char	*new_str;

	new_str = str;
	if (flags->plus && str[0] != '-' && is_numeric_conversion(conversion))
	{
		new_str = ft_strjoin("+", str);
		free(str);
	}
	return (new_str);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	size_t	len;
	t_flags	flags;
			const int offset = parse_flags(format + i, &flags);
			const char conversion = format[i + offset];
			const t_printer *printer = get_printer(conversion);
				const char *str = append_plus_if_needed(&flags,
						(char *)printer->print(&flags, &args), conversion);
	size_t	str_len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			flags = {0};
			i++;
			if (printer)
			{
				i += offset;
				str_len = ft_strlen(str);
				if (conversion == 'c' && str[0] == 0)
					str_len = 1;
				len += apply_width_and_write(&flags, str, str_len, conversion);
				free((void *)str);
			}
			else
			{
				len += write(1, &format[i - 1], 2);
			}
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return ((int)len);
}
