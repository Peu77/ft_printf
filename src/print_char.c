/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:10 by eebert            #+#    #+#             */
/*   Updated: 2024/10/11 14:12:11 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*print_char(t_flags *flags, va_list *args)
{
	const char	c = va_arg(*args, int);

	(void)flags;
	return (ft_strdup(&c));
}
