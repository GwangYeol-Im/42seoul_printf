/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:28:40 by gim               #+#    #+#             */
/*   Updated: 2020/10/22 22:30:46 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned long long n)
{
	int		len;

	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char		*convert_base(unsigned long long n, char c)
{
	char	*hex;
	char	*result;
	char	temp;
	int		len;

	len = get_len(n);
	hex = (char *)malloc(sizeof(char) * 17);
	hex = "0123456789abcdef";
	result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = 0;
	while (n)
	{
		temp = hex[n % 16];
		if (ft_isalpha(temp))
			temp = c == 'x' ? temp : ft_toupper(temp);
		result[--len] = temp;
		n /= 16;
	}
	return (result);
}
