/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:51:04 by gim               #+#    #+#             */
/*   Updated: 2020/10/09 17:19:41 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_alloc(char *str, int idx, char *dest)
{
	char	*temp;

	str[idx] = '\0';
	if (!dest)
		dest = ft_strdup(str);
	else
	{
		temp = ft_strjoin(dest, str);
		free(dest);
		dest = temp;
	}
	temp = ft_strdup(str[idx] + 1);
	free(str);
	str = temp;
	return (idx);
}

int			ft_print_str(va_list *args, char *str)
{
	int		len;
	int		idx;
	char	*temp;
	char	*result;

	len = 0;
	idx = 0;
	while (str[idx])
	{
		while (str[idx] != '%' && str[idx])
			idx++;
		if (!str[idx])
			break ;
		len += ft_alloc(str, idx, result);
		idx = 0;
		while (!check_format(str[idx]))
			idx++;
	}
	write(1, result, ft_strlen(result));
	return (len);
}

int			ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, str);
	len = ft_print_str(&args, (char *)str);
	return (len);
}