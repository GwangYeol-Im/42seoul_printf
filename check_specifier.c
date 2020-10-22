/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:00:10 by gim               #+#    #+#             */
/*   Updated: 2020/10/22 16:16:47 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_specifier(char c)
{
	char	*formats;
	int		i;

	formats = ft_strdup("cspdiuxX%");
	i = 0;
	while (formats[i])
	{
		if (formats[i++] == c)
		{
			free(formats);
			return (1);
		}
	}
	free(formats);
	return (0);
}
