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

void	al_initialise(t_dict *d, int initial_capacity)
{
	int		i;

	d->size = 0;
	d->capasity = (initial_capacity >= 1) ? initial_capacity : 4;
	d->rooms = (t_room **)malloc(sizeof(t_room*) * d->capasity);
	i = 0;
	while (i < d->capasity)
	{
		d->rooms[i] = NULL;
		i++;
	}
}

void	al_stretch(t_dict *d)
{
	t_room	**nd;
	int		i;

	nd = (t_room **)malloc(sizeof(t_room*) * 2 * d->capasity);
	i = 0;
	while (i < d->size)
	{
		nd[i] = d->rooms[i];
		i++;
	}
	d->capasity *= 2;
	free(d->rooms);
	d->rooms = nd;
}

void	al_insert_room(t_dict *d, char *name, int x, int y)
{
	if (d->size + 1 >= d->capasity)
		al_stretch(d);
	d->rooms[size] = (t_room *)malloc(sizeof(t_room));
	d->rooms[size].name = (char *)malloc(sizeof(char) * ft_strlen(name));
	ft_strcpy(d->rooms[size].name, name);
	d->rooms[size]->x = x;
	d->rooms[size]->y = y;
	d->size++;
}

void	al_clear(t_dic *d)
{
	int		i;

	int		i = 0;
	while (i < d->size)
	{
		ft_memdel(d->rooms[i].name);
		ft_memdel(d->rooms[i])
		i++;
	}
	ft_memdel(d->rooms);
}
