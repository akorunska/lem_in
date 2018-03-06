/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:50:53 by akorunsk          #+#    #+#             */
/*   Updated: 2018/03/05 15:51:18 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

t_ant	**ants_init(int q)
{
	t_ant	**res;
	int		i;

	res = (t_ant **)ft_memalloc(sizeof(t_ant *) * (q + 1));
	res[q] = NULL;
	i = 0;
	while (i < q)
	{
		res[i] = (t_ant *)ft_memalloc(sizeof(t_ant));
		res[i]->num = i;
		res[i]->path = -1;
		res[i]->step_num = -1;
		res[i]->start_time = -1;
		res[i]->finished = 0;
		i++;
	}
	return (res);
}
