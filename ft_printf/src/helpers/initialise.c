/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <akorunsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:45:00 by akorunsk          #+#    #+#             */
/*   Updated: 2018/01/02 15:45:00 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		initialise(t_param *p)
{
	p->precision_specified = 0;
	p->precision = 0;
	p->width_specified = 0;
	p->width = 0;
	p->flag_plus = 0;
	p->flag_minus = 0;
	p->flag_space = 0;
	p->flag_hash = 0;
	p->flag_zero = 0;
	p->sign_outputted = 0;
	ft_bzero(p->len, 3);
}
