/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:12:41 by akorunsk          #+#    #+#             */
/*   Updated: 2017/12/26 15:12:43 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_percent(va_list args, t_param *p)
{
	if (p->width_specified && !p->flag_minus && !p->flag_zero)
		ft_putnchar(' ', p->width - 1);
	if (p->width_specified && !p->flag_minus && p->flag_zero)
		ft_putnchar('0', p->width - 1);
	if (args)
		ft_putchar('%');
	else
		ft_putchar('%');
	if (p->width_specified && p->flag_minus)
		ft_putnchar(' ', p->width - 1);
	return ((p->width > 1) ? p->width : 1);
}
