/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:08:03 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/22 22:58:10 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_format_suffix(char *s, t_bool is_upper)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (ft_strncmp(s, "(nil)", 5) == 0)
		return (ft_strdup(s));
	if (is_upper)
		ret = ft_strjoin("0X", s);
	else
		ret = ft_strjoin("0x", s);
	return (ret);
}

int	ft_print_addr(unsigned long int n)
{
	char	*num_str;
	char	*formatted_suffix;
	int		len;

	if ((void *)n == NULL)
		return (write(1, "(nil)", 5));
	num_str = ft_utox(n, FALSE);
	formatted_suffix = _format_suffix(num_str, FALSE);
	len = ft_strlen(formatted_suffix);
	write(1, formatted_suffix, len);
	free(num_str);
	free(formatted_suffix);
	return (len);
}
