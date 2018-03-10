/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <akorunsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 17:48:00 by akorunsk          #+#    #+#             */
/*   Updated: 2018/01/02 17:48:00 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_hex_l(va_list args, t_param *p)
{
	unsigned long long int		val;
	int							len;

	val = convert_unsigned(args, p);
	len = (p->precision > count_digits_base(val, 16)) ? p->precision \
		: count_digits_base(val, 16);
	if (p->precision_specified && !p->precision && !val)
		len = 0;
	len += count_additional_len_ox('x', p, val);
	if (p->width_specified && !p->flag_minus && !p->flag_zero)
		ft_putnchar(' ', p->width - len);
	handle_flags_ox('x', p, val);
	handle_prec_u(val, p, '0', 16);
	handle_zero_flag_u(val, p, 'x', 16);
	if (!(p->precision_specified && !p->precision && !val))
		ft_putnbr_long_base(val, 16, 'a');
	else
		len = 0;
	if (p->width_specified && p->flag_minus)
		ft_putnchar(' ', p->width - len);
	return ((p->width > len) ? p->width : len);
}

int		handle_hex_c(va_list args, t_param *p)
{
	unsigned long long int		val;
	int							len;

	val = convert_unsigned(args, p);
	len = (p->precision > count_digits_base(val, 16)) ? p->precision \
		: count_digits_base(val, 16);
	if (p->precision_specified && !p->precision && !val)
		len = 0;
	len += count_additional_len_ox('X', p, val);
	if (p->width_specified && !p->flag_minus && !p->flag_zero)
		ft_putnchar(' ', p->width - len);
	handle_flags_ox('X', p, val);
	handle_prec_u(val, p, '0', 16);
	handle_zero_flag_u(val, p, 'X', 16);
	if (!(p->precision_specified && !p->precision && !val))
		ft_putnbr_long_base(val, 16, 'A');
	else
		len = 0;
	if (p->width_specified && p->flag_minus)
		ft_putnchar(' ', p->width - len);
	return ((p->width > len) ? p->width : len);
}

int		handle_ptr(va_list args, t_param *p)
{
	unsigned long int		val;
	int						len;

	p->flag_hash = 1;
	val = (unsigned long int)va_arg(args, void*);
	len = (p->precision > count_digits_base(val, 16)) ? p->precision \
		: count_digits_base(val, 16);
	len += count_additional_len_ox('p', p, val);
	if (p->width_specified && !p->flag_minus && !p->flag_zero)
		ft_putnchar(' ', p->width - len);
	handle_flags_ox('p', p, val);
	handle_prec_u(val, p, '0', 16);
	handle_zero_flag_u(val, p, 'p', 16);
	if (!(p->precision_specified && !p->precision && !val))
		ft_putnbr_long_base(val, 16, 'a');
	else
		len = count_additional_len_ox('p', p, val);
	if (p->width_specified && p->flag_minus)
		ft_putnchar(' ', p->width - len);
	return ((p->width > len) ? p->width : len);
}
