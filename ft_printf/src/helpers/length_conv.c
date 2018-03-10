/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:24:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/01/06 17:24:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int				convert_signed(va_list args, t_param *p)
{
	long long int val;

	if (!ft_strcmp(p->len, "hh"))
		val = (signed char)va_arg(args, void*);
	else if (!ft_strcmp(p->len, "h"))
		val = (short int)va_arg(args, void*);
	else if (!ft_strcmp(p->len, "l"))
		val = (long int)va_arg(args, void*);
	else if (!ft_strcmp(p->len, "ll"))
		val = (long long int)va_arg(args, void*);
	else if (!ft_strcmp(p->len, "j"))
		val = (long int)va_arg(args, void*);
	else if (!ft_strcmp(p->len, "z"))
		val = (size_t)va_arg(args, void*);
	else
		val = (int)va_arg(args, void*);
	return (val);
}

long long unsigned int		convert_unsigned(va_list args, t_param *p)
{
	long long unsigned int val;

	if (!ft_strcmp(p->len, "hh"))
		val = (unsigned char)va_arg(args, void*);
	else if (!ft_strcmp(p->len, "h"))
		val = (unsigned short int)va_arg(args, void*);
	else if (!ft_strcmp(p->len, "l"))
		val = (unsigned long int)va_arg(args, void*);
	else if (!ft_strcmp(p->len, "ll"))
		val = (unsigned long long int)va_arg(args, void*);
	else if (!ft_strcmp(p->len, "j"))
		val = (unsigned long int)va_arg(args, void*);
	else if (!ft_strcmp(p->len, "z"))
		val = (size_t)va_arg(args, void*);
	else
		val = (unsigned int)va_arg(args, void*);
	return (val);
}
