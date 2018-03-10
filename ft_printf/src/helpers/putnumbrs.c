/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnumbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:08:56 by akorunsk          #+#    #+#             */
/*   Updated: 2018/01/02 16:09:02 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_abs(long long int n)
{
	return ((n > 0) ? n : -n);
}

void			ft_putnbr_ll(long long int n, t_param *p)
{
	if (n < 0)
	{
		if (!p->sign_outputted)
		{
			ft_putchar('-');
			p->sign_outputted = 1;
		}
	}
	if (ft_abs(n / 10) > 0)
	{
		ft_putnbr_ll(n / 10, p);
	}
	ft_putchar('0' + ft_abs(n % 10));
}

void			ft_putnbr_llu(long long unsigned int n)
{
	if (n / 10 > 0)
	{
		ft_putnbr_llu(n / 10);
	}
	ft_putchar('0' + n % 10);
}

void			ft_putnbr_base(unsigned int n, int base, char seed)
{
	char	output;

	if (n / base > 0)
	{
		ft_putnbr_base(n / base, base, seed);
	}
	if (n % base >= 10)
		output = seed + (n % base - 10);
	else
		output = '0' + n % base;
	ft_putchar(output);
}

void			ft_putnbr_long_base(unsigned long long int n, int base, \
									char seed)
{
	char	output;

	if (n / base > 0)
	{
		ft_putnbr_long_base(n / base, base, seed);
	}
	if (n % base >= 10)
		output = seed + (n % base - 10);
	else
		output = '0' + n % base;
	ft_putchar(output);
}
