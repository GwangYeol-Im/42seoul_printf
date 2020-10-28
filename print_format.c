/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:07:34 by gim               #+#    #+#             */
/*   Updated: 2020/10/28 21:52:30 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_info(t_info *info)
{
	info->minus = 0;
	info->width = 0;
	info->zero = 0;
	info->prec = 0;
	info->nbr_base = 10;
	info->nbr_sign = 1;
}

void		check_width_and_prec(char c, t_info *info, va_list ap)
{
	
}

void		check_info(char *buf, t_info *info, va_list ap)
{
	int		idx;

	idx = 0;
	while (!ft_strrchr(TYPE, buf[idx]))
	{
		if (buf[idx] == '0' && info->width == 0 && info->prec == 0)
			info->zero = 1;
		else if (buf[idx] == '-')
			info->minus = 1;
		else if (buf[idx] == '.')
			info->prec = 1;
		else if (ft_isdigit(buf[idx]) || buf[idx] == '*')
			check_width_and_prec(buf[idx], info, ap);
	}
	info->type = buf[idx];
	if (info->minus == 1)
		info->zero = 0;
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
	check_info(buf, info, ap);
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
