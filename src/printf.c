/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:00 by eebert            #+#    #+#             */
/*   Updated: 2024/10/10 22:31:03 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static const t_printer printers[] = {
        {'d', &print_int},
        {'i', &print_int},
        {'u', &print_unsigned},
        {'x', &print_hex},
        {'X', &print_hex_upper},
        {'c', &print_char},
        {'s', &print_string},
        {'p', &print_pointer},
        {'%', &print_percent},
        {0,   0}
};

static const t_printer *get_printer(char type) {
    int i = 0;

    while (printers[i].type) {
        if (printers[i].type == type)
            return &printers[i];
        i++;
    }
    return NULL;
}

static int is_numeric_conversion(char c) {
    return c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'p';
}

static size_t print_spaces(t_flags *flags, const int spaces, const char conversion) {
    int i = 0;
    size_t len = 0;
    char c = ' ';

    if (conversion == '%')
        return 0;

    if (flags->zero && !flags->minus && !flags->dot && is_numeric_conversion(conversion))
        c = '0';

    while (i < spaces) {
        len += write(1, &c, 1);
        i++;
    }
    return len;
}

static size_t apply_width_and_write(t_flags *flags, const char *str, size_t str_len, const char conversion) {
    const int spaces = flags->width - str_len;
    size_t len = 0;

    if (str_len <= 0)
        return print_spaces(flags, spaces, conversion);;

    if (flags->minus) {
        len += write(1, str, str_len);
        len += print_spaces(flags, spaces, conversion);
    } else {
        len += print_spaces(flags, spaces, conversion);
        len += write(1, str, str_len);
    }
    return len;
}

int ft_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int i = 0;
    size_t len = 0;

    while (format[i]) {
        if (format[i] == '%') {
            t_flags flags = {0};
            i++;
            const int offset = parse_flags(format + i, &flags, &args);
            const char conversion = format[i + offset];
            const t_printer *printer = get_printer(conversion);
            if (printer) {
                i += offset;
                const char *str = printer->print(&flags, &args);
                size_t str_len = ft_strlen(str);
                if (conversion == 'c' && str[0] == 0)
                    str_len = 1;

                len += apply_width_and_write(&flags, str, str_len, conversion);
                free((void *) str);
            } else {
                len += write(1, &format[i - 1], 2);
            }
        } else
            len += write(1, &format[i], 1);
        i++;
    }

    va_end(args);
    return (int) len;
}