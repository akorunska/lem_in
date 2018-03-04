/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:46:37 by akorunsk          #+#    #+#             */
/*   Updated: 2018/03/04 18:46:39 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	mark_rooms(t_matrix *m, int	*path)
{
	int		i;
	int		j;

	i = 0;
	while (path[i] >= 0)
	{
		j = 0;
		while (j < m->rooms_q)
		{
			m->reachability_m[path[i]][j] = 0;
			j++;
		}
		j = 0;
		while (j < m->rooms_q)
		{
			m->reachability_m[j][path[i]] = 0;
			j++;
		}
		i++;
	}
}

int		**get_shortest_paths(t_matrix *m)
{
	int		**res;
	int		*cur;
	int		i;

	res = (int **)ft_memalloc(sizeof(int *) * (m->rooms_q + 1));
	i = 0;
	while (i < m->rooms_q)
	{
		cur = get_path();
		if (!cur)
			return (res);
		res[i] = cur;
		mark_rooms(m, cur);
		i++;
	}
	return (res);
}
