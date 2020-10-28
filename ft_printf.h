/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:51:21 by gim               #+#    #+#             */
/*   Updated: 2020/10/28 20:14:11 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define EMPTY ""
# define TYPE "cspdiuxX%"

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
	int			nbr_base;
	int			nbr_sign;
}				t_info;

int				ft_printf(const char *str, ...);
int				parse_str(char *str, va_list ap);
int				put_str(char *str, int i, int *ret);
int				check_specifier(char *str, int i);
int				print_format(char *buf, va_list ap);
int				print_char(int c);
int				print_str(char *str);
int				print_nbr(unsigned long long n);
#endif
