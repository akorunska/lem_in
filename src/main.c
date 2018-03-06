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

int		main(void)
{
	int				ant_q;
	t_matrix		m;
	t_array_list	rooms;
	t_path			**p;

	ant_q = parse_input(&m, &rooms);
	if (!ant_q)
		return (1);
	p = fill_path_arr(get_shortest_paths(&m), m.end_room);
	farm_manager(p, &rooms, ant_q);
	return (0);
}
