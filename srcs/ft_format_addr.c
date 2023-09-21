/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:39:31 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/21 17:57:44 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_skip_hexzero(char *num_str)
{
	while (*num_str == '0' && ft_strlen(num_str) > 1)
		num_str++;
	return (ft_strdup(num_str));
}

char	*ft_format_addr(unsigned long int n, t_print_tab *tab)
{
	char	*ret;
	char	*num_str;
	char	pad_char;
	char	*formatted_perc;
	char	*formatted_suffix;

	pad_char = ' ';
	if (tab->f_zero_pad)
		pad_char = '0';
	if ((void *)n == NULL)
		num_str = ft_strdup("(nil)");
	else
		num_str = ft_utox(n, FALSE);
	formatted_perc = _skip_hexzero(num_str);
	formatted_suffix = ft_format_suffix(formatted_perc, FALSE, tab);
	tab->total_len = ft_max(2, tab->width, ft_strlen(formatted_suffix));
	ret = ft_format_padding(formatted_suffix, pad_char, tab, FALSE);
	free(num_str);
	free(formatted_perc);
	free(formatted_suffix);
	return (ret);
}
