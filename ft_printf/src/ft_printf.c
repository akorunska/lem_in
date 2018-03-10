/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:13:03 by akorunsk          #+#    #+#             */
/*   Updated: 2017/12/01 10:21:34 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdarg.h"

int		ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*pos = format;
	int			t;

	va_start(args, format);
	t = 0;
	while (*pos != '\0')
	{
		if (*pos != '%')
		{
			ft_putchar(*pos++);
			t++;
		}
		else
			pos += handle_specifier(pos, args, &t);
	}
	va_end(args);
	return (t);
}
