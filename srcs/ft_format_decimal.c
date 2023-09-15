/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:07:15 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/15 18:35:36 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_decimal(int n, t_print_tab *tab)
{
	char	*ret;
	char	pad_char;
	char	*formatted_perc;

	pad_char = ' ';
	if (tab->f_zero_pad)
		pad_char = '0';
	formatted_perc = ft_format_persicion(ft_itoa(n), tab->perc_len, tab);
	tab->total_len = ft_max(tab->width, ft_strlen(formatted_perc));
	ret = ft_format_padding(
			formatted_perc,
			pad_char,
			tab->total_len,
			tab->f_dash);
	free(formatted_perc);
	return (ret);
}
