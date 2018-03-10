/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <akorunsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:47:00 by akorunsk          #+#    #+#             */
/*   Updated: 2018/01/02 16:47:00 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_octal(va_list args, t_param *p)
{
	unsigned long long int	val;
	int						len;

	val = convert_unsigned(args, p);
	len = (p->precision > count_digits_base(val, 8)) ? p->precision :
		count_digits_base(val, 8) + count_additional_len_ox('o', p, val);
	if (p->precision_specified && !p->precision && !val)
		len = count_additional_len_ox('o', p, val);
	if (p->width_specified && !p->flag_minus && !p->flag_zero)
		ft_putnchar(' ', p->width - len);
	handle_flags_ox('o', p, val);
	handle_prec_u(val, p, '0', 8);
	handle_zero_flag_u(val, p, 'o', 8);
	if (!(p->precision_specified && !p->precision && !val && !p->flag_hash))
		ft_putnbr_long_base(val, 8, 'a');
	else
		len = count_additional_len_ox('o', p, val);
	if (p->width_specified && p->flag_minus)
		ft_putnchar(' ', p->width - len);
	return ((p->width > len) ? p->width : len);
}
