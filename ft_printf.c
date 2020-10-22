/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:13:03 by gim               #+#    #+#             */
/*   Updated: 2020/10/22 13:23:22 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	int		idx;
	int		fprint;
	char	*format;
	va_list	ap;

	va_start(ap, str);
	idx = 0;
	while (str[idx])
	{
		while (str[idx] && str[idx] != '%')
			print(&str[idx++]);
		fprint = ++idx;
		while (str[idx] && !check_specifier(str[idx]))
			idx++;
		format = ft_substr(str, fprint, idx - fprint);
		if (!(str[idx] && print_format(format, str[idx], ap)))
			return (-1);
		free(format);
	}
	return (0);
}
