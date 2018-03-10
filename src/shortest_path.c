/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 08:55:24 by akorunsk          #+#    #+#             */
/*   Updated: 2018/03/05 08:55:26 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "stdlib.h"

int		smallest_dist(t_matrix *m, int start)
{
	char	*visited;
	int		wave;
	int		i;
	int		j;

	if (start == m->end_room)
		return (0);
	wave = 0;
	visited = (char *)ft_memalloc(sizeof(char) * m->rooms_q);
	visited[start] = 1;
	while (++wave < m->rooms_q)
	{
		i = -1;
		while (++i < m->rooms_q)
			if (visited[i] == wave)
			{
				j = -1;
				while (++j < m->rooms_q)
					if (m->reachability_m[i][j] && j == m->end_room)
						return (return_n_free(visited, wave));
					else if (m->reachability_m[i][j])
						visited[j] = wave + 1;
			}
	}
	return (return_n_free(visited, -1));
}

void	build_path(t_matrix *m, int cur, int dist, int *solution)
{
	int		i;
	int		j;

	i = 0;
	while (cur != m->end_room && dist > 0)
	{
		j = 0;
		while (j < m->rooms_q)
		{
			if (m->reachability_m[cur][j] && smallest_dist(m, j) == dist - 1)
			{
				dist--;
				cur = j;
				if (j != m->end_room)
					solution[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int		*get_path(t_matrix *m)
{
	int		*solution;
	int		dist;
	int		i;

	solution = (int *)malloc(sizeof(int) * (m->rooms_q + 1));
	i = 0;
	while (i < m->rooms_q + 1)
	{
		solution[i] = -1;
		i++;
	}
	dist = smallest_dist(m, m->start_room);
	if (dist >= 0)
		build_path(m, m->start_room, dist, solution);
	else
	{
		free(solution);
		return (NULL);
	}
	return (solution);
}

void	mark_rooms(t_matrix *m, int *path)
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
	int		path_exists;

	path_exists = 0;
	res = NULL;
	i = 0;
	while (i < m->rooms_q)
	{
		cur = get_path(m);
		if (cur && !path_exists)
		{
			res = (int **)ft_memalloc(sizeof(int *) * (m->rooms_q + 1));
			path_exists = 1;
		}
		if (!cur)
			return (res);
		res[i] = cur;
		if (res[i][0] == -1)
			return (res);
		mark_rooms(m, res[i]);
		i++;
	}
	return (res);
}
