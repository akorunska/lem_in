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

#include <stdlib.h> //
#include <stdio.h>  //
#include "lem_in.h"
#include <fcntl.h>

// int		main(void)
// {
// 	int				ant_q;
// 	t_matrix		m;
// 	t_array_list	rooms;
// 	t_path			**p;

// 	ant_q = parse_input(&m, &rooms);
// 	if (!ant_q)
// 		return (1);
// 	p = fill_path_arr(get_shortest_paths(&m), m.end_room);
// 	farm_manager(p, &rooms, ant_q);
// 	matrix_free(&m);
// 	al_clear(&rooms);
// 	free_path(p);
	
// 	//system("leaks lem-in");
// 	return (0);
// }

int		main(void)
{
	char	*buf;
	int		fd = open("1.txt", O_RDONLY);

	while (get_next_line(fd, &buf) > 0)
	{
		printf("%s\n", buf);
		free(buf);
	}
	free(buf);
	system("leaks lem-in");
	return (0);
}
