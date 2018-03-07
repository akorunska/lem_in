/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:24:47 by akorunsk          #+#    #+#             */
/*   Updated: 2018/03/02 15:24:50 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	first_link(t_array_list *rooms, t_matrix *m, t_error *err, char *buf)
{
	char **tokens;

	tokens = ft_strsplit(buf, '-');
	if (count_tokens(tokens) != 2)
		err->error_type = wrong_tokens_num;
	else if (al_index_of(rooms, tokens[0]) == -1 \
		|| al_index_of(rooms, tokens[1]) == -1)
		err->error_type = unexisting_room;
	else
		matrix_set_link(m, rooms, tokens[0], tokens[1]);
	free_tokens(tokens);
	ft_memdel((void**)&buf);
}

void	read_links(t_array_list *rooms, t_matrix *m, t_error *err, char *buf)
{
	char	**tokens;

	if (!buf)
		err->error_type = unknown_error;
	else
		first_link(rooms, m, err, buf);
	while (err->error_type == ok && get_next_line(0, &buf))
	{
		if (!is_comment(buf))
		{
			tokens = ft_strsplit(buf, '-');
			if (count_tokens(tokens) != 2)
				err->error_type = wrong_tokens_num;
			else if (al_index_of(rooms, tokens[0]) == -1 \
				|| al_index_of(rooms, tokens[1]) == -1)
				err->error_type = unexisting_room;
			else
				matrix_set_link(m, rooms, tokens[0], tokens[1]);
			free_tokens(tokens);
		}
		ft_memdel((void**)&buf);
		err->line++;
	}
	free(buf);
}
