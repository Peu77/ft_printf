/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:00 by eebert            #+#    #+#             */
/*   Updated: 2024/10/14 14:57:29 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	print_spaces(const int spaces, const char conversion)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (conversion == '%')
		return (0);
	while (i < spaces)
	{
		len += write(1, " ", 1);
		i++;
	}
	return (len);
}

static size_t	apply_width_and_write(t_flags *flags, const char *str,
		size_t str_len, const char conversion)
{
	int		spaces;
	size_t	len;

	len = 0;
	if (conversion == 'c')
	{
		str_len = 1;
	}
	spaces = flags->width - str_len;
	if (str_len <= 0)
		return (print_spaces(spaces, conversion));
	if (flags->minus)
	{
		len += write(1, str, str_len);
		len += print_spaces(spaces, conversion);
	}
	else
	{
		len += print_spaces(spaces, conversion);
		len += write(1, str, str_len);
	}
	return (len);
}

static int	get_printer_and_print(const char *format, va_list *args, int *i)
{
	t_flags		flags;
	int			offset;
	t_printer	*printer;
	char		*str;
	size_t		len;

	ft_memset(&flags, 0, sizeof(t_flags));
	offset = parse_flags(format, &flags, args);
	printer = get_printer(format[offset]);
	str = printer->print(&flags, args);
	if (!printer)
		return (-1);
	len = apply_width_and_write(&flags, str, ft_strlen(str), printer->type);
	if (str)
		free((void *)str);
	*i += offset + 1;
	return ((int)len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	size_t	len;
	int		print_result;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			len += write(1, &format[i++], 1);
			continue ;
		}
		print_result = get_printer_and_print(format + ++i, &args, &i);
		if (print_result == -1)
		{
			len += write(1, &format[i - 1], 2);
			i++;
			continue ;
		}
		len += print_result;
	}
	return (va_end(args), (int)len);
}
