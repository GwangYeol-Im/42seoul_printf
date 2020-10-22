/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:51:21 by gim               #+#    #+#             */
/*   Updated: 2020/10/22 13:26:17 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define EMPTY ""

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct		s_spec
{
	int				i;
	unsigned int	ui;
	char			c;
	void			*content;
}					t_spec;

int					ft_printf(const char *str, ...);
int					check_format(char c);
int					check_specifier(char c);
int					print_format(const char *format, char spec, va_list ap);
void				print(const char *str);

#endif
