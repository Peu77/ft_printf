/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:41:55 by eebert            #+#    #+#             */
/*   Updated: 2024/10/10 15:41:56 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

const char	*print_pointer(t_flags *flags, va_list *args)
{
	const unsigned long	number = va_arg(*args, unsigned long);

	(void)flags;
	if (number == 0)
		return (ft_strdup("(nil)"));
	return (ft_itoa_hex(number, 1));
}
