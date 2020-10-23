/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:43:39 by gim               #+#    #+#             */
/*   Updated: 2020/10/23 15:58:48 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define TYPE "cspdiuxX%"

int			print_format(char *buf, int *ret, va_list ap)
{
	
}

int			check_specifier(char *str, int i)
{
	int		idx;

	while (str[i])
	{
		idx = 0;
		while (TYPE[idx])
			if (TYPE[idx++] == str[i])
				return (i);
		i++;
	}
	return (i);
}

int			print_str(char *str, int i, int *ret)
{
	while (str[i] && str[i] != '%')
	{
		write(1, &str[i++], 1);
		*ret += 1;
	}
	return (i);
}

int			parse_str(char *str, va_list ap)
{
	int		ret;
	int		i;
	int		save;
	char	*buf;

	ret = 0;
	i = 0;
	while (str[i])
	{
		i = print_str(str, i, &ret);
		if (!str[i])
			break ;
		save = ++i;
		i = check_specifier(str, i);
		buf = ft_substr(str, save, i - save + 1);
		if (!buf || buf == EMPTY || str[i])
			return (-1);
		if (!print_format(buf, &ret, ap))
			return (-1);
		free(buf);
	}
	return (ret);
}

int			ft_printf(const char *str, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, str);
	ret = parse_str((char *)str, ap);
	va_end(ap);
	return (ret);
}