/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:00:10 by gim               #+#    #+#             */
/*   Updated: 2020/10/09 17:03:43 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_format(char c)
{
	char	*formats;

	formats = "cspdiuxX%";
	while (*formats == c)
		if (!*formats++)
			return (0);
	return (1);
}
