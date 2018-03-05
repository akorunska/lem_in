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
		while (p[active + 1] && \
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
	res = ants_init(ants_q);
	ants_per_path(p, ants_q);
	while (ants_q)
	{
		cur_p = 0;
		while (p[cur_p])
		{
			if (p[cur_p]->ants_q > 0)
			{
				p[cur_p]->ants_q--;
				res[cur_ant]->path = cur_p;
				res[cur_ant]->start_time = time;
				cur_ant++;
			}
			i++;
		}
		time++;
	}
	return (res);
}
