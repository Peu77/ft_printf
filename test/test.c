/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:50:32 by eebert            #+#    #+#             */
/*   Updated: 2024/10/11 12:58:12 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main() {
    const char *str = "%-10c %%\n";
    int printed = printf(str, 'c');
    int printed2 = ft_printf(str, 'c');

    printf("printf: %d\n", printed);
    printf("ft_printf: %d\n", printed2);
}