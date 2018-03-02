
#include "lem_in.h"

void	read_links(t_array_list *rooms, t_matrix *m, t_error *err, char *buf)
{
	int		rv;
	char	**tokens;

	rv = 1;
	if (!buf)
		err->error_type = unknown_error;
	while (rv && err->error_type == ok)
	{
		err->line++;
		if (!is_comment(buf))
		{
			ft_printf("here\n");
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
		rv = get_trimmed(&buf);
	}
}