/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:41:58 by eebert            #+#    #+#             */
/*   Updated: 2024/10/10 21:31:19 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

const char	*print_string(t_flags *flags, va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
	{
		if (flags->dot && flags->precision < 6)
			return (ft_strdup(""));
		return (ft_strdup("(null)"));
	}
	if (flags->dot && flags->precision < ft_strlen(str))
		return (ft_substr(str, 0, flags->precision));
	return (ft_strdup(str));
}
