/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:25:53 by akorunsk          #+#    #+#             */
/*   Updated: 2018/03/02 15:25:55 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	get_command(char *buf, int *command, t_error *err, t_matrix *m)
{
	if (is_command(buf) && !*command)
		*command = is_command(buf);
	else if (is_command(buf) && *command)
		err->error_type = wrong_tokens_num;
	if (*command)
	{
		if (m->start_room != -1 && *command == 1)
			err->error_type = start_duplicate;
		else if (m->end_room != -1 && *command == 2)
			err->error_type = end_duplicate;
	}
}

int		check_for_errors(char **tokens, t_error *err, t_array_list *rooms)
{
	if (!tokens)
	{
		err->error_type = wrong_tokens_num;
		return (0);
	}
	if (count_tokens(tokens) != 3)
	{
		if (count_tokens(tokens) == 1 || count_tokens(tokens) == 0)
		{
			free_tokens(tokens);
			if (count_tokens(tokens) == 0)
				err->error_type = wrong_tokens_num;
			return (0);
		}
		else
			err->error_type = wrong_tokens_num;
	}
	if (contains_nondigits(tokens[1]) || contains_nondigits(tokens[2]))
		err->error_type = nondigit_coord;
	else if (al_index_of(rooms, tokens[0]) != (-1))
		err->error_type = room_name_duplicate;
	return (1);
}

char	*read_rooms(t_array_list *rooms, t_matrix *m, t_error *err)
{
	int		command;
	char	*buf;
	char	**tokens;

	command = 0;
	while (err->error_type == ok && get_trimmed(&buf) >= 0)
	{
		err->line++;
		get_command(buf, &command, err, m);
		if (!is_comment(buf))
		{
			tokens = ft_split_whitespaces(buf);
			if (!check_for_errors(tokens, err, rooms))
				return (buf);
			if (command == 1)
				m->start_room = rooms->size;
			else if (command == 2)
				m->end_room = rooms->size;
			command = 0;
			al_insert(rooms, tokens[0], ft_atoi(tokens[1]), ft_atoi(tokens[2]));
			free_tokens(tokens);
		}
		ft_memdel((void**)&buf);
	}
	return (NULL);
}
