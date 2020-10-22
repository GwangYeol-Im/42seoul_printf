/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:00:10 by gim               #+#    #+#             */
/*   Updated: 2020/10/22 11:55:06 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_specifier(char c)
{
	char	*formats;

	formats = ft_strdup("cspdiuxX%");
	while (*formats == c)
	{
		if (!*formats++)
		{
			free(formats);
			return (0);
		}
	}
	free(formats);
	return (1);
}
