/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:08:02 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/15 21:52:02 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_free_print()
// {}

// const char	*formatters = "cdsupxX%";
char	*ft_eval_format(const char *fmt, int i, t_print_tab *tab)
{
	char	*ret;

	ret = NULL;
	ft_setup_print_table(fmt, i, tab);
	if (tab->type == '%')
	{
		tab->total_len += 1;
		ret = ft_strdup("%");
	}
	else if (tab->type == 'c')
		ret = ft_format_char(va_arg(tab->args, int), tab);
	else if (tab->type == 's')
		ret = ft_format_string(va_arg(tab->args, char *), tab);
	else if (tab->type == 'd' || tab->type == 'i')
		ret = ft_format_decimal(va_arg(tab->args, int), tab);
	else if (tab->type == 'u')
		ret = NULL;
	else if (tab->type == 'p')
		ret = NULL;
	else if (tab->type == 'x')
		ret = NULL;
	else if (tab->type == 'X')
		ret = NULL;
	if (ret == NULL)
		free(tab);
	return (ret);
}

void	_print_out(const char *fmt, int i, t_print_tab *tab)
{
	char		*formatted_str;

	formatted_str = ft_eval_format(fmt, i, tab);
	ft_putstr_fd(formatted_str, 1);
	free(formatted_str);
}

int	ft_printf(const char *format, ...)
{
	t_print_tab	*tab;
	int			ret;
	int			i;

	tab = (t_print_tab *)malloc(sizeof(t_print_tab));
	if (!tab || !format)
		return (-1);
	va_start(tab->args, format);
	ret = 0;
	i = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			_print_out(format, i + 1, tab);
			i += tab->fmt_len;
			ret += tab->total_len;
		}
		else
			ret += write(1, format + i, 1);
		i++;
	}
	va_end(tab->args);
	// ft_print_table_status(tab);
	free(tab);
	return (ret);
}
