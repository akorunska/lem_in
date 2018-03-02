/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:29:51 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/28 16:29:53 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				handle_error(t_error *e)
{
	if (e->error_type == wrong_ants_num)
		ft_printf("ERROR\nline %i: number of ants is incorrect.\n", e->line);
	else if (e->error_type == wrong_tokens_num)
		ft_printf("ERROR\nline %i: number of tokens is wrong.\n", e->line);
	else if (e->error_type == room_name_duplicate)
		ft_printf("ERROR\nline %i: room with such name already exists.\n",\
			e->line);
	else if (e->error_type == nondigit_coord)
		ft_printf("ERROR\nline %i: the coordinate must be digit.\n", e->line);
	else if (e->error_type == unexisting_room)
		ft_printf("ERROR\nline %i: there is no room with such name.\n",\
			e->line);
	else if (e->error_type == start_not_spec)
		ft_printf("ERROR\nline %i: start room was not specified.\n", e->line);
	else if (e->error_type == end_not_spec)
		ft_printf("ERROR\nline %i: end room was not specified.\n", e->line);
	else if (e->error_type == start_duplicate)
		ft_printf("ERROR\nline %i: start room cannot be specified twice.\n",\
			e->line);
	else if (e->error_type == end_duplicate)
		ft_printf("ERROR\nline %i: end room cannot be specified twice.\n", \
			e->line);
	else
		ft_printf("ERROR\nline %i", e->line);
	return (0);
}
