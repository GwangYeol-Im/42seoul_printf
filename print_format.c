/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:07:34 by gim               #+#    #+#             */
/*   Updated: 2020/10/22 17:27:28 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_format(const char *format, char spec, va_list ap)
{
	t_spec	*spec_list;
	char	*temp;

	temp = (char *)format;
	spec_list = (t_spec *)malloc(sizeof(t_spec));
	if (spec == 'c')
	{
		spec_list->c = va_arg(ap, int);
		print(&spec_list->c);
	}
	else if (spec == 's')
		print(spec_list->content = va_arg(ap, char *));
	else if (spec == 'd' || spec == 'i')
		print(ft_itoa(spec_list->i = va_arg(ap, int)));
	else if (spec == 'u')
		print(itoa_ui(spec_list->ui = va_arg(ap, unsigned int)));
	else if (spec == 'x' || spec == 'X')
		print("1");
	else if (spec == '%')
		print("%");
	free(spec_list);
	return (1);
}
