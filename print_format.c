/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:07:34 by gim               #+#    #+#             */
/*   Updated: 2020/10/28 20:15:30 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_info(t_info *info)
{
	info->nbr_base = 10;
	info->nbr_sign = 1;
}

int			print_format(char *buf, va_list ap)
{
	int		len;
	int		ret;
	t_info	*Info;

	ret = 0;
	len = ft_strlen(buf);
	Info = (t_info *)malloc(sizeof(t_info));
	init_info(Info);
	Info->type = buf[len - 1];
	if (Info->type == '%')
		ret = print_char('%');
	else if (Info->type == 'c')
		ret = print_char(va_arg(ap, int));
	else if (Info->type == 's')
		ret = print_str(va_arg(ap, char *));
	else if (Info->type == 'd' || Info->type == 'i')
		ret = print_nbr(va_arg(ap, int));
	else if (Info->type == 'u' || Info->type == 'x' || Info->type == 'X')
		ret = print_nbr(va_arg(ap, unsigned int));
	else if (Info->type == 'p')
		ret = print_nbr(va_arg(ap, unsigned long long));
	free(Info);
	return (ret);
}
