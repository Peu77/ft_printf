/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:16 by eebert            #+#    #+#             */
/*   Updated: 2024/10/10 22:29:50 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	size_t		width;
	size_t 		precision;
	int			zero;
	int			minus;
	int			space;
	int			dot;
	int			plus;
	int			hashtag;
}				t_flags;

typedef struct s_printer
{
	char		type;

	const char	*(*print)(t_flags *, va_list *);
}				t_printer;

int				ft_printf(const char *format, ...);

// print functions

const char		*print_char(t_flags *flags, va_list *args);

const char		*print_string(t_flags *flags, va_list *args);

const char		*print_pointer(t_flags *flags, va_list *args);

const char		*print_int(t_flags *flags, va_list *args);

const char		*print_unsigned(t_flags *flags, va_list *args);

const char		*print_hex(t_flags *flags, va_list *args);

const char		*print_hex_upper(t_flags *flags, va_list *args);

const char		*print_percent(t_flags *flags, va_list *args);

// utils

int				parse_flags(const char *format, t_flags *flags, va_list *args);

size_t			ft_numlen_long(long n);

int				max(int a, int b);

void			itoa_recursive_long(char *str, long nbr, size_t start,
					size_t stop);

#endif