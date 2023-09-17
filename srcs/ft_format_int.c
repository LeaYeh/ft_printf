/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:07:15 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/15 22:57:40 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_int(int n, t_print_tab *tab)
{
	char	*ret;
	char	pad_char;
	char	*num_str;
	char	*formatted_perc;

	pad_char = ' ';
	if (tab->f_zero_pad)
		pad_char = '0';
	num_str = ft_itoa(n);
	formatted_perc = ft_format_persicion(num_str, tab->perc_len, tab);
	tab->total_len = ft_max(tab->width, ft_strlen(formatted_perc));
	ret = ft_format_padding(
			formatted_perc,
			pad_char,
			tab->total_len,
			tab->f_dash);
	free(num_str);
	free(formatted_perc);
	return (ret);
}
