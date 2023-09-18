/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:01:22 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/18 11:20:48 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_string(char *s, t_print_tab *tab)
{
	char		*ret;
	const char	pad_char = ' ';
	char		*tmp;

	if (!s)
		s = "(null)";
	if (tab->f_perc_fmt)
		tab->total_len = ft_min(ft_strlen(s), tab->perc_len);
	else if (tab->width)
		tab->total_len = ft_max(ft_strlen(s), tab->width);
	else
		tab->total_len = ft_strlen(s);
	tmp = ft_substr(s, 0, tab->total_len);
	ret = ft_format_padding(tmp, pad_char, tab->total_len, tab->f_dash);
	free(tmp);
	return (ret);
}
