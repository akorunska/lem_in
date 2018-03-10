/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <akorunsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:53:00 by akorunsk          #+#    #+#             */
/*   Updated: 2018/01/02 16:53:00 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_digits_base(long long unsigned int n, int base)
{
	int res;

	res = 1;
	while (n / base > 0)
	{
		n /= base;
		res++;
	}
	return (res);
}

int		count_digits(long long int n)
{
	long long int res;

	res = 1;
	if (n < 0)
	{
		if (n + 1 == (long long int)-9223372036854775807)
		{
			return (20);
		}
		n = -n;
		res++;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

void	handle_prec_u(long long int val, t_param *p, \
				char zero, int base)
{
	int i;
	int	digits;
	int type;

	i = 0;
	if (p->precision_specified)
	{
		if (!p->precision && !val)
			return ;
		if (base == 10)
			type = 'd';
		else
			type = (base == 16) ? 'x' : 'o';
		digits = count_digits_base(val, base);
		if (!(p->flag_hash && base == 16))
			digits += count_additional_len_ox(type, p, val);
		while (i + digits < p->precision)
		{
			ft_putchar(zero);
			i++;
		}
	}
}

void	handle_prec(long long int val, t_param *p, char zero)
{
	int i;
	int	digits;

	i = 0;
	if (p->precision_specified)
	{
		digits = count_digits(val) + \
		count_additional_len_d('d', p, val);
		if ((p->flag_space || p->flag_plus) && val >= 0)
			digits--;
		if (val < 0)
		{
			digits -= 1;
			ft_putchar('-');
			p->sign_outputted = 1;
		}
		while (i + digits < p->precision)
		{
			ft_putchar(zero);
			i++;
		}
	}
}
