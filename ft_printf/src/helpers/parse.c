/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <akorunsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 18:48:00 by akorunsk          #+#    #+#             */
/*   Updated: 2018/01/02 18:48:00 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_precision(const char *str, t_param *p, va_list args)
{
	p->precision_specified = 1;
	if (str[1] == '*')
	{
		p->precision = (int)va_arg(args, void*);
	}
	else if (ft_isdigit(str[1]))
		p->precision = ft_atoi(str + 1);
}

void	parse_width_backwards(const char *str, t_param *p, int i)
{
	int		num;

	num = 0;
	while (i >= 1)
	{
		num = ft_isdigit(str[i]);
		if (num && !ft_isdigit(str[i - 1]) && str[i - 1] != '.')
		{
			p->width_specified = 1;
			p->width = ft_atoi(str + i);
			return ;
		}
		if (str[i] == '*' && str[i - 1] != '.')
			return ;
		i--;
	}
}

void	parse_width(const char *str, t_param *p, va_list args)
{
	int		i;

	i = 1;
	while (!is_type(str[i]) && str[i] != '\0')
	{
		if (str[i] == '*' && str[i - 1] != '.')
		{
			p->width_specified = 1;
			p->width = (int)va_arg(args, void*);
			if (p->width < 0)
			{
				p->width = -p->width;
				p->flag_minus = 1;
			}
		}
		i++;
	}
	parse_width_backwards(str, p, i);
}

void	parse_length(const char *str, t_param *p)
{
	int		i;
	char	*found;

	i = 1;
	found = 0;
	while (!is_type(str[i]) && str[i] != '\0' && !found)
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
			found = ft_strcat(p->len, "hh");
		else if (str[i] == 'h')
			found = ft_strcat(p->len, "h");
		else if (str[i] == 'l' && str[i + 1] == 'l')
			found = ft_strcat(p->len, "ll");
		else if (str[i] == 'l')
			found = ft_strcat(p->len, "l");
		else if (str[i] == 'j')
			found = ft_strcat(p->len, "j");
		else if (str[i] == 'z')
			found = ft_strcat(p->len, "z");
		i++;
	}
}

void	parse_flags(const char *str, t_param *p)
{
	int		i;
	int		part_of_digit;

	i = 1;
	part_of_digit = 0;
	while (!is_type(str[i]) && str[i] + '\0')
	{
		if (str[i] == '-')
			p->flag_minus = 1;
		else if (str[i] == '+')
			p->flag_plus = 1;
		else if (str[i] == ' ')
			p->flag_space = 1;
		else if (str[i] == '#')
			p->flag_hash = 1;
		else if (str[i] == '0' && !part_of_digit && str[i - 1] != '.')
			p->flag_zero = 1;
		if (str[i] != 0 && ft_isdigit(str[i]))
			part_of_digit = 1;
		else
			part_of_digit = 0;
		i++;
	}
}
