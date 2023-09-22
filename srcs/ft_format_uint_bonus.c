/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_uint_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:58:27 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/21 18:03:48 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_format_uint(unsigned int n, t_print_tab *tab)
{
	char	*ret;
	char	pad_char;
	char	*num_str;
	char	*formatted_perc;

	pad_char = ' ';
	if (tab->f_zero_pad && !tab->f_perc_fmt)
		pad_char = '0';
	num_str = ft_utoa(n);
	formatted_perc = ft_format_persicion(num_str, tab);
	tab->total_len = ft_max(2, tab->width, ft_strlen(formatted_perc));
	ret = ft_format_padding(formatted_perc, pad_char, tab, FALSE);
	free(num_str);
	free(formatted_perc);
	return (ret);
}
