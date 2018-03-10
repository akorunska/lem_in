/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 13:36:25 by akorunsk          #+#    #+#             */
/*   Updated: 2017/12/25 13:36:30 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fptr	get_handler(char c, t_param *p)
{
	if (c == 'd' || c == 'i')
		return (handle_int);
	else if (c == 'u')
		return (handle_unsigned);
	else if (c == 's')
		return (handle_string);
	else if (c == 'c')
		return (handle_char);
	else if (c == 'o')
		return (handle_octal);
	else if (c == '%')
		return (handle_percent);
	else if (c == 'x')
		return (handle_hex_l);
	else if (c == 'X')
		return (handle_hex_c);
	else if (c == 'p')
		return (handle_ptr);
	else if (c == 'O' || c == 'U' || c == 'D' || c == 'S' || c == 'C')
	{
		bzero(p->len, 3);
		ft_strcat(p->len, "l");
		return (get_handler(c + ('a' - 'A'), p));
	}
	return (NULL);
}

int		parse_error(const char *str, int pos, t_param *p, int *total)
{
	*total += handle_char_err(str[pos], p);
	return (pos + 1);
}

void	call_parsers(const char *str, t_param *opts, va_list args)
{
	parse_width(str, opts, args);
	parse_flags(str, opts);
	parse_length(str, opts);
}

int		handle_specifier(const char *str, va_list args, int *total)
{
	int		pos;
	t_fptr	f;
	t_param	opts;

	pos = 1;
	initialise(&opts);
	call_parsers(str, &opts, args);
	while (!is_type(str[pos]) && str[pos] != '\0')
	{
		if (str[pos] == '.')
			parse_precision(str + pos, &opts, args);
		if (!is_allowed(str[pos]))
			return (parse_error(str, pos, &opts, total));
		pos++;
	}
	if (opts.precision_specified && opts.precision < 0 && !is_str(str[pos]))
		opts.precision_specified = 0;
	if (str[pos])
	{
		f = get_handler(str[pos], &opts);
		*total += f(args, &opts);
		return (pos + 1);
	}
	return (1);
}
