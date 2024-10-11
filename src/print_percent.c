/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:41:52 by eebert            #+#    #+#             */
/*   Updated: 2024/10/11 14:03:39 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*print_percent(t_flags *flags, va_list *args)
{
	(void)flags;
	(void)args;
	return (ft_strdup("%"));
}
