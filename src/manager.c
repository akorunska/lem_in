/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:47:27 by akorunsk          #+#    #+#             */
/*   Updated: 2018/03/05 15:47:44 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ants_per_path(t_path **p, int ants_q)
{
	int		cur_q;
	int		active;
	int		i;

	cur_q = 0;
	active = 0;
	while (cur_q < ants_q)
	{
		i = 0;
		while (i <= active && cur_q < ants_q)
		{
			p[i]->ants_q++;
			i++;
			cur_q++;
		}
		while (p[active + 1] &&
			p[active]->len + p[active]->ants_q > p[active + 1]->len)
			active++;
	}
}

t_ant	**divide_ants(t_path **p, int ants_q)
{
	t_ant	**res;
	int		time;
	int		cur_p;
	int		cur_ant;

	time = 0;
	cur_ant = 0;
	res = ants_init(ants_q);
	ants_per_path(p, ants_q);
	while (ants_q)
	{
		cur_p = -1;
		while (p[++cur_p])
			if (p[cur_p]->ants_q > 0)
			{
				p[cur_p]->ants_q--;
				res[cur_ant]->path = cur_p;
				res[cur_ant]->start_time = time;
				cur_ant++;
				ants_q--;
			}
		time++;
	}
	return (res);
}

void	print_move(int ant_num, t_array_list *rooms, int room_num)
{
	char *r_name;

	r_name = al_get_room_name(rooms, room_num);
	ft_printf("L%i-%s ", ant_num + 1, r_name);
}

void	move_ant(t_path **p, t_ant *cur_ant, t_array_list *rooms, int *f)
{
	cur_ant->step_num++;
	if (p[cur_ant->path]->rooms[cur_ant->step_num] != -1)
	{
		print_move(cur_ant->num, rooms,
			p[cur_ant->path]->rooms[cur_ant->step_num]);
		*f = 0;
	}
	else
		cur_ant->finished = 1;
}

void	farm_manager(t_path **p, t_array_list *rooms, int ants_q)
{
	t_ant	**ants;
	int		time;
	int		everyone_finished;
	int		cur_ant;

	ants = divide_ants(p, ants_q);
	time = 0;
	everyone_finished = 0;
	while (!everyone_finished)
	{
		if (time)
			ft_printf("\n");
		everyone_finished = 1;
		cur_ant = -1;
		while (ants[++cur_ant])
		{
			if (!ants[cur_ant]->finished && time >= ants[cur_ant]->start_time)
				move_ant(p, ants[cur_ant], rooms, &everyone_finished);
		}
		time++;
	}
	ants_free(ants);
}
