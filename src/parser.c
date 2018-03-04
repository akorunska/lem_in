/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 09:31:11 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/26 09:31:15 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		read_ants(t_error *err)
{
	char	*buf;
	char	**tokens;
	int		res;

	res = 0;
	err->line = 1;
	err->error_type = ok;
	get_trimmed(&buf);
	tokens = ft_split_whitespaces(buf);
	if (count_tokens(tokens) != 1)
		err->error_type = wrong_tokens_num;
	else if (contains_nondigits(buf))
		err->error_type = wrong_ants_num;
	else
	{
		res = ft_atoi(buf);
		if (res <= 0)
			err->error_type = wrong_ants_num;
	}
	free_tokens(tokens);
	return (res);
}

void	check_end_start(t_matrix *m, t_error *err)
{
	if (err->error_type != ok)
		return ;
	if (m->start_room == -1)
		err->error_type = start_not_spec;
	else if (m->end_room == -1)
		err->error_type = end_not_spec;
}

int		parse_input(t_matrix *m, t_array_list *rooms)
{
	t_error	err;
	char	*buf;
	int		ant_q;

	al_initialise(rooms, 4);
	matrix_initialise(m);
	ant_q = read_ants(&err);
	if (err.error_type != ok)
		return (handle_error(&err));
	buf = read_rooms(rooms, m, &err);
	check_end_start(m, &err);
	if (err.error_type != ok)
		return (handle_error(&err));
	matrix_alloc(m, rooms->size);
	read_links(rooms, m, &err, buf);
	if (err.error_type != ok && !m->links_q)
		return (handle_error(&err));
	return (ant_q);
}
