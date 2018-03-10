/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putwchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <akorunsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:38:00 by akorunsk          #+#    #+#             */
/*   Updated: 2018/01/23 19:38:00 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		get_wchar_len(int c)
{
	int		temp;
	int		i;

	i = 0;
	temp = c;
	while (temp > 0)
	{
		temp = temp / 2;
		i++;
	}
	if (i <= 7)
		return (1);
	if (i <= 11)
		return (2);
	if (i <= 16)
		return (3);
	return (4);
}

void	ft_putwchar_long(int c)
{
	ft_putchar(((c & 1835008) >> 18) | 240);
	ft_putchar(((c & 258048) >> 12) | 128);
	ft_putchar(((c & 4032) >> 6) | 128);
	ft_putchar((c & 63) | 128);
}

void	ft_putwchar(int c)
{
	int				len;

	len = get_wchar_len(c);
	if (len == 1 || MB_CUR_MAX == 1)
	{
		ft_putchar((unsigned char)c);
		return ;
	}
	if (len == 2)
	{
		ft_putchar(((c & 1984) >> 6) | 192);
		ft_putchar((c & 63) | 128);
	}
	if (len == 3)
	{
		ft_putchar(((c & 61440) >> 12) | 224);
		ft_putchar(((c & 4032) >> 6) | 128);
		ft_putchar((c & 63) | 128);
	}
	if (len == 4)
		ft_putwchar_long(c);
}
