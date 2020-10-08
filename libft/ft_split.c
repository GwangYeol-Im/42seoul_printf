/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:55:51 by gim               #+#    #+#             */
/*   Updated: 2020/10/08 14:22:29 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_units(char const *s, char c)
{
	int		len;
	int		idx;

	len = 0;
	idx = 0;
	while (s[idx])
	{
		while (s[idx] == c && s[idx])
			idx++;
		if (!s[idx])
			return (len);
		len++;
		while (s[idx] != c && s[idx])
			idx++;
	}
	return (len);
}

char		*get_unit(char const *s, int srt, int end)
{
	char	*unit;
	int		idx;

	if (!(unit = malloc(sizeof(char) * (end - srt + 1))))
		return (0);
	idx = 0;
	while (srt < end)
		unit[idx++] = s[srt++];
	unit[idx] = 0;
	return (unit);
}

void		free_split(char **split)
{
	int		idx;

	idx = 0;
	while (split[idx])
		free(split[idx++]);
	free(split);
}

int			get_split(char const *s, char c, char **split)
{
	int		idx;
	int		split_i;
	int		foot_print;

	split_i = 0;
	idx = 0;
	while (s[idx])
	{
		while (s[idx] == c && s[idx])
			idx++;
		if (!s[idx])
			return (1);
		foot_print = idx;
		while (s[idx] != c && s[idx])
			idx++;
		if (!(split[split_i++] = get_unit(s, foot_print, idx)))
		{
			free_split(split);
			return (0);
		}
	}
	return (1);
}

char		**ft_split(char const *s, char c)
{
	int		len;
	char	**split;

	len = count_units(s, c);
	if (!(split = malloc(sizeof(char *) * (len + 1))))
		return (0);
	split[len] = 0;
	if (!(get_split(s, c, split)))
		return (0);
	return (split);
}
