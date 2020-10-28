/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:07:34 by gim               #+#    #+#             */
/*   Updated: 2020/10/28 20:58:00 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_info(t_info *info)
{
	info->nbr_base = 10;
	info->nbr_sign = 1;
}

void		check_info(char *buf, t_info *info)
{
	int		idx;

	idx = 0;
	while (buf[idx])
	{
		if (ft_isdigit(buf[idx]))
		{
			if (buf[idx] == '0')
				info->zero = 1;
			else
				info->width = buf[idx] - '0';
		}
		else if (buf[idx] == '-')
			info->minus = 1;
	}
	if (info->minus == 1)
		info->zero = 0;
	info->type = buf[idx - 1];
}

int			print_format(char *buf, va_list ap)
{
	int		len;
	int		ret;
	t_info	*info;

	ret = 0;
	len = ft_strlen(buf);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	init_info(info);
	check_info(buf, info);
	if (info->type == '%')
		ret = print_char('%');
	else if (info->type == 'c')
		ret = print_char(va_arg(ap, int));
	else if (info->type == 's')
		ret = print_str(va_arg(ap, char *));
	else if (info->type == 'd' || info->type == 'i')
		ret = print_nbr(va_arg(ap, int));
	else if (info->type == 'u' || info->type == 'x' || info->type == 'X')
		ret = print_nbr(va_arg(ap, unsigned int));
	else if (info->type == 'p')
		ret = print_nbr(va_arg(ap, unsigned long long));
	free(info);
	return (ret);
}
