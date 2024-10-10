/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:56:30 by eebert            #+#    #+#             */
/*   Updated: 2024/10/10 15:11:27 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*generate_chars(char c, size_t len)
{
	char	*str;
	size_t	i;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
// get the length of a number without sign

size_t	ft_numlen_long(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
#include <stdio.h>

void	itoa_recursive_long(char *str, long nbr, size_t start, size_t stop)
{
	if (start == stop - 1)
	{
		return ;
	}
	itoa_recursive_long(str, nbr / 10, start - 1, stop);
	str[start] = nbr % 10 + '0';
}
