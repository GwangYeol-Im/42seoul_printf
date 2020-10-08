/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:43:14 by gim               #+#    #+#             */
/*   Updated: 2020/09/30 14:13:49 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		idx;
	char	*new_s1;
	char	*new_s2;
	char	*join;

	new_s1 = (char *)s1;
	new_s2 = (char *)s2;
	len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (len + 1));
	if (!join)
		return (0);
	idx = 0;
	while (*s1)
		join[idx++] = *s1++;
	while (*s2)
		join[idx++] = *s2++;
	join[idx] = '\0';
	return (join);
}
