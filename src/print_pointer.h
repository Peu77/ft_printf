/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:11:07 by eebert            #+#    #+#             */
/*   Updated: 2024/10/11 14:23:06 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_POINTER_H
# define PRINT_POINTER_H

# include <stdbool.h>
# include <unistd.h>

typedef struct s_nbr_len
{
	size_t	len;
	size_t	raw_nbr_len;
	size_t	zero_count;
	bool	has_sign;
}			t_nbr_len;

#endif