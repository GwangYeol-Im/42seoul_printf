/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:43:39 by gim               #+#    #+#             */
/*   Updated: 2020/10/28 20:27:29 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_specifier(char *str, int i)
{
	int		idx;
	int		type_i;

	idx = i;
	while (str[idx])
	{
		type_i = 0;
		while (TYPE[type_i])
			if (TYPE[type_i++] == str[idx])
				return (idx);
		idx++;
	}
	return (idx);
}

int			put_str(char *str, int i, int *ret)
{
	int		idx;

	idx = i;
	while (str[idx] && str[idx] != '%')
	{
		write(1, &str[idx++], 1);
		*ret += 1;
	}
	return (idx);
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
		i = put_str(str, i, &ret);
		if (!str[i])
			break ;
		save = ++i;
		i = check_specifier(str, i);
		if (!(buf = ft_substr(str, save, i - save + 1)))
			return (-1);
		ret += print_format(buf, ap);
		free(buf);
		i++;
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
