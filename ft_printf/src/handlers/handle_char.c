/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:50:42 by akorunsk          #+#    #+#             */
/*   Updated: 2017/12/25 16:51:00 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		handle_char(va_list args, t_param *p)
{
	char	c;

	if (!ft_strcmp(p->len, "l") && MB_CUR_MAX == 4)
		return (handle_wchar(args, p));
	if (p->width_specified && !p->flag_minus && !p->flag_zero)
		ft_putnchar(' ', p->width - 1);
	if (p->width_specified && !p->flag_minus && p->flag_zero)
		ft_putnchar('0', p->width - 1);
	c = (char)va_arg(args, void*);
	ft_putchar(c);
	if (p->width_specified && p->flag_minus)
		ft_putnchar(' ', p->width - 1);
	return ((p->width > 1) ? p->width : 1);
}

int		handle_wchar(va_list args, t_param *p)
{
	int		c;
	int		len;

	c = (int)va_arg(args, void*);
	len = get_wchar_len(c);
	if (p->width_specified && !p->flag_minus && !p->flag_zero)
		ft_putnchar(' ', p->width - len);
	if (p->width_specified && !p->flag_minus && p->flag_zero)
		ft_putnchar('0', p->width - len);
	ft_putwchar(c);
	if (p->width_specified && p->flag_minus)
		ft_putnchar(' ', p->width - len);
	return ((p->width > 1) ? p->width : len);
}

int		handle_char_err(char c, t_param *p)
{
	if (p->width_specified && !p->flag_minus && !p->flag_zero)
		ft_putnchar(' ', p->width - 1);
	if (p->width_specified && !p->flag_minus && p->flag_zero)
		ft_putnchar('0', p->width - 1);
	ft_putchar(c);
	if (p->width_specified && p->flag_minus)
		ft_putnchar(' ', p->width - 1);
	return ((p->width > 1) ? p->width : 1);
}
