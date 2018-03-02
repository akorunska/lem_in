
#include "lem_in.h"

char	*read_rooms(t_array_list *rooms, t_matrix *m, t_error *err)
{
	int		command;
	char	*buf;
	char 	**tokens;

	command = 0;
	while (get_trimmed(&buf) >= 0 && err->error_type == ok)
	{
		err->line++;
		if (is_command(buf) && !command)
			command = is_command(buf);
		else if (is_command(buf) && !command)
			err->error_type = wrong_tokens_num;
		if (command)
		{
			if (m->start_room != -1 && command == 1)
				err->error_type = start_duplicate;
			else if (m->end_room != -1 && command == 2)
				err->error_type = end_duplicate;
		}
		if (!is_comment(buf))
		{
			tokens = ft_split_whitespaces(buf);
			if (count_tokens(tokens) != 3)
			{
				if (count_tokens(tokens) == 1)
				{
					free_tokens(tokens);
					return (buf);
				}
				else
					err->error_type = wrong_tokens_num;
			}
			if (contains_nondigits(tokens[1]) || contains_nondigits(tokens[2]))
				err->error_type = nondigit_coord;
			else if (al_index_of(rooms, tokens[0]) != (-1))
				err->error_type = room_name_duplicate;
			if (command == 1)
				m->start_room = rooms->size;
			else if (command == 2)
				m->end_room = rooms->size;
			command = 0;
			al_insert_room(rooms, tokens[0], ft_atoi(tokens[1]), ft_atoi(tokens[2]));
			free_tokens(tokens);
		}
		ft_memdel((void**)&buf);
	}
	return (NULL);
}