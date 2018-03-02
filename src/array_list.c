/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:40:35 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/26 12:40:37 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	al_initialise(t_array_list *d, int initial_capacity)
{
	int		i;

	d->size = 0;
	d->capacity = (initial_capacity >= 1) ? initial_capacity : 4;
	d->rooms = (t_room **)malloc(sizeof(t_room*) * d->capacity);
	i = 0;
	while (i < d->capacity)
	{
		d->rooms[i] = NULL;
		i++;
	}
}

void	al_stretch(t_array_list *d)
{
	t_room	**nd;
	int		i;

	nd = (t_room **)malloc(sizeof(t_room*) * 2 * d->capacity);
	i = 0;
	while (i < d->size)
	{
		nd[i] = d->rooms[i];
		i++;
	}
	d->capacity *= 2;
	free(d->rooms);
	d->rooms = nd;
}

void	al_insert_room(t_array_list *d, char *name, int x, int y)
{
	if (d->size + 1 >= d->capacity)
		al_stretch(d);
	d->rooms[d->size] = (t_room *)malloc(sizeof(t_room));
	d->rooms[d->size]->name = (char *)malloc(sizeof(char) * ft_strlen(name));
	ft_strcpy(d->rooms[d->size]->name, name);
	d->rooms[d->size]->x = x;
	d->rooms[d->size]->y = y;
	d->size++;
}

void	al_clear(t_array_list *d)
{
	int		i;

	i = 0;
	while (i < d->size)
	{
		ft_memdel((void**)&(d->rooms[i]->name));
		ft_memdel((void**)&(d->rooms[i]));
		i++;
	}
	ft_memdel((void**)&(d->rooms));
}

char	*al_get_room_name(t_array_list *d, int index)
{
	return (d->rooms[index]->name);
}
