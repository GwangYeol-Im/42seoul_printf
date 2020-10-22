/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:51:21 by gim               #+#    #+#             */
/*   Updated: 2020/10/09 17:17:09 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define EMPTY ""

#include "./libft/libft.h"
#include <stdarg.h>

int			ft_printf(const char *, ...);
int			check_format(char c);

#endif
