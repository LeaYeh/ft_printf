/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:59:33 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/17 18:52:47 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_suffix(char *s, t_bool is_upper, t_print_tab *tab)
{
	char	*ret;

	if (!tab->f_hash)
		return (s);
	if (is_upper)
		ret = ft_strjoin("0x", s);
	else
		ret = ft_strjoin("0X", s);
	return (ret);
}

char	*ft_format_hex(unsigned int n, t_bool is_upper, t_print_tab *tab)
{
	char	*ret;
	char	*num_str;
	char	pad_char;
	char	*formatted_perc;

	pad_char = ' ';
	if (tab->f_zero_pad)
		pad_char = '0';
	num_str = ft_utox(n, 8, is_upper);
	formatted_perc = ft_format_persicion(num_str, tab->perc_len, tab);
	formatted_perc = ft_format_suffix(formatted_perc, is_upper, tab);
	tab->total_len = ft_max(tab->width, ft_strlen(num_str));
	ret = ft_format_padding(
			formatted_perc,
			pad_char,
			tab->total_len,
			tab->f_dash);
	free(num_str);
	free(formatted_perc);
	return (ret);
}
