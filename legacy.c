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
	else if (spec == 'p')
	{
		print("0x");
		print(convert_base(spec_list->addr = va_arg(ap, unsigned long long), 'x'));
	}
	else if (spec == 's')
		print(spec_list->content = va_arg(ap, char *));
	else if (spec == 'd' || spec == 'i')
		print(ft_itoa(spec_list->i = va_arg(ap, int)));
	else if (spec == 'u')
		print(itoa_ui(spec_list->ui = va_arg(ap, unsigned int)));
	else if (spec == 'x')
		print(convert_base(spec_list->ui = va_arg(ap, unsigned int), spec));
	else if (spec == 'X')
		print(convert_base(spec_list->ui = va_arg(ap, unsigned int), spec));
	else if (spec == '%')
		print("%");
	free(spec_list);
	return (1);
}

int			ft_printf(const char *str, ...)
{
	int		idx;
	int		fprint;
	char	*format;
	va_list	ap;

	va_start(ap, str);
	idx = 0;
	while (str[idx])
	{
		while (str[idx] && str[idx] != '%')
			write(1, &str[idx++], 1);
		if (!str[idx])
			break ;
		fprint = ++idx;
		while (str[idx] && !check_specifier(str[idx]))
			idx++;
		if (!(format = ft_substr(str, fprint, idx - fprint + 1)) \
			|| !(str[idx] && print_format(format, str[idx], ap)))
			return (-1);
		free(format);
		idx++;
	}
	va_end(ap);
	return (0);
}

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
