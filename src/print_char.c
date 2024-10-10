/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:10 by eebert            #+#    #+#             */
/*   Updated: 2024/10/10 21:30:33 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

const char	*print_char(t_flags *flags, va_list *args)
{
    (void)flags;
	const char c = va_arg(*args, int);
	return (ft_strdup(&c));
}