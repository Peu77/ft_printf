/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:17:17 by eebert            #+#    #+#             */
/*   Updated: 2024/10/10 15:47:30 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	parse_number(const char *format, int *i)
{
	int	number;

	number = 0;
	while (ft_isdigit(format[*i]))
	{
		number = number * 10 + format[*i] - '0';
		(*i)++;
	}
	return (number);
}

static int	is_flag(const char c)
{
	return (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+');
}

void	parse_precision(const char *format, t_flags *flags, int *i)
{
	if (format[*i] == '.')
	{
		flags->dot = 1;
		(*i)++;
		flags->precision = parse_number(format, i);
	}
}

int	parse_flags(const char *format, t_flags *flags)
{
	int	i;
	int	width;

	i = 0;
	while (is_flag(format[i]))
	{
		if (format[i] == '#')
			flags->hashtag = 1;
		if (format[i] == '0')
			flags->zero = 1;
		if (format[i] == '-')
			flags->minus = 1;
		if (format[i] == ' ')
			flags->space = 1;
		if (format[i] == '+')
			flags->plus = 1;
		i++;
	}
	width = parse_number(format, &i);
	if (width)
		flags->width = width;
	parse_precision(format, flags, &i);
	return (i);
}
