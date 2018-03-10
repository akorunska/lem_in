/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <akorunsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:38:00 by akorunsk          #+#    #+#             */
/*   Updated: 2018/01/03 17:38:00 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_additional_len_ox(char type, t_param *p,
									unsigned long long int val)
{
	if (type == 'o' && p->flag_hash && \
	(val || (!p->precision && p->precision_specified)))
		return (1);
	else if (type == 'x' && p->flag_hash && \
	(val || (!p->precision && p->precision_specified)))
		return (2);
	else if (type == 'X' && p->flag_hash && \
	(val || (!p->precision && p->precision_specified)))
		return (2);
	else if (type == 'p')
		return (2);
	return (0);
}

void	handle_flags_ox(char type, t_param *p, \
		unsigned long long int val)
{
	if (type == 'o' && p->flag_hash && val)
		ft_putchar('0');
	else if (type == 'x' && p->flag_hash && val)
		ft_putstr("0x");
	else if (type == 'X' && p->flag_hash && val)
		ft_putstr("0X");
	else if (type == 'p')
		ft_putstr("0x");
}

int		count_additional_len_d(char type, t_param *p, \
		long long int val)
{
	if (type == 'd' && p->flag_plus && val >= 0)
		return (1);
	else if (type == 'd' && p->flag_space && val >= 0)
		return (1);
	return (0);
}

void	handle_flags_d(char type, t_param *p, \
		long long int val)
{
	if (type == 'd' && p->flag_plus && val >= 0)
		ft_putchar('+');
	if (p->flag_space && !p->flag_plus && val >= 0)
		ft_putchar(' ');
}

void	handle_zero_flag_u(long long unsigned int val, \
			t_param *p, char type, int base)
{
	int			i;
	int			digits;

	i = 0;
	if (p->width_specified && p->flag_zero && !p->flag_minus)
	{
		digits = count_digits_base(val, base) + \
		count_additional_len_ox(type, p, val);
		while (i + digits < p->width)
		{
			ft_putchar('0');
			i++;
		}
	}
}
