/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:20:36 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/28 13:20:39 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		al_index_of(t_array_list *d, char *to_find)
{
	int		i;

	i = 0;
	while (i < d->size)
	{
		if (!ft_strcmp(to_find, d->rooms[i]->name))
			return (i);
		i++;
	}
	return (-1);
}
