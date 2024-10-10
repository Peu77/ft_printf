/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:50:32 by eebert            #+#    #+#             */
/*   Updated: 2024/10/10 22:37:01 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main() {
    const char *str = "%05.*d\n";
    int printed = printf(str, -15, 42);
    int printed2 = ft_printf(str, -15, 42);

    printf("printf: %d\n", printed);
    printf("ft_printf: %d\n", printed2);
}