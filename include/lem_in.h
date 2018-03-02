/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 09:31:58 by akorunsk          #+#    #+#             */
/*   Updated: 2018/02/26 09:32:00 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf.h"
# include "libft.h"

typedef struct	s_matrix
{
	int		rooms_q;
//	int		moment;
	int		start_room;
	int		end_room;
	char 	**reachability_m;
}				t_matrix;

typedef struct	s_room
{
	char	*name;
	int		x;
	int		y;
}				t_room;

typedef struct	s_array_list
{
	int		capacity;
	int		size;
	t_room	**rooms;
}				t_array_list;

typedef struct	s_ant
{
	int		num;
	char 	**path;
}				t_ant;

typedef struct	s_error
{
	int		error_type;
	int		line;
}				t_error;

enum			e_err
{
	ok,
	wrong_ants_num,
	wrong_tokens_num,
	room_name_duplicate,
	nondigit_coord,
	unexisting_room,
	start_not_spec,
	end_not_spec,
	start_duplicate,
	end_duplicate,
	unknown_error
};

int				parse_input(t_matrix *m, t_array_list *rooms);

char			*read_rooms(t_array_list *rooms, t_matrix *m, t_error *err);
void			read_links(t_array_list *rooms, t_matrix *m, t_error *err, char *buf);

int				get_trimmed(char **temp);
int				is_command(char *buf);
int				is_comment(char *buf);

void			matrix_initialise(t_matrix *m);
void			matrix_alloc(t_matrix *m, int rooms_q);
void			matrix_set_link(t_matrix *m, t_array_list *l, char *r1, char *r2);

void			al_initialise(t_array_list *d, int initial_capacity);
void			al_insert_room(t_array_list *d, char *name, int x, int y);
void			al_clear(t_array_list *d);
char			*al_get_room_name(t_array_list *d, int index);
int				al_index_of(t_array_list *d, char *to_find);

int				contains_nondigits(char *str);
int				count_tokens(char **t);
void			free_tokens(char **t);

int				handle_error(t_error *t);

#endif
