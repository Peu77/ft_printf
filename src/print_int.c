/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:41:47 by eebert            #+#    #+#             */
/*   Updated: 2024/10/10 15:53:09 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_nbr_len
{
	size_t	len;
	size_t	raw_nbr_len;
	size_t	zero_count;
	bool	has_sign;
}			t_nbr_len;

static void	calculate_len(long nbr, t_flags *flags, t_nbr_len *nbr_len,
		bool ignore_sign)
{
	size_t			len;
	const size_t	raw_nbr_len = ft_numlen_long(nbr);
	size_t			len_with_zeros;

	len_with_zeros = 0;
	len = raw_nbr_len;
	if ((flags->plus || flags->space || nbr < 0) && !ignore_sign)
	{
		len++;
		nbr_len->has_sign = true;
	}
	if (flags->zero)
	{
		if (flags->dot)
			len_with_zeros = len + max(flags->precision - raw_nbr_len, 0);
		else
			len_with_zeros = max(flags->width, len);
	}
	nbr_len->zero_count = max(len_with_zeros - len, 0);
	nbr_len->len = max(len, len_with_zeros);
	nbr_len->raw_nbr_len = raw_nbr_len;
}

void	add_sign(char *buffer, long nbr, t_flags *flags)
{
	if (nbr < 0)
		*buffer = '-';
	else if (flags->plus)
		*buffer = '+';
	else if (flags->space)
		*buffer = ' ';
}

const char	*print_int(t_flags *flags, va_list *args)
{
	const int	number = va_arg(*args, int);
	t_nbr_len	nbr_len;
	char		*buffer;

	calculate_len(number, flags, &nbr_len, false);
	buffer = ft_calloc(nbr_len.len + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	add_sign(buffer, number, flags);
	ft_memset(buffer + nbr_len.has_sign, '0', nbr_len.zero_count);
	itoa_recursive_long(buffer, number, nbr_len.len - 1, nbr_len.has_sign
		+ nbr_len.zero_count);
	return (buffer);
}

const char	*print_unsigned(t_flags *flags, va_list *args)
{
	const unsigned int	number = va_arg(*args, unsigned int);
	t_nbr_len			nbr_len;
	char				*buffer;

	calculate_len(number, flags, &nbr_len, true);
	buffer = ft_calloc(nbr_len.len + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	add_sign(buffer, number, flags);
	ft_memset(buffer, '0', nbr_len.zero_count);
	itoa_recursive_long(buffer, number, nbr_len.len - 1, nbr_len.zero_count);
	return (buffer);
}
