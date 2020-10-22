/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:42:25 by gim               #+#    #+#             */
/*   Updated: 2020/10/22 17:40:55 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int    get_ui_len(unsigned int n)
{
	int		len;

    len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		    *itoa_ui(unsigned int n)
{
	int		    len;
	char	    *str;

	len = get_ui_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	if (n == 0)
		str[0] = '0';
	while (--len >= 0 && n)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
