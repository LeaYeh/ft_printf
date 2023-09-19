/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:59:33 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/19 16:36:42 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_hex(unsigned int n, t_bool is_upper, t_print_tab *tab)
{
	char	*ret;
	char	*num_str;
	char	pad_char;
	char	*formatted_perc;
	char	*formatted_suffix;

	pad_char = ' ';
	if (tab->f_zero_pad)
		pad_char = '0';
	num_str = ft_utox(n, is_upper);
	formatted_perc = ft_format_persicion(num_str, tab);
	formatted_suffix = ft_format_suffix(formatted_perc, is_upper, tab);
	tab->total_len = ft_max(2, tab->width, ft_strlen(num_str));
	ret = ft_format_padding(formatted_suffix, pad_char, tab);
	free(num_str);
	free(formatted_perc);
	free(formatted_suffix);
	return (ret);
}
