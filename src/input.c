/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:20:35 by akorunsk          #+#    #+#             */
/*   Updated: 2018/03/02 15:20:41 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_command(char *buf)
{
	if (!ft_strcmp("##start", buf))
		return (1);
	else if (!ft_strcmp("##end", buf))
		return (2);
	return (0);
}

int		is_comment(char *buf)
{
	if (buf[0] == '#')
		return (1);
	return (0);
}

int		get_trimmed(char **temp)
{
	char	*buf;
	int		rv;

	rv = get_next_line(0, &buf);
	*temp = ft_strtrim(buf);
	ft_memdel((void**)&buf);
	return (rv);
}
