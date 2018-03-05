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

void	otput_res(t_matrix *m, t_array_list *r)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("R O O M S\n\n");
	while (i < r->size)
	{
		ft_printf("\t %i | %s |\n", i, al_get_room_name(r, i));
		i++;
	}
	ft_printf("\nM A T R I X\n");
	ft_printf("start room: %s\n", al_get_room_name(r, m->start_room));
	ft_printf("end room: %s\n", al_get_room_name(r, m->end_room));

	ft_printf("   ");
	j = 0;
	while (j < m->rooms_q)
	{
		ft_printf("%i ", j % 10);
		j++;
	}
	ft_printf("\n\n");
	i = 0;
	while (i < m->rooms_q)
	{
		j = 0;
		ft_printf("%i  ", i);
		while (j < m->rooms_q)
		{
			ft_printf("%i ", m->reachability_m[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_paths(t_path **p)
{
	int		i;

	i = 0;
	while (p[i])
	{
		ft_printf("num: %i, len: %i, ant_q: %i || ", p[i]->num, p[i]->len, p[i]->ants_q);
		for(int j = 0; p[i]->rooms[j] >= 0; j++)
		{
			ft_printf("%i - ", p[i]->rooms[j]);
		}
		ft_printf("\n");
		i++;
	}
}

int		main(void)
{
	int				ant_q;
	t_matrix		m;
	t_array_list	rooms;
	t_path			**p;

	ant_q = parse_input(&m, &rooms);
	if (!ant_q)
		return (1);
	otput_res(&m, &rooms);
	p = fill_path_arr(get_shortest_paths(&m));
	divide_ants(p, ant_q);
	return (0);
}
