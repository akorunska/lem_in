/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:12:39 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/26 10:12:41 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

int		main(void)
{
	int				ant_q;
	t_matrix		m;
	t_array_list	rooms;
	int				**raw_paths;
	t_path			**p;

	ant_q = parse_input(&m, &rooms);
	if (!ant_q)
		return (1);
	raw_paths = get_shortest_paths(&m);
	if (raw_paths)
	{
		p = fill_path_arr(raw_paths, m.end_room);
		farm_manager(p, &rooms, ant_q);
		free_path(p);
	}
	else
		path_doesnt_exits();
	matrix_free(&m);
	al_clear(&rooms);
	return (0);
}
