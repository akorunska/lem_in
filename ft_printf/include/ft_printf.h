/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:46:30 by akorunsk          #+#    #+#             */
/*   Updated: 2017/11/28 17:52:24 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include "stdarg.h"

typedef struct			s_param
{
	int		precision_specified;
	int		precision;
	int		width_specified;
	int		width;
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_hash;
	int		flag_zero;
	int		sign_outputted;
	char	len[3];
}						t_param;

typedef int				(*t_fptr)(va_list args, t_param *p);

int						ft_printf(const char *format, ...);
int						handle_specifier(const char *str, va_list args, \
						int *total);
int						is_type(char c);
int						is_str(char c);
int						is_allowed(char c);
void					initialise(t_param *p);
void					parse_length(const char *str, t_param *p);

void					parse_precision(const char *str, t_param *p, \
						va_list args);
void					parse_width(const char *str, t_param *p, \
						va_list args);
void					parse_flags(const char *str, t_param *p);
void					parse_length(const char *str, t_param *p);

long long int			convert_signed(va_list args, t_param *p);
long long unsigned int	convert_unsigned(va_list args, t_param *p);

int						count_additional_len_ox(char type, t_param *p, \
						unsigned long long int val);
void					handle_flags_ox(char type, t_param *p, \
						unsigned long long int val);
int						count_additional_len_d(char type, t_param *p, \
						long long int val);
void					handle_flags_d(char type, t_param *p, \
						long long int val);
void					handle_zero_flag_u(unsigned long long int val, \
						t_param *p, char zero, int base);

int						handle_int(va_list args, t_param *p);
int						handle_char(va_list args, t_param *p);
int						handle_wchar(va_list args, t_param *p);
int						handle_string(va_list args, t_param *p);
int						handle_wstring(va_list args, t_param *p);
int						handle_percent(va_list args, t_param *p);
int						handle_unsigned(va_list args, t_param *p);
int						handle_octal(va_list args, t_param *p);
int						handle_hex_l(va_list args, t_param *p);
int						handle_hex_c(va_list args, t_param *p);
int						handle_ptr(va_list args, t_param *p);
int						handle_char_err(char c, t_param *p);
int						ft_putnstr(char *str, int to_output);

int						get_wchar_len(int c);
void					ft_putwchar(int c);

void					ft_putnchar(char c, int n);
void					ft_putnbr_ll(long long int n, t_param *p);
void					ft_putnbr_llu(long long unsigned int n);
void					ft_putnbr_long_base(unsigned long long int n, \
						int base, char seed);
int						count_digits_base(long long unsigned int n, \
						int base);
int						count_digits(long long int n);
void					handle_prec(long long int val, t_param *p, char zero);
void					handle_prec_u(long long int val, t_param *p, \
						char zero, int base);

#endif
