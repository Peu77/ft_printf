/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:42:00 by eebert            #+#    #+#             */
/*   Updated: 2024/10/11 12:58:34 by eebert           ###   ########.fr       */
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

static size_t print_spaces(const int spaces, const char conversion) {
    int i = 0;
    size_t len = 0;

    if (conversion == '%')
        return 0;

    while (i < spaces) {
        len += write(1, " ", 1);
        i++;
    }
    return len;
}

static size_t apply_width_and_write(t_flags *flags, const char *str, size_t str_len, const char conversion) {
    const int spaces = flags->width - str_len;
    size_t len = 0;

    if (str_len <= 0)
        return print_spaces(spaces, conversion);;

    if (flags->minus) {
        len += write(1, str, str_len);
        len += print_spaces(spaces, conversion);
    } else {
        len += print_spaces(spaces, conversion);
        len += write(1, str, str_len);
    }
    return len;
}

static size_t print_printer(const t_printer *printer, t_flags *flags, va_list *args) {
    const char *str = printer->print(flags, args);
    size_t str_len = ft_strlen(str);
    if (printer->type == 'c' && str[0] == 0)
        str_len = 1;

    size_t len = apply_width_and_write(flags, str, str_len, printer->type);
    if (str)
        free((void *) str);
    return len;
}

int ft_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int i = 0;
    size_t len = 0;

    while (format[i]) {
        if (format[i] != '%') {
            len += write(1, &format[i++], 1);
            continue;
        }

        t_flags flags = {0};
        i++;
        const int offset = parse_flags(format + i, &flags, &args);
        const char conversion = format[i + offset];
        const t_printer *printer = get_printer(conversion);
        if (!printer) {
            len += write(1, &format[i - 1], 2);
            i++;
            continue;
        }
        len += print_printer(printer, &flags, &args);
        i += offset + 1;
    }

    va_end(args);
    return (int) len;
}