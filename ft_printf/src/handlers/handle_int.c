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

void		handle_zero_flag_d(long long int val, t_param *p, char zero)
{
	int			i;
	int			digits;
	int			outp;

	i = 0;
	if (!p->precision_specified)
		outp = 1;
	else
		outp = 0;
	if (p->width_specified && p->flag_zero && !p->flag_minus && outp)
	{
		digits = count_digits(val) + count_additional_len_d('d', p, val);
		if (val < 0)
		{
			ft_putchar('-');
			p->sign_outputted = 1;
		}
		while (i + digits < p->width)
		{
			ft_putchar(zero);
			i++;
		}
	}
}

void		call_handlers(long long int val, t_param *p)
{
	handle_flags_d('d', p, val);
	handle_prec(val, p, '0');
	handle_zero_flag_d(val, p, '0');
}

int			handle_int(va_list args, t_param *p)
{
	long long int	val;
	int				len;

	val = convert_signed(args, p);
	len = (p->precision > count_digits(val)) ? p->precision : \
		count_digits(val) + count_additional_len_d('d', p, val);
	if (p->precision >= count_digits(val) && \
	(p->flag_space || p->flag_plus) && val >= 0)
		len++;
	if (p->precision >= count_digits(val) && val < 0)
		len++;
	if (p->width_specified && p->precision_specified && \
		p->width > p->precision)
		p->flag_zero = 0;
	if (p->precision_specified && !p->precision && !val)
		len = 0;
	if (p->width_specified && !p->flag_minus && !p->flag_zero)
		ft_putnchar(' ', p->width - len);
	call_handlers(val, p);
	if (!(p->precision_specified && !p->precision && !val))
		ft_putnbr_ll(val, p);
	if (p->width_specified && p->flag_minus)
		ft_putnchar(' ', p->width - len);
	return ((p->width > len) ? p->width : len);
}

int			handle_unsigned(va_list args, t_param *p)
{
	unsigned long long int	val;
	int						len;

	val = convert_unsigned(args, p);
	len = (p->precision >= count_digits_base(val, 10)) ? p->precision : \
		count_digits_base(val, 10);
	if (p->width_specified && !p->flag_minus && !p->flag_zero)
		ft_putnchar(' ', p->width - len);
	handle_prec_u(val, p, '0', 10);
	handle_zero_flag_u(val, p, 'u', 10);
	if (!(p->precision_specified && !p->precision && !val))
		ft_putnbr_llu(val);
	else
		len = 0;
	if (p->width_specified && p->flag_minus)
		ft_putnchar(' ', p->width - len);
	return ((p->width > len) ? p->width : len);
}
