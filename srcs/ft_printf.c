/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:19:02 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/22 21:49:01 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char type, va_list *args)
{
	int	ret;

	ret = 0;
	if (type == '%')
		ret = ft_print_char('%');
	else if (type == 'c')
		ret = ft_print_char(va_arg(*args, int));
	else if (type == 's')
		ret = ft_print_string(va_arg(*args, char *));
	else if (type == 'd' || type == 'i')
		ret = ft_print_int(va_arg(*args, int));
	else if (type == 'u')
		ret = ft_print_uint(va_arg(*args, unsigned int));
	// else if (type == 'p')
	// 	ret = ft_format_addr(va_arg(args, unsigned long int));
	// else if (type == 'x')
	// 	ret = ft_format_hex(va_arg(args, unsigned int), FALSE);
	// else if (type == 'X')
	// 	ret = ft_format_hex(va_arg(args, unsigned int), TRUE);
	return (ret);
}

t_bool	ft_has_subset(const char *s, const char *subset)
{
	int	i;
	int	j;

	if (!s || !subset)
		return (FALSE);
	i = 0;
	while (s[i])
	{
		j = 0;
		while (subset[j])
		{
			if (s[i] == subset[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

int	ft_printf_helper(const char *fmt, va_list *args)
{
	const char	*formatters = "udicsupxX%";
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	while (i < (int)ft_strlen(fmt))
	{
		if (fmt[i] == '%')
		{
			i++;
			if (!ft_has_subset(fmt + i, formatters))
			{
				ret += ft_print_char('%');
				ret += ft_print_char(fmt[i]);
			}
			else
				ret += ft_print_format(fmt[i], args);
		}
		else
			ret += ft_print_char(fmt[i]);
			i++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_printf_helper(format, &args);
	va_end(args);
	return (ret);
}
