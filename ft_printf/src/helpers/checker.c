/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <akorunsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 20:15:00 by akorunsk          #+#    #+#             */
/*   Updated: 2018/01/02 20:15:00 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "ft_printf.h"

int		is_str(char c)
{
	if (c == 's' || c == 'S')
		return (1);
	return (0);
}

int		is_type(char c)
{
	const char	types[] = {'s', 'u', 'd', 'i', 'c', '%', 'o', 'x', 'X', \
							'p', '%', 'O', 'U', 'D', 'S', 'C'};
	size_t		i;

	i = 0;
	while (i < (size_t)(sizeof(types) / sizeof(char)))
	{
		if (c == types[i])
			return (c);
		i++;
	}
	return (0);
}

int		is_allowed(char c)
{
	if (ft_isdigit(c) || c == '.' || c == '*')
		return (1);
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	else if (c == 'h' || c == 'l' || c == 'z' || c == 'j')
		return (1);
	return (0);
}
