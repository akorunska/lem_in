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
	int		moment;
	char 	**reachability_m;
}				t_matrix;

typedef struct	s_room
{
	char	*name;
	int		x;
	int		y;
}				t_room;

typedef struct	s_dict
{
	int		capacity;
	int		size;
	char	*t_room;
}				t_dict;

typedef struct	s_ant
{
	int		num;
	char 	**path;
}				t_ant;

int		read_input(t_matrix *m, t_dict *rooms);

#endif
