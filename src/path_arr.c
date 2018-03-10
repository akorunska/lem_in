/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:49:34 by akorunsk          #+#    #+#             */
/*   Updated: 2018/03/05 14:50:07 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

t_path		**fill_path_arr(int **paths, int end)
{
	t_path	**res;
	int		size;
	int		len;
	int		i;

	size = 0;
	while (paths[size] != NULL)
		size++;
	res = (t_path **)ft_memalloc(sizeof(t_path*) * (size + 1));
	i = -1;
	while (++i < size)
	{
		res[i] = (t_path *)ft_memalloc(sizeof(t_path));
		res[i]->rooms = paths[i];
		len = 0;
		while (paths[i][len] >= 0)
			len++;
		res[i]->len = len;
		res[i]->rooms[len] = end;
		res[i]->num = i;
		res[i]->ants_q = 0;
	}
	free(paths);
	return (res);
}

void		free_path(t_path **p)
{
	int		i;

	i = 0;
	while (p[i])
	{
		free(p[i]->rooms);
		free(p[i]);
		i++;
	}
	free(p);
}
