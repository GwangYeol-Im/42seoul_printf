/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:51:04 by gim               #+#    #+#             */
/*   Updated: 2020/10/09 16:57:40 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_alloc(char *str, char *split, char *dest)
{
	char	*temp;

	*split = '\0';
	if (!dest)
		dest = ft_strdup(str);
	else
	{
		temp = ft_strjoin(dest, str);
		free(dest);
		dest = temp;
	}
	temp = ft_strdup(split + 1);
	free(str);
	str = temp;
	split = temp;
}

int			ft_print_str(va_list *args, char *str)
{
	int		len;
	char	*temp;
	char	*result;

	temp = str;
	while (*str)
	{
		while (*temp != '%' && *temp)
			temp++;
		if (!*temp)
			break ;
		ft_alloc(str, temp, result);
	}
}

int			ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, str);
	len = ft_print_str(&args, (char *)str);
	return (len);
}