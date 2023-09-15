/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:01:22 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/15 18:42:27 by lyeh             ###   ########.fr       */
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
	tab->total_len = tab->width;
	if (!tab->width)
		tab->total_len = ft_min(ft_strlen(s), tab->perc_len);
	tmp = ft_substr(s, 0, tab->perc_len);
	ret = ft_format_padding(tmp, pad_char, tab->total_len, tab->f_dash);
	free(tmp);
	return (ret);
}
